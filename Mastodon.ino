//For use with BlueControl app - https://play.google.com/store/apps/details?id=com.gundel.bluecontrol&hl=en
#include <SoftwareSerial.h>
SoftwareSerial mySerial(4, 5);
int motor_left[] = {2, 3};
int motor_right[] = {8, 9};

int incomingByte = 0;
int oldByte = 0;



void setup()  
{
  pinMode(13, OUTPUT); //If you want to have a cool looking blue LED, like we did in the video.
  
  int i;
  for(i = 0; i < 2; i++){
    pinMode(motor_left[i], OUTPUT);
    pinMode(motor_right[i], OUTPUT);
  }
  mySerial.begin(9600);
  //Serial.begin(9600); 
  //We had a bit of single strand wire preventing us from putting 
  //anything into Digital Pins 1 and 0, so we used Pins 4 and 5 with
  //SoftwareSerial.h instead.
  //If you don't have a problem with using the normal Rx and Tx pins, 
  //just use Serial.begin
}

void loop()
{  digitalWrite(13, HIGH);
   if (mySerial.available() > 0)
     {
// read the incoming byte:
     incomingByte = mySerial.read();    
// delay 25 milliseconds to allow serial update time
     delay(25);
     
     
  Serial.println(incomingByte);
  if (incomingByte == 82)
  {
    
        turn_right();


    delay(100);
    oldByte = incomingByte;
  
}

 else if(incomingByte == 76)
  {
    turn_left();
    delay(100);
    oldByte = incomingByte;
  }
  
   else if(incomingByte == 68)
  {
    drive_forward();
    
    delay(100);
    oldByte = incomingByte;
    //motor_stop();  
}
  
   else if(incomingByte == 85)
  {
    drive_backward();
    
    delay(100);
    oldByte = incomingByte;
   // motor_stop();
  }
   else if(incomingByte == 10)
  {
    incomingByte = oldByte;
    
    
   // motor_stop();
  }
  else 
  {
    
    motor_stop();
    delay(100);
  }
     }

  
     
}

void drive_forward(){
digitalWrite(motor_left[0], HIGH); 
digitalWrite(motor_left[1], LOW); 

digitalWrite(motor_right[0], HIGH); 
digitalWrite(motor_right[1], LOW); 
}

void motor_stop(){
digitalWrite(motor_left[0], LOW); 
digitalWrite(motor_left[1], LOW); 

digitalWrite(motor_right[0], LOW); 
digitalWrite(motor_right[1], LOW);
delay(25);
}

void drive_backward(){
digitalWrite(motor_left[0], LOW); 
digitalWrite(motor_left[1], HIGH); 

digitalWrite(motor_right[0], LOW); 
digitalWrite(motor_right[1], HIGH); 
}

void turn_left(){
digitalWrite(motor_left[0], LOW); 
digitalWrite(motor_left[1], HIGH); 

digitalWrite(motor_right[0], HIGH); 
digitalWrite(motor_right[1], LOW);
}

void turn_right(){
digitalWrite(motor_left[0], HIGH); 
digitalWrite(motor_left[1], LOW); 

digitalWrite(motor_right[0], LOW); 
digitalWrite(motor_right[1], HIGH); 
}



