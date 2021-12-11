//Sensorsetup
#define echoPin1 10 //Back
#define trigPin1 11 //Back
#define echoPin2 8 //Right
#define trigPin2 9 //Right
#define echoPin3 6 //Left
#define trigPin3 7 //Left

//Variables declaration
int piezo = 13; //Piezo controller 
int duration = 0;
int back_distance = 0; //Back distance chack 
int right_distance = 0; //Right distance chack
int left_distance = 0; //Left distance chack
int RGB1 = 2; //Red color controller
int RGB2 = 3; //Blue color controller
int RGB3 = 4; //Green color controller

// Startup configs for Arduino
void setup()
{
  pinMode(piezo, OUTPUT);
  pinMode (RGB1, OUTPUT);
  pinMode (RGB2, OUTPUT);
  pinMode (RGB3, OUTPUT);

  //Settings for the back sensor
  pinMode(echoPin1, INPUT);
  pinMode(trigPin1, OUTPUT);

  //Settings for the right sensor
  pinMode(echoPin2, INPUT);
  pinMode(trigPin2, OUTPUT);

  //Settings for the left sensor
  pinMode(echoPin3, INPUT);
  pinMode(trigPin3, OUTPUT);

  Serial.begin(9600);
}

// Functions to check distance from sensor
void distance_check_back()
{
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration = pulseIn(echoPin1, HIGH);
  back_distance = duration * 0.017;
  Serial.print("Back: ");
  Serial.print(back_distance);
  Serial.print("cm ");
}

void distance_check_right()
{
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration = pulseIn(echoPin2, HIGH);
  right_distance = duration * 0.017;
  Serial.print("Right: ");
  Serial.print(right_distance);
  Serial.print("cm ");
}

void distance_check_left()
{
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  duration = pulseIn(echoPin3, HIGH);
  left_distance = duration * 0.017;
  Serial.print("Left: ");
  Serial.print(left_distance);
  Serial.print("cm ");
}

//Control the three possible cases (OK - GREEN, CAUTION - YELLOW and DANGER - RED)
void green_case(){
  digitalWrite (RGB1, LOW);
  digitalWrite (RGB2, LOW);
  digitalWrite (RGB3, HIGH);
}

void yellow_case(){
  digitalWrite (RGB1, 255);
  digitalWrite (RGB2, LOW);
  digitalWrite (RGB3, 50);
}

void red_case(){
  digitalWrite (RGB1, HIGH);
  digitalWrite (RGB2, LOW);
  digitalWrite (RGB3, LOW);
  tone (piezo, 1000, 5);
  delay(500);
}

//Functions to control movement possibilities
void movement_control_back(){
 if (back_distance > 60){
   green_case();
 }else if (back_distance <= 60 and back_distance > 40){
   yellow_case();
 }else{
   red_case();
  }
}

void movement_control_left(){
 if (left_distance > 60){
   green_case();
 }else if (left_distance <= 60 and left_distance > 40){
   yellow_case();
 }else{
   red_case(); 
  }
}

void movement_control_right(){
 if (right_distance > 60){
   green_case();
 }else if (right_distance <= 60 and right_distance > 40){
   yellow_case();
 }else{
   red_case();
  }
}


// Main function 
void loop()
{
  distance_check_back();
  movement_control_back();
  delay(120);
  
  distance_check_right();
  movement_control_right();
  delay(120);
  
  distance_check_left();
  movement_control_left();
  delay(120);
}
