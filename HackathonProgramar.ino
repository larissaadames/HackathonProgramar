// Sensor ultrassônico
const int trigPin = 2;
const int echoPin = 3;

// Sensor LM35
const int lm35Pin = A0;

// LEDs
const int greenLedPin = 4;
const int redLedPin = 5;
const int tempGreenLedPin = 6;
const int tempRedLedPin = 7;

// Buzzers
const int alarmBuzzerPin = 8;
const int tempBuzzerPin = 9;

void setup() {
  // Inicialização dos pinos
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(lm35Pin, INPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(tempGreenLedPin, OUTPUT);
  pinMode(tempRedLedPin, OUTPUT);
  pinMode(alarmBuzzerPin, OUTPUT);
  pinMode(tempBuzzerPin, OUTPUT);

  // Inicialização da comunicação serial
  Serial.begin(9600);
}

void loop() {
  // Leitura da distância pelo sensor ultrassônico
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  float duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;

  // Leitura da temperatura pelo sensor LM35
  float tempCelsius = (analogRead(lm35Pin) * 5.0 / 1024.0 - 0.5) * 100.0;

  // Lógica para os LEDs e buzzers
  if (distance < 10) {
    digitalWrite(greenLedPin, HIGH);
    digitalWrite(redLedPin, LOW);
    digitalWrite(alarmBuzzerPin, HIGH);
    Serial.println("Perigo eminente!!");
  } else {
    digitalWrite(greenLedPin, LOW);
    digitalWrite(redLedPin, HIGH);
    digitalWrite(alarmBuzzerPin, LOW);
  }

  if (tempCelsius >= 20 && tempCelsius <= 28) {
    digitalWrite(tempGreenLedPin, HIGH);
    digitalWrite(tempRedLedPin, LOW);
    digitalWrite(tempBuzzerPin, HIGH);
  } else if (tempCelsius > 28) {
    digitalWrite(tempGreenLedPin, LOW);
    digitalWrite(tempRedLedPin, HIGH);
    digitalWrite(tempBuzzerPin, HIGH);
  } else {
    digitalWrite(tempGreenLedPin, LOW);
    digitalWrite(tempRedLedPin, LOW);
    digitalWrite(tempBuzzerPin, LOW);
  }

  // Exibição da leitura de temperatura no terminal serial
  Serial.print("Temperatura: ");
  Serial.print(tempCelsius);
  Serial.println(" °C");

  delay(500);  // Pequeno atraso para evitar leituras rápidas e instáveis
}
// Sensor ultrassônico
const int trigPin = 2;
const int echoPin = 3;

// Sensor LM35
const int lm35Pin = A0;

// LEDs
const int greenLedPin = 4;
const int redLedPin = 5;
const int tempGreenLedPin = 6;
const int tempRedLedPin = 7;

// Buzzers
const int alarmBuzzerPin = 8;
const int tempBuzzerPin = 9;

void setup() {
  // Inicialização dos pinos
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(lm35Pin, INPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(tempGreenLedPin, OUTPUT);
  pinMode(tempRedLedPin, OUTPUT);
  pinMode(alarmBuzzerPin, OUTPUT);
  pinMode(tempBuzzerPin, OUTPUT);

  // Inicialização da comunicação serial
  Serial.begin(9600);
}

void loop() {
  // Leitura da distância pelo sensor ultrassônico
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  float duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;

  // Leitura da temperatura pelo sensor LM35
  float tempCelsius = (analogRead(lm35Pin) * 5.0 / 1024.0 - 0.5) * 100.0;

  // Lógica para os LEDs e buzzers
  if (distance < 10) {
    digitalWrite(greenLedPin, HIGH);
    digitalWrite(redLedPin, LOW);
    digitalWrite(alarmBuzzerPin, HIGH);
    Serial.println("Perigo eminente!!");
  } else {
    digitalWrite(greenLedPin, LOW);
    digitalWrite(redLedPin, HIGH);
    digitalWrite(alarmBuzzerPin, LOW);
  }

  if (tempCelsius >= 20 && tempCelsius <= 28) {
    digitalWrite(tempGreenLedPin, HIGH);
    digitalWrite(tempRedLedPin, LOW);
    digitalWrite(tempBuzzerPin, HIGH);
  } else if (tempCelsius > 28) {
    digitalWrite(tempGreenLedPin, LOW);
    digitalWrite(tempRedLedPin, HIGH);
    digitalWrite(tempBuzzerPin, HIGH);
  } else {
    digitalWrite(tempGreenLedPin, LOW);
    digitalWrite(tempRedLedPin, LOW);
    digitalWrite(tempBuzzerPin, LOW);
  }

  // Exibição da leitura de temperatura no terminal serial
  Serial.print("Temperatura: ");
  Serial.print(tempCelsius);
  Serial.println(" °C");

  delay(500);  // Pequeno atraso para evitar leituras rápidas e instáveis
}
