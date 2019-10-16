int trig=3;
int echo=4;

int RM1=8;
int RM2=7;
int LM1=6;
int LM2=5;

void setup() {
  Serial.begin(9600);

 pinMode(trig,OUTPUT);
 pinMode(echo,INPUT);
 
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(2,OUTPUT);
 
 pinMode(RM1,OUTPUT);
 pinMode(RM2,OUTPUT);
 pinMode(LM1,OUTPUT);
 pinMode(LM2,OUTPUT);
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

 
  if(y>13){                                           //stopp
  digitalWrite(RM1,LOW);
  digitalWrite(RM2,LOW);
  digitalWrite(LM1,LOW);
  digitalWrite(LM2,LOW);
  }

  else{                                               //run
 
 
  float a = analogRead(A0);
  float b = analogRead(A1);
  float c = analogRead(A2);
  float d = analogRead(A3);
 
 Serial.print(b);
 Serial.print("     ");
  Serial.print(c);
  Serial.print("   ");
  Serial.print(d);
 

 
  if(a>900&&b<50&&c<50)//right turn
 {digitalWrite(RM1,HIGH);
  digitalWrite(RM2,LOW);
   digitalWrite(LM1,LOW);
   digitalWrite(LM2,HIGH);}

   else if(a<50&&c>900&&b<50)//left turn
   {digitalWrite(RM1,LOW);
  digitalWrite(RM2,HIGH);
   digitalWrite(LM1,HIGH);
   digitalWrite(LM2,LOW);}
 
   else if(a<50&&b>900&&c<50)//forward
   {digitalWrite(RM1,HIGH);
  digitalWrite(RM2,LOW);
   digitalWrite(LM1,HIGH);
   digitalWrite(LM2,LOW);}
   
   else if(a>900&&c<50&&b>900)//reverse
    {digitalWrite(RM1,LOW);
  digitalWrite(RM2,HIGH);
   digitalWrite(LM1,LOW);
   digitalWrite(LM2,HIGH);
   }
   
   else if(b>900&&a<50&&c>900)//reverse
   {digitalWrite(RM1,LOW);
  digitalWrite(RM2,HIGH);
   digitalWrite(LM1,LOW);
   digitalWrite(LM2,HIGH);}

   else
    {digitalWrite(RM1,LOW);
  digitalWrite(RM2,LOW);
   digitalWrite(LM1,LOW);
   digitalWrite(LM2,LOW);}
   if(d>900)
   {digitalWrite(2,HIGH);}
   else
   { digitalWrite(2,LOW);}
   
  delay(100);
    }

 }
