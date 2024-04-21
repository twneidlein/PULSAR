#define AREF 5          // set to AREF, typically board voltage like 3.3 or 5.0
#define ADC_RESOLUTION 10  // set to ADC bit resolution, 10 is default
#include <Servo.h>


float reading, voltage, temperature, power;
float pressure1, temperature1, pressure2, temperature2, reading1, reading2, reading3, reading4, reading5, reading6, reading7;   //Variables for printing
float voltage1, voltage2, voltage3, voltage4, voltage5, voltage6, voltage7, button; 
Servo esc_1; // create servo oject to control the PWM signal

int buttonCount = 0;
int loopCount = 0;

float get_voltage(int raw_adc) {
  return raw_adc * (AREF / (pow(2, ADC_RESOLUTION)-1));  
}
float get_voltagepressure(int raw_adc) {
  int corrected_adc = raw_adc;
  return corrected_adc * (AREF / (pow(2, ADC_RESOLUTION)-1)); 
}
float get_temperature(float voltage) {
  return (voltage - 1.25) / 0.005;
}

float get_pressure(float voltage) { // to get pressure from voltage
  return (voltage * (200 - 0) / 5 - 5); // Might need to change
}

void set_esc_power (Servo esc, int power){
  power = constrain(power, -100, 100);
  int signal_min = 1050; //Find that information
  int signal_max = 1950;
  int signal_output = map(power, -100, 100, signal_min, signal_max);
  esc.writeMicroseconds(signal_output);

}

//Beginning Setup
void setup() {
  Serial.begin(9600);
  esc_1.attach(9);     //The motor is attached to pin 9
  pinMode(13, INPUT); //For the switch of emergency shutoff on the arduino

}

void loop() {
  button = digitalRead(13);
  if (buttonCount == 0) {
    Serial.flush();
    buttonCount++;
    Serial.print("\n\n\n\n\n\n\n\n\n\n\nLaunch in 5");
    delay(1000);
    Serial.print(", 4");
    delay(1000);
    Serial.print(", 3");
    delay(1000);
    Serial.print(", 2");
    delay(1000);
    Serial.println(", 1");
    delay(950);
  }

 // reading1 = analogRead(A1); //A1 is temperature inlet
 // reading2 = analogRead(A2); //A2 is temperature outlet
  reading3 = analogRead(A1); //A3 is pressure inlet
 // reading4 = analogRead(A2); //A4 is pressure outlet

 // voltage1 = get_voltage(reading1);
 // voltage2 = get_voltage(reading2);
  voltage3 = get_voltagepressure(reading3);
  voltage4 = get_voltagepressure(reading4);  

  //temperature1 = get_temperature(voltage1);
  //temperature2 = get_temperature(voltage2);
  pressure1 = get_pressure(voltage3);
//  pressure2 = get_pressure(voltage4);
 
  //Printing stuff

  Serial.print("P_outlet:");
  Serial.print(pressure1); //Serial.print(" , ");
  Serial.println(" Psi ");

/*
  Serial.print(" , ");
  Serial.print("P_outlet:");
  Serial.print(pressure2);
  Serial.println(" Psi");
*/

/*Serial.print(",  Analog is ");
Serial.print(reading3); // Was 28 with short wires
Serial.print("  voltage is ");
Serial.println(voltage3);
*/

  //Motor shit for TOM
  if (loopCount < 6){
    set_esc_power(esc_1, 15); // JOHN CHANGE THE VALUE AFTER THE COMMA : (esc_1, x)
  }
  else {
    set_esc_power(esc_1, 20); // JOHN SAME HERE
  }

// Loop Count to stop code
loopCount++;
delay(200); // JOHN duration of one loop, dont change for now
if (loopCount == 50) //JOHN : 100 = running for 20s, 50 = 10s
{
  Serial.println("\n\nEND OF THE LAUNCH");
  set_esc_power(esc_1, 0); // NEVER CHANGE
  delay(1000000);
}
} //END OF THE CODE



/*  Serial.print("\nT_inlet:");
  Serial.print(temperature1); //Serial.print(" , ");
  Serial.print(" °C ");
  Serial.print(" , ");
  Serial.print("T_outlet:");
  Serial.print(temperature2);
  Serial.print(" C");
 */ 