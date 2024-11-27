int ctr1 = 0;
int ctr2 = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // iteramos 20 veces porque 0.1seg x 20 = 2seg
  for (int i = 0; i < 20; i++) {
    delay(100);
    ctr1++; // cada 0.1seg incrementamos ctr1
    Serial.println("C1: " + String(ctr1) + " C2: " + String(ctr2));
  }

  delay(2000);
  ctr2++; // cada 2seg incrementamos ctr2
  ctr1 -= ctr2;
  Serial.println("C1: " + String(ctr1) + " C2: " + String(ctr2));
}
