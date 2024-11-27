int contador = 0;
int interval = 1000;
unsigned long time_now = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(millis() >= time_now + interval){
    time_now += interval;
    Serial.println("Contador: " + String(contador));
    contador++;
  }
}
