// setup parameters
const int trigger= 2;
const int echo = 3;
long timeTaken;
int dist1, dist2;
int distMax = 50;

// setup
void setup() {
  Serial.begin(9600);

  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
}

// calculate distance from sensor
int calculateDistance(int trigger, int echo) {
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  timeTaken = pulseIn(echo, HIGH);
  int dist = timeTaken * (0.034 / 2);

  if (dist > distMax) {
    dist = distMax;
  }
  
  return dist;  
}

void loop() {
    
  dist1 = calculateDistance(trigger, echo);
  delay(300);
  
  dist2 = calculateDistance(trigger, echo);

  // 'Scroll Up' event  
  if (dist2 - dist1 > 0) {
    Serial.println("Scroll Up");
  }
  // 'Scroll Down' event
  else if (dist2 - dist1 < 0) {
    Serial.println("Scroll Down");
  }
  // No movement 
  else if (dist2 - dist1 == 0) {
    Serial.print(calculateDistance(trigger,echo));
    Serial.print(": ");
    Serial.println("Do Nothing");
    delay(100);
  }
    
}
