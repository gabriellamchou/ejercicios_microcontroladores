const unsigned long DEFAULT_INTERVAL = 1000;
const unsigned long FAST_INTERVAL = 100;

bool publish = false;
unsigned long lastPublishTime = 0;
unsigned long publishInterval = DEFAULT_INTERVAL;
int currentValue = 1;
bool alternateMode = false;

void setup() {
  Serial.begin(9600);
  delay(1000);
  showHelp();
}

void loop() {
  if (Serial.available() > 0) {
    String receivedStr = Serial.readStringUntil('\n');
    receivedStr.trim();
    receivedStr.toLowerCase();
    handleCommand(receivedStr);
  }

  if (publish && millis() - lastPublishTime >= publishInterval) {
    lastPublishTime = millis();
    publishValue();
  }
}

void handleCommand(String receivedStr) {
  if (receivedStr == "h") {
    showHelp();
  } else if (receivedStr == "start") {
    publish = true;
    Serial.println(F("Start"));
  } else if (receivedStr == "stop") {
    publish = false;
    Serial.println(F("Stop"));
  } else if (receivedStr == "t") {
    publishInterval = (publishInterval == DEFAULT_INTERVAL) ? FAST_INTERVAL : DEFAULT_INTERVAL;
  } else if (receivedStr == "m") {
    alternateMode = !alternateMode;
  } else {
    Serial.println(F("Comando no reconocido. Escriba 'h' para ayuda."));
  }
}

void publishValue() {
  if (alternateMode) {
    currentValue = !currentValue;
  }
  Serial.println(currentValue);
}

void showHelp() {
  Serial.println(F("Lista de comandos:"));
  Serial.println(F("H o h (help): muestra este menu de ayuda."));
  Serial.println(F("START o start: publica cada segundo un valor por el puerto serie."));
  Serial.println(F("STOP o stop: detiene la publicación del valor."));
  Serial.println(F("T o t (time): cambia el periodo de publicación (1-10 veces por segundo)."));
  Serial.println(F("M o m (mode): cambia el modo entre fijo y alternativo."));
  Serial.println(F("---"));
}
