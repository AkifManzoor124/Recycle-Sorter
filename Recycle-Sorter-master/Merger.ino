#include <Servo.h>
#include <LiquidCrystal.h>

Servo servo1, servo2, servo3; // Define servos
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

String items[3] = {"Plastic:"," Tims:", " Cans:"};
int counter[3] = {0,0,0};

 
int cat = 90; //default angle when turned on
int move_pull = 0;
int move_fwd = 0;
int move_push = 190;
int move_bwd = 190;

const int button1=5;
const int button2=6;
const int button3=7;

void setup()
{
  lcd.begin(16,2);
  
  servo1.attach(3); 
  servo2.attach(2);
  servo3.attach(4);
  servo1.write(cat - 9); // C
  servo2.write(cat - 4); // B
  servo3.write(cat - 7); //A
  Serial.begin(9600);
  displayer();
  pinMode(button1,INPUT);
  pinMode(button2,INPUT);
  pinMode(button3,INPUT);
}
void loop() {
  
  if (digitalRead(button1)==HIGH){//plastic - B
   servo2.write(move_push - 50);  //pushed
   delay(100);      
   servo1.write(move_pull + 10);  //pulled back
   increment(0);/*
   Serial.print(counter[0]);
   Serial.print(",");
   Serial.print(counter[1]);
   Serial.print(",");
   Serial.println(counter[2]);*/
   lcd.clear();
   displayer();
   delay(2000);
   
   servo1.write(cat - 9);
   delay(100);
  servo2.write(cat - 4);  
  }


  else if (digitalRead(button2)==HIGH){//aluminium - A
   servo3.write(move_push - 55);  //pull in this case is this variable
   delay(100);   
   servo2.write(move_pull + 20);  //push in this case is this variable
   increment(1);/*
   Serial.print(counter[0]);
   Serial.print(",");
   Serial.print(counter[1]);
   Serial.print(",");
   Serial.println(counter[2]);*/
   lcd.clear();
   displayer();
   delay(2000);
   servo2.write(cat - 4);  
   delay(100);
   servo3.write(cat - 7); 
 
  }
  else if (digitalRead(button3)==HIGH){//paper - C
   servo1.write(move_push - 70);  
   delay(100);   
   servo3.write(move_pull + 10);
   increment(2);/*
   Serial.print(counter[0]);
   Serial.print(",");
   Serial.print(counter[1]);
   Serial.print(",");
    Serial.println(counter[2]);*/

   lcd.clear();
   displayer();
   delay(2000);
   servo3.write(cat - 7);  
   delay(100);
   servo1.write(cat - 9);  

  }
  Serial.print(counter[0]);
   Serial.print(",");
   Serial.print(counter[1]);
   Serial.print(",");
    Serial.println(counter[2]);
    delay(500);

  
}
void increment(int item){
    counter[item]++;
  }

void displayer(){
  lcd.print(items[0] + String(counter[0]));
  lcd.print(items[1] + String(counter[1]));
  lcd.setCursor(0,2);
  lcd.print(items[2] + String(counter[2]));
  lcd.setCursor(9,2);
  lcd.print("ARISE");
}


void sweep(){
  for (int positionCounter = 0; positionCounter < 25; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:    
  }

}

