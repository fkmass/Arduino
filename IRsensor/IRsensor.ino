// Ejemplo de uso del sensor de obstaculos

#define noObstacle HIGH

int isObstaculePin = 8;
int isObstacle;

void setup() {
  // put your setup code here, to run once:
  pinMode(isObstaculePin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("#Hola");

}

void loop() {
  // put your main code here, to run repeatedly:
  isObstacle = digitalRead(isObstaculePin);
  if (isObstacle == LOW){
    Serial.println("Obstaculo");
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else{
    digitalWrite(LED_BUILTIN, LOW);
  }
  delay(200);
}
