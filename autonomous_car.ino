const int AIN1 = 13;           
const int AIN2 = 12;            
const int PWMA = 11;           
const int redPin = 0;             
const int greenPin = 3;           
const int bluePin = 4;            
const int PWMB = 10;           
const int BIN2 = 9;           
const int BIN1 = 8;           
const int trigPin = 6;
const int echoPin = 5;
float distance = 0;            
int backupTime = 350;           
int turnTime = 350;             
int Button1 = 7;
int Button2 = 2;
bool IsButtonOn = false;
void setup()
{
  pinMode(trigPin, OUTPUT);       
  pinMode(echoPin, INPUT);        
 pinMode(Button1, INPUT_PULLUP);
  pinMode(Button2, INPUT_PULLUP);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);
 pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);                       
  Serial.print("To infinity and beyond!");
    Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
void loop()
{
  if (digitalRead(Button1) == LOW)
  {
    IsButtonOn = true;
  }
  else if (digitalRead(Button2) == LOW)
  {
    IsButtonOn = false;
    analogWrite(redPin, 255);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
  }

  distance = getDistance();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" in"); 
 if (IsButtonOn == true) {
    if (distance < 5) {
      analogWrite(redPin, 255);
      analogWrite(greenPin, 0);
      analogWrite(bluePin, 0);
      rightMotor(0);
      leftMotor(0);
      delay(200);
      rightMotor(-255);
      leftMotor(-255);
      delay(backupTime);
      rightMotor(-255);
      leftMotor(255);
      delay(turnTime);
      delay(50);
      if (distance < 5) {
      analogWrite(redPin, 255);
      analogWrite(greenPin, 0);
      analogWrite(bluePin, 0);
      rightMotor(0);
      leftMotor(0);
      delay(200);
      rightMotor(-255);
      leftMotor(-255);
      delay(backupTime);
      rightMotor(-255);
      leftMotor(255);
      delay(2 * turnTime);
      }
      else {


      }
    }
    else {                          
      analogWrite(redPin, 0);
      analogWrite(greenPin, 255);
      analogWrite(bluePin, 0);
      rightMotor(220);
      leftMotor(220);
    }
  } else if(IsButtonOn == false){ 
    rightMotor(0);
    leftMotor(0);
  }
  delay(50);               
}


void rightMotor(int motorSpeed)
{
  if (motorSpeed > 0)
  {
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW); 
  }
  else if (motorSpeed < 0)                 
  {
    digitalWrite(AIN1, LOW);                   
    digitalWrite(AIN2, HIGH);                  
  }
  else                                     
  {
    digitalWrite(AIN1, LOW);                      
    digitalWrite(AIN2, LOW);         
  }
  analogWrite(PWMA, abs(motorSpeed));        
}
void leftMotor(int motorSpeed)             
{
  if (motorSpeed > 0)                  
  {
    digitalWrite(BIN1, HIGH);     
    digitalWrite(BIN2, LOW);  
  }
  else if (motorSpeed < 0)           
  {
    digitalWrite(BIN1, LOW);              
    digitalWrite(BIN2, HIGH);                     
  }
  else                                              
  {
    digitalWrite(BIN1, LOW);                        
    digitalWrite(BIN2, LOW);                  
  }
  analogWrite(PWMB, abs(motorSpeed));       
}
float getDistance()
{
  float echoTime;              
  float calculatedDistance; 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);


  echoTime = pulseIn(echoPin, HIGH);  


  calculatedDistance = echoTime / 148.89; 


  return calculatedDistance;   
}
