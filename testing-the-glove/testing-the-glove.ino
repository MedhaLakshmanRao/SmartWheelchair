
void setup() {
  Serial.begin(9600);
  //pinMode(10,INPUT);
  //pinMode(3,INPUT);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
}

void loop() {
  //float y = digitalRead(10);
  //float z = digitalRead(3);
  float x = analogRead(A0);
  float y = analogRead(A1);
  float z = analogRead(A2);
  Serial.print(x);
  Serial.print("   ");
  Serial.print(y);
  Serial.print("   ");
  Serial.println(z);
  delay(100);
   }

 
