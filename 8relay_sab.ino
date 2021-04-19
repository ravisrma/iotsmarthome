#include<SoftwareSerial.h>
SoftwareSerial mySerial(10,11);
int rainsense= A0; // analog sensor input pin 0
int buzzerout= 22; // digital output pin 10 - buzzer output
int countval= 0; // counter value starting from 0 and goes up by 1 every second
int ledout= 24; 
int redLed = 26;//gas red led
int greenLed = 28;//gas red led
int buzzer = 30;//gas buzzer
int smokeA0 = A2; //gas sensor
// Your threshold value
int sensorThres = 400;
const int buzzerPin = 32;//flame buzzer
const int flamePin =12;//flame
int Flame = HIGH;
int redled =34 ;//flame red
int greenled = 36;//flame green
int rainPin = A4;//soil sensor
int greenLED = 38;//soil led
int redLED = 40;//soil led
int thresholdValue = 800;
String inputs;
#define relay1 2 //Connect relay1 to pin 9
#define relay2 3 //Connect relay2 to pin 8
#define relay3 4 //Connect relay3 to pin 7
#define relay4 5 //Connect relay4 to pin 6
#define relay5 6 //Connect relay5 to pin 5
#define relay6 7 //Connect relay6 to pin 4
#define relay7 8 //Connect relay7 to pin 3
#define relay8 9 //Connect relay8 to pin 2
void setup()
{
mySerial.begin(9600);
Serial.begin(9600); //Set rate for communicating with phone
pinMode(buzzerout, OUTPUT);
pinMode(ledout, OUTPUT); 
pinMode(rainsense, INPUT);
pinMode(redLed, OUTPUT);//gas
pinMode(greenLed, OUTPUT);//gas
pinMode(buzzer, OUTPUT);//gas
pinMode(smokeA0, INPUT);//gas
pinMode(buzzerPin, OUTPUT);//flame
pinMode(redled, OUTPUT);//flame
pinMode(greenled, OUTPUT);//flame
pinMode(flamePin, INPUT);//flame
pinMode(rainPin, INPUT);//soil 
pinMode(greenLED, OUTPUT);//soil
pinMode(redLED, OUTPUT);//soil
digitalWrite(greenLED, LOW);//soil
digitalWrite(redLED, LOW);//soil
pinMode(relay1, OUTPUT); //Set relay1 as an output
pinMode(relay2, OUTPUT); //Set relay2 as an output
pinMode(relay3, OUTPUT); //Set relay1 as an output
pinMode(relay4, OUTPUT); //Set relay2 as an output
pinMode(relay5, OUTPUT); //Set relay1 as an output
pinMode(relay6, OUTPUT); //Set relay2 as an output
pinMode(relay7, OUTPUT); //Set relay1 as an output
pinMode(relay8, OUTPUT); //Set relay2 as an output
digitalWrite(relay1, HIGH); //Switch relay1 off
digitalWrite(relay2, HIGH); //Swtich relay2 off
digitalWrite(relay3, HIGH); //Switch relay1 off
digitalWrite(relay4, HIGH); //Swtich relay2 off
digitalWrite(relay5, HIGH); //Switch relay1 off
digitalWrite(relay6, HIGH); //Swtich relay2 off
digitalWrite(relay7, HIGH); //Switch relay1 off
digitalWrite(relay8, HIGH); //Swtich relay2 off
}
void loop()
{
 int rainSenseReading = analogRead(rainsense);
   Serial.println(rainSenseReading); // serial monitoring message 
   delay(250);// rain sensing value from 0 to 1023.
   // from heavy rain - no rain.
   if (countval >= 35){ 
      Serial.print("Heavy rain");
      digitalWrite(buzzerout, HIGH);  //raise an alert after x time
      digitalWrite(ledout, HIGH);  // led glow
   }
   //raining for long duration rise buzzer sound
   // there is no rain then reset the counter value
   if (rainSenseReading <500){ 
      countval++; // increment count value
   }
   else if (rainSenseReading >500) { // if not raining
      digitalWrite(buzzerout, LOW); // turn off buzzer 
      digitalWrite(ledout, LOW); // turn off led
      countval = 0; // reset count to 0
   }
   delay(1000);
int analogSensor = analogRead(smokeA0);

  Serial.print("Pin A2: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {
    Serial.println("Gas detected!");
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    tone(buzzer, 1000, 200);
  }
  else
  {
    Serial.println("No gas detected!");
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    noTone(buzzer);
  }
  delay(100);
int sensorValue = analogRead(rainPin);
  Serial.print(sensorValue);
  if(sensorValue < thresholdValue){
    Serial.println(" - Doesn't need watering");
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
  }
  else {
    Serial.println(" - Time to water your plant");
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
  }
  delay(500);
  Flame = digitalRead(flamePin);
  Serial.println(Flame);
  if (Flame==HIGH)
  {
    Serial.println("Fire!!!");
    digitalWrite(buzzerPin,HIGH);
    digitalWrite(redled, HIGH);
    digitalWrite(greenled, LOW);}
  else
  {
    Serial.println("NO worries");
    digitalWrite(buzzerPin,LOW);
    digitalWrite(greenled, HIGH);
    digitalWrite(redled, LOW);
  }
  delay(100);
while(mySerial.available()) //Check if there are available bytes to read
{
delay(10); //Delay to make it stable
char c = mySerial.read(); //Conduct a serial read
if (c == '#'){
break; //Stop the loop once # is detected after a word
}
inputs += c; //Means inputs = inputs + c
}
if (inputs.length() >0)
{
Serial.println(inputs);

if(inputs == "A")
{
digitalWrite(relay1, LOW);
}
else if(inputs == "a")
{
digitalWrite(relay1, HIGH);
}
else if(inputs == "B")
{
digitalWrite(relay2, LOW);
}
else if(inputs == "b")
{
digitalWrite(relay2, HIGH);
}
else if(inputs == "C")
{
digitalWrite(relay3, LOW);
}
else if(inputs == "c")
{
digitalWrite(relay3, HIGH);
}
else if(inputs == "D")
{
digitalWrite(relay4, LOW);
}
else if(inputs == "d")
{
digitalWrite(relay4, HIGH);
}
else if(inputs == "E")
{
digitalWrite(relay5, LOW);
}
else if(inputs == "e")
{
digitalWrite(relay5, HIGH);
}
else if(inputs == "F")
{
digitalWrite(relay6, LOW);
}
else if(inputs == "f")
{
digitalWrite(relay6, HIGH);
}
else if(inputs == "G")
{
digitalWrite(relay7, LOW);
}
else if(inputs == "g")
{
digitalWrite(relay7, HIGH);
}
else if(inputs == "H")
{
digitalWrite(relay8, LOW);
}
else if(inputs == "h")
{
digitalWrite(relay8, HIGH);
}
inputs="";
}
}
