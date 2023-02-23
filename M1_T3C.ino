int motionsensorpin = 2;  // the pin that the sensor is atteched to
int ledPin = 13;
const int buzzer = 8;
const int tiltSensor = 3;

bool MotionDetected = false;
bool titlDetected = false;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
  pinMode(motionsensorpin, INPUT);  // initialize sensor as an input
  pinMode(buzzer, OUTPUT);
  pinMode(tiltSensor, INPUT_PULLUP);
 
  attachInterrupt(digitalPinToInterrupt(motionsensorpin), handleMotionInterrupt, CHANGE);
  attachInterrupt(digitalPinToInterrupt(tiltSensor), tilt, CHANGE);

}

void loop()
{
  delay(500);
}

void handleMotionInterrupt()
{
  MotionDetected = !MotionDetected;
 
  Serial.println("Motion Detected!");
  digitalWrite(ledPin,MotionDetected);
  Serial.println("Interrupted");
}

void tilt()
{
  titlDetected = !titlDetected;
  Serial.println("Tilted!");
  digitalWrite(buzzer, titlDetected);
  Serial.println("Interrupt! BUZZER");
}

    
