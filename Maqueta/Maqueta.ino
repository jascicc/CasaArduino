#define CUSTOM_SETTINGS
#define INCLUDE_VOICE_RECOGNIZER_SHIELD
#define INCLUDE_LCD_SHIELD
#define INCLUDE_TERMINAL_SHIELD

#include <OneSheeld.h>

int btn1=0, btn2=1, btn3=2, btn4=3, btn5=4, btn6=5, btn7=6;
int led1=7, led2=8, led3=9, led4=10, led5=11, led6=12, led7=13;

const char prenderEntrada[]="prender entrada";//pin 7
const char prenderSalida[]="prender salida";//pin 13
const char prenderCocina[]="prender cocina";//pin 9
const char prenderSala[]="prender sala";//pin 8
const char prenderWC[]="prender regadera";//pin 10
const char prenderEscalera[]="prender escalera";//pin 11
const char prenderComedor[]="prender comedor";//pin 12
const char prenderTodos[]="prender todos";

const char apagarEntrada[]="apagar entrada";
const char apagarSalida[]="apagar salida";
const char apagarCocina[]="apagar cocina";
const char apagarSala[]="apagar sala";
const char apagarWC[]="apagar regadera";
const char apagarEscalera[]="apagar escalera";
const char apagarComedor[]="apagar comedor";
const char apagarTodos[]="apagar todos";

void setup() {
  OneSheeld.begin();
  VoiceRecognition.setOnError(error);
  VoiceRecognition.start();
  for(int btn=0;btn<=13;btn++){
    if(btn<7){
      pinMode(btn,INPUT);
    }
    else{
      pinMode(btn,OUTPUT);
    }
  }
}

void prenderLED(int led){
  switch(led){
    case 0:
      for(int i=7;i<=13;i++){
        digitalWrite(i,LOW);
      }
    break;

    case 1:
      for(int i=7;i<=13;i++){
        digitalWrite(i,HIGH);
      }
    break;

    case 2:
      digitalWrite(led1,HIGH);
    break;

    case 3:
      digitalWrite(led2,HIGH);
    break;

    case 4:
      digitalWrite(led3, HIGH);
    break;

    case 5:
      digitalWrite(led4, HIGH);
    break;

    case 6:
      digitalWrite(led5, HIGH);
    break;

    case 7:
      digitalWrite(led6, HIGH);
    break;

    case 8:
      digitalWrite(led7, HIGH);
    break;

    case 9:
      digitalWrite(led1, LOW);
    break;

    case 10:
      digitalWrite(led2, LOW);
    break;

    case 11:
      digitalWrite(led3, LOW);
    break;

    case 12:
      digitalWrite(led4, LOW);
    break;

    case 13:
      digitalWrite(led5, LOW);
    break;

    case 14:
      digitalWrite(led6, LOW);
    break;

    case 15:
      digitalWrite(led7, LOW);
    break;
  }
}

void loop() {
  if(VoiceRecognition.isNewCommandReceived())
  {
    if(!strcmp(prenderEntrada,VoiceRecognition.getLastCommand()))
    {
      prenderLED(2);
    }    
    else if(!strcmp(prenderSala,VoiceRecognition.getLastCommand()))
    {
      prenderLED(3);
    } 
    else if(!strcmp(prenderCocina,VoiceRecognition.getLastCommand()))
    {
      prenderLED(4);
    } 
    else if(!strcmp(prenderWC,VoiceRecognition.getLastCommand()))
    {
      prenderLED(5);
    } 
    else if(!strcmp(prenderEscalera,VoiceRecognition.getLastCommand()))
    {
      prenderLED(6);
    } 
    else if(!strcmp(prenderComedor,VoiceRecognition.getLastCommand()))
    {
      prenderLED(7);
    } 
    else if(!strcmp(prenderSalida,VoiceRecognition.getLastCommand()))
    {
      prenderLED(8);
    } 
    else if(!strcmp(apagarEntrada,VoiceRecognition.getLastCommand())){
      prenderLED(9);
    }
    else if(!strcmp(apagarSala,VoiceRecognition.getLastCommand()))
    {
      prenderLED(10);
    } 
    else if(!strcmp(apagarCocina,VoiceRecognition.getLastCommand()))
    {
      prenderLED(11);
    } 
    else if(!strcmp(apagarWC,VoiceRecognition.getLastCommand()))
    {
      prenderLED(12);
    } 
    else if(!strcmp(apagarEscalera,VoiceRecognition.getLastCommand()))
    {
      prenderLED(13);
    } 
    else if(!strcmp(apagarComedor,VoiceRecognition.getLastCommand()))
    {
      prenderLED(14);
    } 
    else if(!strcmp(apagarSalida,VoiceRecognition.getLastCommand()))
    {
      prenderLED(15);
    } 
    else if(!strcmp(apagarTodos,VoiceRecognition.getLastCommand())){
      prenderLED(0);
    }
    else if(!strcmp(prenderTodos,VoiceRecognition.getLastCommand())){
      prenderLED(1);
    }
  }
}

void error(byte errorData)
{
  switch(errorData)
  {
    case NETWORK_TIMEOUT_ERROR: Terminal.println("Network timeout");break;
    case NETWORK_ERROR: Terminal.println("Network Error");break;
    case AUDIO_ERROR: Terminal.println("Audio error");break;
    case SERVER_ERROR: Terminal.println("No Server");break;
    case SPEECH_TIMEOUT_ERROR: Terminal.println("Speech timeout");break;
    case NO_MATCH_ERROR: Terminal.println("No match");break;
    case RECOGNIZER_BUSY_ERROR: Terminal.println("Busy");break;
  }
}
