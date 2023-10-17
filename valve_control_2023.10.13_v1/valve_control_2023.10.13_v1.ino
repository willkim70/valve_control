#include <Stepper.h>


const int stepsPerRevolution = 600; 
// 2048 → 한 바퀴(360도), 1024 → 반 바퀴(180도) …
Stepper myStepper(stepsPerRevolution, 5,3,4,2);   
// 모터 드라이브에 연결된 핀 IN4, IN2, IN3, IN1
        

void valve_open()
{
  myStepper.step(-stepsPerRevolution);  // 시계 방향으로 한바퀴 회전
  delay(500);
}

void valve_close()
{
  myStepper.step(stepsPerRevolution);  // 시계 방향으로 한바퀴 회전
  delay(500);
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  myStepper.setSpeed(40);

}



void loop() 
{


  // put your main code here, to run repeatedly:
  valve_open();
  valve_close();
  delay(1000);


}


