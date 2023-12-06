#include<Servo.h>
#define ir_1 7
#define ir_2 4


Servo myservo;
void setup()
{
  Serial.begin(9600);
  pinMode(ir_1,INPUT);  
  pinMode(ir_2,INPUT);
  myservo.attach(6);
  myservo.write(0);
}

void loop()
{ static int count=5; 

 if(digitalRead(ir_1)==0&&count>0){
    myservo.write(90);
    Serial.println("1_1");
    int p=count;
   while(p==count){if(digitalRead(ir_2)==0){
       myservo.write(0);
    Serial.println("1_2");
     delay(1000);
     count--;
     Serial.println(count); ;    }
    }
 }
 else if(digitalRead(ir_2)==0&&count!=5){
    myservo.write(90);
    Serial.println("2_1");
    int q=count;
   while(q==count){if(digitalRead(ir_1)==0){
  myservo.write(0);
  Serial.println("2_2");
     delay(1000);
     count++;
     Serial.println(count);
   }
    }
   
  }
  
}
