#define sensor 15

volatile int counter = 0;
int balance = 0;

void setup() {
  pinMode(sensor, INPUT);
  Serial.begin(115200);
}

void loop() {
  timeCounter();

  if (counter >= 900000) {
    balance += 10;
  } else if (counter >= 700000 && counter < 900000) {
    balance += 5;
  } else if (counter >= 500000 && counter < 700000) {
    balance += 2;
  } else if (counter >= 300000 && counter < 500000) {
    balance += 1;
  }

  if (counter != 0) {
    Serial.println("Time: " + String(counter));
    Serial.println("Balance: $" + String(balance));
  }

  counter = 0;
}

void timeCounter() {
  while(digitalRead(sensor) == 0) {
    counter++;
  }
}
