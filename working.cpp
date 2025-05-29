// C++ code
//

void setup()
{
 
  pinMode(A0,INPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int sensor_reading=analogRead(0);
  Serial.print("moisture:");
  Serial.println(sensor_reading);
  if(sensor_reading<=150){
    digitalWrite(8,HIGH);
    tone(10,10000,50);
    digitalWrite(7,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(5,LOW);
  }
  if(sensor_reading>150 && sensor_reading<=600){
    digitalWrite(8,LOW);
    //tone(10,10000,50);
    digitalWrite(7,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(5,LOW);
  }
  if(sensor_reading>600){
    digitalWrite(8,LOW);
    //tone(10,10000,50);
    digitalWrite(7,LOW);
    digitalWrite(6,LOW);
    digitalWrite(5,HIGH);
  }
  delay(1000);
}
