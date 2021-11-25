//Sensor setup
#define echoPin1 9
#define trigPin1 10
#define echoPin2 7
#define trigPin2 8
#define echoPin3 5
#define trigPin3 6

//Variables declaration
int motor = 12;
int pieso = 13;
int greenled = 4;
int yellowled = 3;
int redled = 2;
int duration = 0;
int back_distance = 0;
int right_distance = 0;
int left_distance = 0;

void setup() // Startup configs for Arduino
{
  pinMode(pieso, OUTPUT);
  pinMode(motor, OUTPUT);
  pinMode(greenled, OUTPUT);
  pinMode(yellowled, OUTPUT);
  pinMode(redled, OUTPUT);

  //More leds
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);

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

void distance_check_back()
{
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration = pulseIn(echoPin1, HIGH);
  back_distance = duration * 0.017;
  duration = 0;
  return back_distance;
}

void distance_check_right()
{
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration = pulseIn(echoPin2, HIGH);
  right_distance = duration * 0.017;
  duration = 0;
  return right_distance;
}

void distance_check_left()
{
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  duration = pulseIn(echoPin3, HIGH);
  left_distance = duration * 0.017;
  duration = 0;
  return left_distance;
}

void loop() // Main code
{
  void distance_check_back();
  void distance_check_right();
  void distance_check_left();

  // Controle de movimento
  if (distancia1 > 5)
  {
    digitalWrite(motor, HIGH);
  }
  else if (distancia1 < 5)
  {
    digitalWrite(motor, LOW);
  }

  if (distancia1 < 50)
  {
    digitalWrite(2, HIGH);
    tone(13, 1000, 50);
    delay(400);
    digitalWrite(2, LOW);
  }
  else
  {
    digitalWrite(2, LOW);
    digitalWrite(13, LOW);
  }
  if (distancia1 >= 50 and distancia1 < 200)
  {
    digitalWrite(3, HIGH);
    delay(500);
    digitalWrite(3, LOW);
  }
  else
  {
    digitalWrite(3, LOW);
  }
  if (distancia1 >= 200 and distancia1 < 330)
  {
    digitalWrite(4, HIGH);
  }
  else
  {
    digitalWrite(4, LOW);
  }
  delay(100);
}