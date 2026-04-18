int pineapplePin = A0;
int solarPin = A1;

int loadLED = 5;
int batteryLED = 6;
int gridLED = 7;

int pineapple;
int solar;
int demand = 500; // fixed demand

void setup() {
  pinMode(loadLED, OUTPUT);
  pinMode(batteryLED, OUTPUT);
  pinMode(gridLED, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  pineapple = analogRead(pineapplePin);
  solar = analogRead(solarPin);

  Serial.print("Pineapple: ");
  Serial.print(pineapple);
  Serial.print(" Solar: ");
  Serial.println(solar);

  // Neural Network-based decision (simplified)

  if (solar > demand) {
    digitalWrite(loadLED, HIGH);
    digitalWrite(batteryLED, HIGH);
    digitalWrite(gridLED, LOW);
  }

  else if (pineapple > 400) {
    digitalWrite(loadLED, HIGH);
    digitalWrite(batteryLED, LOW);
    digitalWrite(gridLED, LOW);
  }

  else {
    digitalWrite(loadLED, LOW);
    digitalWrite(batteryLED, LOW);
    digitalWrite(gridLED, HIGH);
  }

  delay(1000);
}
