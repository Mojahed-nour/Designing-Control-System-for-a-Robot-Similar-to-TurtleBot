
#define outputA (6, 12)
#define outputB (7, 13)
 int present, past,counter = 0;
 const int disPin = 2;
 

 void setup() { 
   pinMode ((6, 12),INPUT_PULLUP);
   pinMode ((7, 13),INPUT_PULLUP);
   
   Serial.begin (9600);
   
   past = digitalRead(outputB);   
 } 

 void loop() {
   long duration, cm;
  
  pinMode(disPin, OUTPUT);
  digitalWrite(disPin, LOW);
  delayMicroseconds(2);
  digitalWrite(disPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(disPin, LOW);
  
  pinMode(disPin, INPUT);
  duration = pulseIn(disPin, HIGH);
  
   

   present = digitalRead(outputA); 
   if (present != past){    
     
    
     if (digitalRead(outputB) == present) { 
       counter ++;
     }
     
     Serial.print("N of rotations: ");
     Serial.println(counter);
     Serial.print("duration: ");
     Serial.println(duration);
     
   } 
   past = present; 
 }
