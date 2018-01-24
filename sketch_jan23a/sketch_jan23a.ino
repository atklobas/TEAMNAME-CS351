#include <LiquidCrystal.h>
enum pins{
  p1Inc=0,
  p1Dec=2,
  p2Inc=1,
  p2Dec=3,  
};
int lastPress=0;
int p1;
int p2;
int bounce=150;


//
LiquidCrystal lcd(5,4,10,11,12,13);


void setup() {
  //set lcd size, 16 chars, 2 rows
  lcd.begin(16, 2);
  //clear any data on lcd
  lcd.clear();

  lcd.print("test3");

pinMode(0, INPUT);
pinMode(1, INPUT);
pinMode(2, INPUT);
pinMode(3, INPUT);
 attachInterrupt(digitalPinToInterrupt(0), p1Incriment, RISING);
 attachInterrupt(digitalPinToInterrupt(1), p2Incriment, RISING);
 attachInterrupt(digitalPinToInterrupt(2), p1Decriment, RISING);
 attachInterrupt(digitalPinToInterrupt(3), p2Decriment, RISING);



}

void loop() {
  lcd.setCursor(0,1);
  lcd.print("p1=");
  lcd.print(p1);
  lcd.print("  p2=");
  lcd.print(p2);
  lcd.print("    ");
  // put your main code here, to run repeatedly:

}


void p1Incriment(){
  if(millis()-lastPress>bounce){
    lastPress=millis();
    p1++;
  }
}
void p2Incriment(){
  if(millis()-lastPress>bounce){
    lastPress=millis();
    p2++;
  }
}
void p1Decriment(){
  if(millis()-lastPress>bounce){
    lastPress=millis();
    if(p1>0){
         p1--; 
    }
  }
}
void p2Decriment(){
  if(millis()-lastPress>bounce){
    lastPress=millis();
    if(p2>0){
         p2--; 
    }
  }
}
