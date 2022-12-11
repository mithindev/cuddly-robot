
#include <evive.h>

//MACROS are defined here
TFT_ST7735 lcd = TFT_ST7735();
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
Motor Motor1(MOTOR1_D1, MOTOR1_D2, MOTOR1_EN);
Servo Servo45;

//Gloabl Variables are declared here
float Delay_Time;

//User Defined Functions
void Brake() {
	Motor1.freeMotor();
	Motor1.freeMotor();
	lcd.setCursor(55, 70);
	lcd.print(" Brake     ");
}
void Turn_Right() {
	Motor1.moveMotor(2.55*100);
	Motor1.moveMotor(2.55*100);
	Servo45.write(90);
	lcd.setCursor(55, 70);
	lcd.print("Right     ");
}
void Turn_Left() {
	Motor1.moveMotor(2.55*100);
	Motor1.moveMotor(2.55*100);
	Servo45.write(90);
	lcd.setCursor(55, 70);
	lcd.print("Left     ");
}
void Take_Reverse() {
	Go_Backward();
	delay(Delay_Time * 1000);
	Turn_Left();
	delay((Delay_Time * 2) * 1000);
	lcd.setCursor(55, 70);
	lcd.print("Reverse   ");
}
void Go_Backward() {
	Motor1.moveMotor(2.55*100);
	Motor1.moveMotor(2.55*100);
	Servo45.write(90);
	lcd.setCursor(55, 70);
	lcd.print("Backward");
}
void Go_Straight() {
	Motor1.moveMotor(2.55*100);
	Motor1.moveMotor(2.55*100);
	Servo45.write(90);
	lcd.setCursor(55, 70);
	lcd.print("Straight");
}

void setup() {
	//put your setup code here, to run once:
	lcd.init(INITR_BLACKTAB);
	lcd.setRotation(1);
	Servo45.attach(45);
	
	
	Delay_Time = 0.5;
	lcd.fillScreen(0);
	lcd.setCursor(25, 10);
	lcd.setTextColor(65535, 0);
	lcd.setTextSize(1);
	lcd.print("STEMpedia");
	lcd.setTextColor(2016, 0);
	lcd.setTextSize(1);
	lcd.setCursor(30, 30);
	lcd.print("Obstacle Avoidance");
	lcd.setCursor(60, 40);
	lcd.print("Robot");
	lcd.setCursor(60, 60);
	lcd.print("Status");
	lcd.setCursor(25, 90);
	lcd.print("Made By: STEMpedia");
	lcd.setTextColor(65535, 0);
	lcd.setTextSize(1);
	lcd.setCursor(0, 105);
	lcd.print("FOR MORE INFORMATION VISIT");
	lcd.setCursor(30, 115);
	lcd.print("thestempedia.com");
}

void loop() {
	//put your main code here, to run repeatedly:
	
	
	if((getDistance(2, 2) < 20)) {
		Brake();
		Servo45.write(45);
		delay(0.5 * 1000);
		if((getDistance(2, 2) > 50)) {
			Turn_Right();
			delay(Delay_Time * 1000);
		}
		else {
			Servo45.write(135);
			delay(0.5 * 1000);
			if((getDistance(2, 2) > 50)) {
				Turn_Left();
				delay(Delay_Time * 1000);
			}
			else {
				Servo45.write(0);
				delay(0.5 * 1000);
				if((getDistance(2, 2) > 50)) {
					Turn_Right();
					delay((Delay_Time * 2) * 1000);
				}
				else {
					Servo45.write(180);
					delay(0.5 * 1000);
					if((getDistance(2, 2) > 50)) {
						Turn_Left();
						delay((Delay_Time * 2) * 1000);
					}
					else {
						Take_Reverse();
					}
				}
			}
		}
	}
	Go_Straight();
	delay(0.2 * 1000);
}
