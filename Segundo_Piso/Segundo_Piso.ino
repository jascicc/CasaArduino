int btn1=2,btn2=3,btn3=4,btn4=5,btn5=6;
int led1=7,led2=8,led3=9,led4=10,led5=11;

bool led1On=false, led2On=false, led3On=false, led4On=false, led5On=false;

void setup() {
  for(int i=2;i<=11;i++){
    if(i<7){
      pinMode(i,INPUT);
    }
    else{
      pinMode(i,OUTPUT);
    }    
  }
}

void loop() {
  if(digitalRead(btn1)==HIGH&&!led1On){
    digitalWrite(led1,HIGH);
    led1On=true;
  }
  else if(digitalRead(btn1)==HIGH&&led1On){
    digitalWrite(led1,LOW);
    led1On=false;
  }
  
  if(digitalRead(btn2)==HIGH&&!led2On){
    digitalWrite(led2,HIGH);
    led2On=true;
  }
  else if(digitalRead(btn2)==HIGH&&led2On){
    digitalWrite(led2,LOW);
    led2On=false;
  }

  if(digitalRead(btn3)==HIGH&&!led3On){
    digitalWrite(led3,HIGH);
    led3On=true;
  }
  else if(digitalRead(btn3)==HIGH&&led3On){
    digitalWrite(led3,LOW);
    led3On=false;
  }

  if(digitalRead(btn4)==HIGH&&!led4On){
    digitalWrite(led4,HIGH);
    led4On=true;
  }
  else if(digitalRead(btn4)==HIGH&&led4On){
    digitalWrite(led4,LOW);
    led4On=false;
  }

  if(digitalRead(btn5)==HIGH&&!led5On){
    digitalWrite(led5,HIGH);
    led5On=true;
  }
  else if(digitalRead(btn5)==HIGH&&led5On){
    digitalWrite(led5,LOW);
    led5On=false;
  }
}
