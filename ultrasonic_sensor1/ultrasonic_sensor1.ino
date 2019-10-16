int trig=3;
int echo=4;
//int vcc=2;
//int gnd=5;
void setup() {
 //pinMode(vcc,OUTPUT);
 //digitalWrite(vcc,HIGH);
 //pinMode(gnd,OUTPUT);
 //digitalWrite(gnd,LOW);
 Serial.begin(9600);
 pinMode(trig,OUTPUT);
 pinMode(echo,INPUT);
 pinMode(14,OUTPUT);
  

}

void loop() {
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(100);
  
  long x=pulseIn(echo,HIGH);
  long y=x/58;
  Serial.print(y);
  Serial.println("cm");

 /* if(y<50)
  {digitalWrite(14,HIGH);
  delay(100);
  digitalWrite(14,LOW);
  delay(y);}
  /* if(y<30&&y>20)
  {digitalWrite(14,HIGH);
  delay(50);
  digitalWrite(14,LOW);
  delay(100);}
   if(y<20&&y>10)
   {digitalWrite(14,HIGH);
  delay(50);
  digitalWrite(14,LOW);
  delay(20);}
  if(y<10)
  {digitalWrite(14,HIGH);
  delay(50);
  digitalWrite(14,LOW);
  delay(10);}*/
  
  

  
 //else
 //{digitalWrite(14,LOW);}

 
}
