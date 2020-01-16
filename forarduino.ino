

void setup() {
  // put your setup code here, to run once:
pinMode(2,INPUT);
pinMode(4,INPUT);
pinMode(5,OUTPUT);
pinMode(7,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(2))
{digitalWrite(5,HIGH);}
if(!digitalRead(2))
{digitalWrite(5,LOW);}
if(digitalRead(4))
{digitalWrite(7,HIGH);}
if(!digitalRead(4))
{digitalWrite(7,LOW);}
}
