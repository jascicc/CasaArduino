int led1=7, led2=8, led3=9, led4=10, led5=11;
int btn1=2, btn2=3, btn3=4, btn4=5, btn5=6;
int inst=0;
bool led1On=false, led2On=false, led3On=false, led4On=false, led5On=false;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i=2;i<=6;i++)
  {
    pinMode(i,INPUT);
  }
  for(int l=7;l<=11;l++)
  {
    pinMode(l,OUTPUT);
  }
  Serial.println("Conected");
}

void dashBoardInstruction(){
  int l=0;
  switch(inst){
    case 0:
      for(l=7; l<=11; l++){
        digitalWrite(l, LOW);
        delay(50);
      }
    break;

    case 1:
      for(l=7; l<=11; l++){
        digitalWrite(l, HIGH);
        delay(50);
      }
    break;

    case 2:
      digitalWrite(led1,HIGH);
    break;

    case 3:
      digitalWrite(led2,HIGH);
    break;

    case 4:
      digitalWrite(led3,HIGH);
    break;

    case 5:
      digitalWrite(led4,HIGH);
    break;

    case 6:
      digitalWrite(led5,HIGH);
    break;
  }
}

void loop() {
  if(Serial.available()){
    inst=Serial.read()-'0';
    delay(50);
    dashBoardInstruction();
  }
  if(digitalRead(btn1)==HIGH){
    Serial.write(1);
    Serial.println("Sala prendida");
    digitalWrite(led1,HIGH);
  }
  delay(10);
}
