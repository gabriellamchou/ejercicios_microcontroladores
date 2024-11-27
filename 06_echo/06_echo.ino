void setup() {
  // Con esta línea ya se configuran los pines RX y TX. Por eso no se necesita usar pinMode()
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()) {
    char receivedChar = Serial.read();

    if(isLowerCase(receivedChar)) {
      receivedChar = toupper(receivedChar);
    } else if (isUpperCase(receivedChar)) {
      receivedChar = tolower(receivedChar);
    }
    Serial.print(receivedChar);
  }
}
