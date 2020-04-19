int PIN6 = 6;

void setup() {
  // put your setup code here, to run once:
  pinMode(PIN6, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(PIN6, HIGH);
  sleep(2000);
  digitalWrite(PIN6, LOW);
}