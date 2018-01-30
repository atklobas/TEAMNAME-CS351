#include <LiquidCrystal.h>
enum pins{
  p1Inc=0,
  p1Dec=2,
  p2Inc=1,
  p2Dec=3,  
};
int lastPress=0;
int p1;
int p1Won;
int p2;
int p2Won;
int bounce=100;
boolean won = false;
int wonAt=0;

LiquidCrystal lcd(5,4,10,11,12,13);

void setup() {
  //set lcd size, 16 chars, 2 rows
  lcd.begin(16, 2);
  //clear any data on lcd

redraw();

pinMode(0, INPUT);
pinMode(1, INPUT);
pinMode(2, INPUT);
pinMode(3, INPUT);
 attachInterrupt(digitalPinToInterrupt(0), p1Incriment, RISING);
 attachInterrupt(digitalPinToInterrupt(1), p2Incriment, RISING);
 attachInterrupt(digitalPinToInterrupt(2), p1Decriment, RISING);
 attachInterrupt(digitalPinToInterrupt(3), p2Decriment, RISING);
 check();
}

void loop() {
  if(digitalRead(0) || digitalRead(1) || digitalRead(2) || digitalRead(3)){
    lastPress=millis();
  }
  delay(20);
}

void redraw(){
  lcd.clear();
  lcd.print(p1Won);
  lcd.print(" - sets won - ");
  lcd.print(p2Won);
    lcd.setCursor(0,1);
    lcd.print("");
    lcd.print(p1);
    lcd.print("            ");
    lcd.setCursor((p2/10)>0?14:15,1);
    lcd.print(p2);
    lcd.print("    ");
}

void clearLED(){
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
}

void flashWinnerLED(int winner) {
  clearLED();
  for (int i = 0; i < 10; i++) {
    digitalWrite(winner, HIGH);
    delay(100);
    digitalWrite(winner, LOW);
    delay(100);
  }
}

void wins(int winner){
  lcd.setCursor(0,1);
  if(winner == 0){
    lcd.print("<-- wins set    ");
    p1Won++;
    lcd.print(p1Won+p2Won);
  }else{
    lcd.print("    wins set -->");
    p2Won++;
    lcd.print(p2Won+p1Won);
  }
  lcd.setCursor(0,0);
  lcd.print(p1Won);
  lcd.print(" - sets won - ");
  lcd.print(p2Won);

  if((p2Won>2 || p1Won>2) && p2Won!=p1Won){
    delay(2500);
    lcd.setCursor(0,1);
    if(p1>p2){
      lcd.print("<-- wins game!  ");
    }else{
      lcd.print("  wins game! -->");
    }
    flashWinnerLED(7 + winner);
    p1Won=0;
    p2Won=0;
  }
  delay(3000);
  lcd.clear();
  int temp = p1Won;
  p1Won = p2Won;
  p2Won = temp;
  p1=0;
  p2=0;
  check();
}

void check(){
  clearLED();
  if(p1<10 && p2<10){
    digitalWrite(7+(p1+p2)/2%2, HIGH);
    redraw();
  }else if((p1-p2)>1){
    wins(0);
  }else if((p1-p2)<-1){
    wins(1);
  }else{
    redraw();
    digitalWrite((7+(p1+p2)%2), HIGH);
  }
}

void p1Incriment(){
  if(millis()-lastPress>bounce){
    lastPress=millis();
    p1++;
  }
  check();
}
void p2Incriment(){
  if(millis()-lastPress>bounce){
    lastPress=millis();
    p2++;
  }
  check();
}
void p1Decriment(){
  if(millis()-lastPress>bounce){
    lastPress=millis();
    if(p1>0){
         p1--; 
    }
  }
  check();
}
void p2Decriment(){
  if(millis()-lastPress>bounce){
    lastPress=millis();
    if(p2>0){
         p2--; 
    }
  }
  check();
}


