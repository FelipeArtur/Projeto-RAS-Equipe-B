//Sensor setup
#define echoPin1 9
#define trigPin1 10
#define echoPin2 7
#define trigPin2 8
#define echoPin3 5
#define trigPin3 6

//Distancia de que?
unsigned int distancia1 = 0;
unsigned int duracao1 = 0;
unsigned int distancia2 = 0;
unsigned int duracao2 = 0;
unsigned int distancia3 = 0;
unsigned int duracao3 = 0;

//Declaracao de variaveis
int motor = 12;
int pieso = 13;
int greenled = 4;
int yellowled = 3;
int redled = 2;

void setup() // Starting configs for Arduino
{
  pinMode(pieso, OUTPUT);
  pinMode(motor, OUTPUT);
  pinMode(greenled, OUTPUT);
  pinMode(yellowled, OUTPUT);
  pinMode(redled, OUTPUT);

  //Mais leds, pq ?
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);

  pinMode(echoPin1, INPUT);
  pinMode(trigPin1, OUTPUT);

  pinMode(echoPin2, INPUT);
  pinMode(trigPin2, OUTPUT);

  pinMode(echoPin3, INPUT);
  pinMode(trigPin3, OUTPUT);
  Serial.begin(9600); //?
}

void distance_check()
{
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duracao1 = pulseIn(echoPin1, HIGH);
  distancia1 = duracao1 * 0.017;
  Serial.print(distancia1);
  Serial.print("cm ");
}

void loop() // Main code
{
  distance_check();

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

  /*Code 02
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duracao2 = pulseIn(echoPin2, HIGH);
  distancia2 = duracao2 * 0.017;
  Serial.print(distancia2);
  Serial.print("cm ");

  if (distancia2 > 5)
  {
    digitalWrite(motor, HIGH);
  }
  else if (distancia2 < 5)
  {
    digitalWrite(motor, LOW);
  }

  if (distancia2 < 50)
  {
    digitalWrite(A2, HIGH);
    tone(13, 1000, 50);
    delay(400);
    digitalWrite(A2, LOW);
  }
  else
  {
    digitalWrite(A2, LOW);
    digitalWrite(13, LOW);
  }
  if (distancia2 >= 50 and distancia2 < 200)
  {
    digitalWrite(A1, HIGH);
    delay(500);
    digitalWrite(A1, LOW);
  }
  else
  {
    digitalWrite(A1, LOW);
  }
  if (distancia2 >= 200 and distancia2 < 330)
  {
    digitalWrite(A0, HIGH);
  }
  else
  {
    digitalWrite(A0, LOW);
  }
  delay(100);

  //Code 03
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  duracao3 = pulseIn(echoPin3, HIGH);
  distancia3 = duracao3 * 0.017;
  Serial.print(distancia3);
  Serial.print("cm ");

  if (distancia3 > 5)
  {
    digitalWrite(motor, HIGH);
  }
  else if (distancia1 < 5)
  {
    digitalWrite(motor, LOW);
  }

  if (distancia3 < 50)
  {
    digitalWrite(A5, HIGH);
    tone(13, 1000, 50);
    delay(400);
    digitalWrite(A5, LOW);
  }
  else
  {
    digitalWrite(A5, LOW);
    digitalWrite(13, LOW);
  }
  if (distancia3 >= 50 and distancia3 < 200)
  {
    digitalWrite(A4, HIGH);
    delay(500);
    digitalWrite(A4, LOW);
  }
  else
  {
    digitalWrite(A4, LOW);
  }
  if (distancia3 >= 200 and distancia3 < 330)
  {
    digitalWrite(A3, HIGH);
  }
  else
  {
    digitalWrite(A3, LOW);
  }
  delay(100);
  */
}