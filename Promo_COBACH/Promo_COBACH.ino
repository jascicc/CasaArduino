int led1=7, led2=8, led3=9, led4=10, led5=11;
int inst=0;
bool led1On=false, led2On=false, led3On=false, led4On=false, led5On=false;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int l=7;l<=11;l++)
  {
    pinMode(l,OUTPUT);
  }
}

void dashBoardInstruction(){
  int l=0;
  switch(inst){
    case 0:
      for(l=7; l<=11; l++){
        digitalWrite(l, LOW);
        delay(50);
        led1On=false;
        led2On=false;
        led3On=false;
        led4On=false;
        led5On=false;
      }
    break;

    case 1:
      for(l=7; l<=11; l++){
        digitalWrite(l, HIGH);
        delay(50);
        led1On=true;
        led2On=true;
        led3On=true;
        led4On=true;
        led5On=true;
      }
    break;

    case 2:
      if(!led1On){
        digitalWrite(led1,HIGH);
        led1On=true;
      }
      else{
        digitalWrite(led1,LOW);
        led1On=false;
      }
    break;

    case 3:
      if(!led2On){
        digitalWrite(led2,HIGH);
        led2On=true;
      }
      else{
        digitalWrite(led2,LOW);
        led2On=false;
      }
    break;

    case 4:
      if(!led3On){
        digitalWrite(led3,HIGH);
        led3On=true;
      }
      else{
        digitalWrite(led3,LOW);
        led3On=false;
      }
    break;

    case 5:
      if(!led4On){
        digitalWrite(led4,HIGH);
        led4On=true;
      }
      else{
        digitalWrite(led4,LOW);
        led4On=false;
      }
    break;

    case 6:
      if(!led5On){
        digitalWrite(led5,HIGH);
        led5On=true;
      }
      else{
        digitalWrite(led5,LOW);
        led5On=false;
      }
    break;
  }
}

void loop() {
  if(Serial.available()){
    inst=Serial.read()-'0';
    delay(50);
    dashBoardInstruction();
  }
  delay(10);
}
