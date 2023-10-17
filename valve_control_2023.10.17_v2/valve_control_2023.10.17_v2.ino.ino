#include <Stepper.h>

String cmd_new;     // Command String
String cmd_cur;

const int stepsPerRevolution = 512; 
// 2048 → 한 바퀴(360도), 1024 → 반 바퀴(180도) …
Stepper myStepper(stepsPerRevolution, 5,3,4,2);   
// 모터 드라이브에 연결된 핀 IN4, IN2, IN3, IN1

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  myStepper.setSpeed(60);

}


void loop() 
{
  if(Serial.available())
  {
    String inString = Serial.readStringUntil('\n');
    //Serial.println(inString);
        
    if(inString.equals("o")){
      myStepper.step(-stepsPerRevolution);  // 시계 방향으로 한바퀴 회전
      delay(500);
      Serial.println("Open");
    } else if(inString.equals("c")){
      myStepper.step(stepsPerRevolution);  // 시계 방향으로 한바퀴 회전
      delay(500);
      Serial.println("close");
    } else {
      Serial.println("nocmd");
    }

  } 



  // put your main code here, to run repeatedly:
  //Serial.print("a");
  //myStepper.step(stepsPerRevolution/2);   // 시계 반대 방향으로 한 바퀴 회전
  //delay(500);
  //Serial.print("b");
  //myStepper.step(-stepsPerRevolution/2);  // 시계 방향으로 한바퀴 회전
  //delay(500);


}


