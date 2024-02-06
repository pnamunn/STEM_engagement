const int in1 = 9;
const int in2 = 8;
const int in3 = 5;
const int in4 = 4;

const int enA = 10;
const int enB = 6;

char motor_speed = 128;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  analogWrite(enA, motor_speed);
  analogWrite(enB, motor_speed);

  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char serial_input = Serial.read();

    switch (serial_input) {
      case 'w':    // Forward
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        break;
      case 's':    // Backward
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        break;
      case 'a':    // Left
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        break;
      case 'd':    // Right
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        break;
      case 'q':    // Stop
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
        break;
      case 'z':    // Speed up
        motor_speed += 10;
        analogWrite(enA, motor_speed);
        analogWrite(enB, motor_speed);
        break;
      case 'x':    // Slow down
        motor_speed -= 10;
        analogWrite(enA, motor_speed);
        analogWrite(enB, motor_speed);
        break;
    }
  }
}

