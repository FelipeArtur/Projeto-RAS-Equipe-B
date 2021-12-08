//Sensor setup
#define echoPin1 10
#define trigPin1 11
#define echoPin2 8
#define trigPin2 9
#define echoPin3 6
#define trigPin3 7

//Variables declaration
int motor = 12;
int piezo = 13;
int greenled_back = 4;
int yellowled_back = 3;
int redled_back = 2;
int duration = 0;
int back_distance = 0;
int right_distance = 0;
int left_distance = 0;

void setup() // Startup configs for Arduino
{
  pinMode(piezo, OUTPUT);
  pinMode(motor, OUTPUT);
  pinMode(greenled_back , OUTPUT);
  pinMode(yellowled_back , OUTPUT);
  pinMode(redled_back, OUTPUT);

  //More leds
  pinMode(A0, OUTPUT); //VERDE
  pinMode(A1, OUTPUT); //AMARELA
  pinMode(A2, OUTPUT); //VERMELHO
  pinMode(A3, OUTPUT); //VERDE
  pinMode(A4, OUTPUT); //AMARELA
  pinMode(A5, OUTPUT); //VERMELHO

  //Back sensor
  pinMode(echoPin1, INPUT);
  pinMode(trigPin1, OUTPUT);
  //Right sensor
  pinMode(echoPin2, INPUT);
  pinMode(trigPin2, OUTPUT);
  //Left sensor
  pinMode(echoPin3, INPUT);
  pinMode(trigPin3, OUTPUT);

  Serial.begin(9600);
}

int distance_check_back()
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

int distance_check_right()
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

int distance_check_left()
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

void green_case(int green){
  digitalWrite(motor, HIGH);
  digitalWrite(green, HIGH);
  delay(500);
  digitalWrite(green, LOW);
}

void yellow_case(int yellow){
  digitalWrite(yellow, HIGH);
  delay(500);
  digitalWrite(yellow, LOW);
}

void red_case(int red){
  digitalWrite(motor, LOW);
  digitalWrite(red, HIGH);
  tone(piezo, 1000, 50);
  delay(400);
  digitalWrite(red, LOW);
}

// Controle de movimento
void movement_control_back(){
 if (back_distance > 50){
   green_case(greenled_back);

  }else if (back_distance <= 50 and back_distance > 20){
    yellow_case(yellowled_back);

  }else{
    red_case(redled_back);
  }
}

void movement_control_right(){
 if (right_distance > 50){
   green_case(A3);

  }else if (right_distance <= 50 and right_distance > 20){
    yellow_case(A4);

  }else{
    red_case(A5);
  }
}

void movement_control_left(){
 if (left_distance > 50){
   green_case(A0);

  }else if (left_distance <= 50 and left_distance > 20){
    yellow_case(A1);

  }else{
    red_case(A2);
  }
}

void loop() // Main code
{
  distance_check_back();
  movement_control_back();
  delay(100);
  
  distance_check_right();
  movement_control_right();
  delay(100);

  distance_check_left();
  movement_control_left();
  delay(100);
}