
/* HC-SR04 Sensor
   https://www.dealextreme.com/p/hc-sr04-ultrasonic-sensor-distance-measuring-module-133696
  
   This sketch reads a HC-SR04 ultrasonic rangefinder and returns the
   distance to the closest object in range. To do this, it sends a pulse
   to the sensor to initiate a reading, then listens for a pulse 
   to return.  The length of the returning pulse is proportional to 
   the distance of the object from the sensor.
     
   The circuit:
  * VCC connection of the sensor attached to +5V
  * GND connection of the sensor attached to ground
  * TRIG connection of the sensor attached to digital pin 2
  * ECHO connection of the sensor attached to digital pin 4
   Original code for Ping))) example was created by David A. Mellis
   Adapted for HC-SR04 by Tautvidas Sipavicius
   This example code is in the public domain.
 */


const int trigPin = 2;
const int echoPin = 3;
const int trigPin2 = 4;
const int echoPin2 = 5;

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(echoPin2, INPUT);
}

void loop()
{
  // establish variables for duration of the ping, 
  // and the distance result in inches and centimeters:
  long duration=-1, inches=-1, cm=-1;
  long duration2=-1, inches2=-1, cm2=-1;

  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  delay (10);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  duration = pulseIn(echoPin, HIGH);

  delay(10);

  // convert the time into a distance
  if(duration !=-1){
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  }
  else{
    inches =-1;
    cm = -1;
   }
  
  delay (10);

  //----------------second US sensor code-----------------

  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

  delay(10);
  
  duration2 = pulseIn(echoPin2, HIGH);
  
  delay(10);
  
  if(duration2!=-1){
  inches2 = microsecondsToInches(duration2);
  cm2 = microsecondsToCentimeters(duration2);
  } else{
    inches2 =-1;
    cm2 = -1;
  }
  delay(10);

//--------------------printing--------------------------
  
  //Serial.print(inches);
  //Serial.print("in, ");
  Serial.print(cm);
  Serial.print(" cm,");
  Serial.print(cm2);
  Serial.print(" cm");
  Serial.println();
 }

long microsecondsToInches(long microseconds)
{
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
