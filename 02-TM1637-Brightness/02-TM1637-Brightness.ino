/*

|---------------|        |---------------|
|               |        |               |
|    TM1637     |        | Wemos D1 mini |
|               |        |               |
|           GND o <----> o G             |
|           VCC o <----> o 3V3           |
|           DIO o <----> o D1 (GPIO5)    |
|           CLK o <----> o D2 (GPIO4)    |
|               |        |               |
|---------------|        |------ooo------|
                                ^^^
								\|/
								 |
								 |
								USB
*/

// Include DigitalTube library
// https://github.com/reeedstudio/libraries/tree/master/DigitalTube
#include "DigitalTube\TM1637.h"

#define TM1637_CLK  4 // TM1637 CLK pin is connected to WEMOS GPIO4 pin
#define TM1637_DIO  5 // TM1637 DIO pin is connected to WEMOS GPIO5 pin

// access TM1637 display through DigitalTube library
TM1637 tm1637(TM1637_CLK, TM1637_DIO);

// TM1637 display brightness can be in the range from BRIGHT_DARKEST to BRIGHTEST (0-7)
uint8_t brightness = BRIGHT_TYPICAL; // start with typical brightness

void setup()
{
	// init debug output
	Serial.begin(9600);

	// init display
	tm1637.init();
}

void loop()
{
	// print brightness to debug output
	Serial.print("Brightness ");
	Serial.println(brightness);

	// set display brightness
	tm1637.set(brightness);

	// show brightness value on display
	tm1637.display(0, brightness);

	// increase brightness
	brightness++;
	if (brightness > BRIGHTEST)
	{
		brightness = BRIGHT_DARKEST;
	}

	// show brightness value for 1 second
	delay(1000);
}
