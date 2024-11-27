int ctr1 = 0;
int ctr2 = 0;
int int1 = 100000;
int int2 = 2000000;
unsigned long time_1 = 0;
unsigned long time_2 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(micros() >= time_1 + int1){
    time_1 += int1;
    ctr1++;
    Serial.println("C1: " + String(ctr1) + " C2: " + String(ctr2));
  }

  if(micros() >= time_2 + int2){
    time_2 += int2;
    ctr2++;
    ctr1 -= ctr2;
    Serial.println("C1: " + String(ctr1) + " C2: " + String(ctr2));
  }
}
