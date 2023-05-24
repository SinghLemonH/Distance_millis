#define BUZZER_PIN1 4
#define BUZZER_PIN2 5

#define echoPin1 7
#define trigPin1 6
#define echoPin2 8
#define trigPin2 9

#include <EasyScheduler.h>

int cm_1;
int cm_2;
Schedular Task1;
Schedular Task2;
Schedular Task3;
Schedular Task4;

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER_PIN1, OUTPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(BUZZER_PIN2, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  Task1.start();
  Task2.start();
  Task3.start();
  Task4.start();
  digitalWrite(BUZZER_PIN1, LOW);
  digitalWrite(BUZZER_PIN2, LOW);
}

void loop() {
    Task1.check(Distance1,100); 
//    Task2.check(buzzer_L,100);
//    Task3.check(buzzer_R,100);
    Task4.check(Distance2,100);
    Distance1();
    Distance2();
}

int Ultrasonic_1() {
  long duration, distance;
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration = pulseIn(echoPin1, HIGH);
  distance = duration / 58.2;
  return distance;
}

int Ultrasonic_2() {
  long duration, distance;
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration = pulseIn(echoPin2, HIGH);
  distance = duration / 58.2;
  return distance;
}

void Distance1() {
    Serial.println("A " + String(Ultrasonic_1()));
    cm_1 = Ultrasonic_1();
  if (cm_1 < 60 && cm_1 != 0) {     //เมื่อวัตถเข้าใกลสียงเตือนดังถี่ขึ้น
    buzzer_L(); 
  }
  else {
      digitalWrite(BUZZER_PIN1, LOW);
  }
}

void Distance2() {
    cm_2 = Ultrasonic_2();
     Serial.println("B " + String(Ultrasonic_2()));
  if (cm_2 < 60 && cm_2 != 0) {     //เมื่อวัตถเข้าใกลสียงเตือนดังถี่ขึ้น
    buzzer_R();
  }
  else {
      digitalWrite(BUZZER_PIN2, LOW);
  }
}

void buzzer_L() {
    digitalWrite(BUZZER_PIN1, HIGH);  //ปิดเสียงเตือน
    //delay(cm_1 * 16);
    delay(100);
    digitalWrite(BUZZER_PIN1, LOW);   //เปิดเสียงเตือน
    //delay(cm_1 * 16);
    delay(100);
}

void buzzer_R() {
    digitalWrite(BUZZER_PIN2, HIGH);  //ปิดเสียงเตือน
    //delay(cm_2 * 16);
    delay(100);
    digitalWrite(BUZZER_PIN2, LOW);   //เปิดเสียงเตือน
    //delay(cm_2 * 16);
    delay(100);
}
