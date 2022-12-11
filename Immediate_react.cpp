#include <evive.h>

//MACROS are defined here
float getDistance(int trig,int echo){
		pinMode(trig,OUTPUT);
		digitalWrite(trig,LOW);
		delayMicroseconds(2);
		digitalWrite(trig,HIGH);
		delayMicroseconds(10);
		digitalWrite(trig,LOW);
		pinMode(echo, INPUT);
		return pulseIn(echo, HIGH)/58.0;
}
Servo Servo44;

void setup() {
	//put your setup code here, to run once:
	Servo44.attach(44);
	
	
}

void loop() {
	//put your main code here, to run repeatedly:
	
	
	if((getDistance(2, 3) < 20)) {
		Servo44.write(180);
		delay(0.03 * 1000);
	}
	else {
		Servo44.write(100);
		delay(0.03 * 1000);
	}
}
