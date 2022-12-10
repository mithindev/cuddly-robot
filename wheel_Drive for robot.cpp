#include <evive.h>

//Included Libraries
#include <Dabble.h>

//MACROS are defined here
TFT_ST7735 lcd = TFT_ST7735();
Motor Motor1(MOTOR1_D1, MOTOR1_D2, MOTOR1_EN);
Motor Motor2(MOTOR2_D1, MOTOR2_D2, MOTOR2_EN);

//User Defined Functions
void Go_Straight() {
	Motor1.moveMotor(2.55*100);
	Motor2.moveMotor(2.55*100);
}
void Go_Backward() {
	Motor1.moveMotor(-2.55*100);
	Motor2.moveMotor(-2.55*100);
}
void Turn_Left() {
	Motor1.moveMotor(-2.55*100);
	Motor2.moveMotor(2.55*100);
}
void Turn_Right() {
	Motor1.moveMotor(2.55*100);
	Motor2.moveMotor(-2.55*100);
}
void Brake() {
	Motor1.freeMotor();
	Motor2.freeMotor();
}

void setup() {
	//put your setup code here, to run once:
	lcd.init(INITR_BLACKTAB);
	lcd.setRotation(1);
	Dabble.begin(115200);
	
	
	lcd.fillScreen(0);
}

void loop() {
	//put your main code here, to run repeatedly:
	Dabble.processInput();
	
	
	lcd.setCursor(10, 10);
	if(GamePad.isPressed(1)) {
		Go_Straight();
		lcd.print("Straight    ");
	}
	else {
		if(GamePad.isPressed(0)) {
			Go_Backward();
			lcd.print("Backward");
		}
		else {
			if(GamePad.isPressed(3)) {
				Turn_Left();
				lcd.print("Left          ");
			}
			else {
				if(GamePad.isPressed(2)) {
					Turn_Right();
					lcd.print("Right        ");
				}
				else {
					Brake();
					lcd.print("Stop        ");
				}
			}
		}
	}
}
