int RM1=11;
int RM2=10;
int LM1=6;
int LM2=7;
void setup() {
  pinMode(RM1,OUTPUT);
  pinMode(RM2,OUTPUT);
  pinMode(LM1,OUTPUT);
  pinMode(LM2,OUTPUT);
  
}

void loop() {
  digitalWrite(RM1,HIGH);
   digitalWrite(RM2,LOW);
   digitalWrite(LM1,LOW);
   digitalWrite(LM2,HIGH);
   delay(1000);
   digitalWrite(RM1,LOW);
   digitalWrite(RM2,HIGH);
   digitalWrite(LM1,HIGH);
   digitalWrite(LM2,LOW);
   delay(1000);
   digitalWrite(RM1,LOW);
   digitalWrite(RM2,LOW);
   digitalWrite(LM1,LOW);
   digitalWrite(LM2,LOW);
   delay(1000);
    digitalWrite(RM1,HIGH);
   digitalWrite(RM2,LOW);
   digitalWrite(LM1,HIGH);
   digitalWrite(LM2,LOW);
   delay(3000);
   digitalWrite(RM1,HIGH);
   digitalWrite(RM2,LOW);
   digitalWrite(LM1,LOW);
   digitalWrite(LM2,HIGH);
   delay(1000);
   
   
  
}
