const int dirPin = 3;  // Direction
const int stepPin = 2; // Step
int capteur0= A0;
int capteur1= A1; 
// Motor steps per rotation
const int STEPS_PER_REV = 200;
int valeur0;
int valeur1;
int x0=0;
int x1=0;
int difference;
//bool a= true; 
void tourned50(void){
    // Set motor direction clockwise
  digitalWrite(dirPin,HIGH); 
  
  // Spin motor one rotation slowly
  for(int x = 0; x < 50 ; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(1000); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(1000);
     }
 }

 

void tourneg50(void){
      digitalWrite(dirPin,LOW); 
  
  // Spin motor one rotation slowly
  for(int x = 0; x < 50 ; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(1000); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(1000); 
  }
}
  void tourned100(void){
    // Set motor direction clockwise
  digitalWrite(dirPin,HIGH); 
  
  // Spin motor one rotation slowly
  for(int x = 0; x < 100 ; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(1000); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(1000);
     }
 }
  void tourneg100(void){
      digitalWrite(dirPin,LOW); 
  
  // Spin motor one rotation slowly
  for(int x = 0; x < 100 ; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(1000); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(1000); 
  }
}
 void stope (void)
    {
      for(int x = 0; x < 50; x++) {
    digitalWrite(stepPin, LOW); 
    delayMicroseconds(1000); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(1000); 
      }
    }

 

void setup() {
  
  // Setup the pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(capteur0,INPUT);
  pinMode(capteur1,INPUT);
  Serial.begin(9600);
}

 

void loop() {
  delay(10000);
  
  valeur0= analogRead(capteur0);
  valeur1= analogRead(capteur1);
  
  // x0= map (valeur0 ,0, 1023 ,0,700);
  //x1= map (valeur1 ,0, 1023 ,0,700);
  
  difference = (abs(valeur0- valeur1));
     Serial.print("valeur1=:");
     Serial.println(valeur0);
     Serial.print("valeur2=:");
     Serial.println(valeur1);
     Serial.print("la difference =");
     Serial.println(difference );
    
    if ((difference<10))
    { 
     stope();
     }
    else if( 10 < difference <20){
      if (valeur0<valeur1){
        tourned50();
        } 
      else {
       tourneg50();
       } 
    }
  
     else if (difference >20) {
      if (valeur0<valeur1){
        tourned100();
        } 
      else {
        tourneg100();
       }
      
     }
  }
