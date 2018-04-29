 
 #include <Shifter.h>;
 int DATO1 = 0;
 int DATO2 = 1;
 int DATO3 = 2;
 int DATO4 = 3;
 int DATO5 = 4;
 int DATO6 = 5;
 int DATO7 = 6;
 int DATO8 = 7;

 


 #define SER_pin 11
 #define RCLK_pin 8
 #define SRCLK_pin 12
 #define NUM_REGISTERS 1 


 Shifter shifter(SER_pin,RCLK_pin,SRCLK_pin,NUM_REGISTERS);

void setup() {

}

void loop() {
 shifter.setPin( 1,HIGH);
 shifter.write();
 delay(500);
 shifter.setPin (1,LOW);
 shifter.write();
 delay(500);
 

}
