int trig=3;
int echo=4;

int RM1=8;
int RM2=7;
int LM1=6;
int LM2=5;

void setup() {
 pinMode(trig,OUTPUT);
 pinMode(echo,INPUT);
  
 pinMode(RM1,OUTPUT);
 pinMode(RM2,OUTPUT);
 pinMode(LM1,OUTPUT);
 pinMode(LM2,OUTPUT);
 Serial.begin(9600);

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
   digitalWrite(RM1,HIGH); 
  digitalWrite(RM2,LOW);
   digitalWrite(LM1,HIGH);
   digitalWrite(LM2,LOW);
   }
}
