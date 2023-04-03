
#define enA 10  //H_bridge Pins 
#define in1 6   //H_bridge Pins 
#define in2 7   //H_bridge Pins 
#define in3 8   //H_bridge Pins 
#define in4 9   //H_bridge Pins 
#define enB 11  //H_bridge Pins 


char x = "";  //for bluetooth read

void setup() {

pinMode(enA, OUTPUT); //  Pin enA as output
pinMode(in1, OUTPUT); //  Pin in1 as output
pinMode(in2, OUTPUT); //  Pin in2 as output
pinMode(in3, OUTPUT); //  Pin in3 as output
pinMode(in4, OUTPUT); //  Pin in4 as output
pinMode(enB, OUTPUT); //  Pin enB as output

 Serial.begin(9600);
 
analogWrite(enA, 200); //speed range 0 - 255
analogWrite(enB, 200); //speed range 0 - 255

}

void loop() {

    x = Serial.read();

    switch (x) {
      case'F' :
        forward();
        break;
        
      case'B' :  
        Backward();
        break;

      case'R' :
        turnRight();
        break;

      case'L' :
        turnLeft();
        break;
		
      case'S' :
        Stop();
        break;
    }

}


void forward(){  
digitalWrite(in1, HIGH); //Right Motor forward Pin 
digitalWrite(in2, LOW);  //Right Motor backward Pin 
digitalWrite(in3, HIGH); //Left Motor forward Pin 
digitalWrite(in4, LOW);  //Left Motor backward Pin
 
}

void Backward(){
digitalWrite(in1, LOW);  //Right Motor forward Pin 
digitalWrite(in2, HIGH); //Right Motor backward Pin 
digitalWrite(in3, LOW);  //Left Motor forward Pin 
digitalWrite(in4, HIGH); //Left Motor backward Pin
}


void turnRight(){ 
digitalWrite(in1, LOW);  //Right Motor forward Pin 
digitalWrite(in2, HIGH); //Right Motor backword Pin  
digitalWrite(in3, HIGH); //Left Motor forward Pin 
digitalWrite(in4, LOW);  //Left Motor backward Pin 

}

void turnLeft(){ 
digitalWrite(in1, HIGH); //Right Motor forward Pin 
digitalWrite(in2, LOW);  //Right Motor backward Pin 
digitalWrite(in3, LOW);  //Left Motor forward Pin 
digitalWrite(in4, HIGH); //Left Motor backward Pin 

}

void Stop(){ 
digitalWrite(in1, LOW); //Right Motor forward Pin 
digitalWrite(in2, LOW); //Right Motor backward Pin 
digitalWrite(in3, LOW); //Left Motor forward Pin 
digitalWrite(in4, LOW); //Left Motor backward Pin 
}

