String rx;

void setup() 
{
Serial.begin(9600);
pinMode(2,OUTPUT);pinMode(3,OUTPUT);pinMode(4,OUTPUT);pinMode(5,OUTPUT);
}

void loop() 
{
if(Serial.available()>0)
{
rx=Serial.readStringUntil('\n');

if(rx=="AA")
{
digitalWrite(2,1);digitalWrite(3,0);digitalWrite(4,0);digitalWrite(5,0);delay(3000);
}
else if(rx=="BB")
{
digitalWrite(2,0);digitalWrite(3,1);digitalWrite(4,0);digitalWrite(5,0);delay(3000);
}
if(rx=="CC")
{
digitalWrite(2,0);digitalWrite(3,0);digitalWrite(4,1);digitalWrite(5,0);delay(3000);
} 
else if(rx=="DD")
{
digitalWrite(2,0);digitalWrite(3,0);digitalWrite(4,0);digitalWrite(5,1);delay(3000);
}
else
{
  if(rx=="AA")
{
digitalWrite(2,0);digitalWrite(3,0);digitalWrite(4,0);digitalWrite(5,0);
}
}

}}
 
