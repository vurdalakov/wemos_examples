/*

                         |---------------|
                         |               |
                         | Wemos D1 mini |
                         |               |
         ----  \-------> o D7 (GPIO13)   |
         |               |               |
         |               |               |
         --------------> o G             |
                         |               |
                         |------ooo------|
								^^^
								\|/
								 |
								 |
								USB
*/

// we connect button to GPIO13 (D7)
#define BUTTON_PIN 13

void setup()
{
	// init debug output
	Serial.begin(9600);
	Serial.print("\n"); // skip garbage

	// set mode of the builin LED pin to "output" mode
	pinMode(BUILTIN_LED, OUTPUT);

	// turn off LED
	digitalWrite(BUILTIN_LED, HIGH);

	// set button pin to "input with pull-up" mode
	pinMode(BUTTON_PIN, INPUT_PULLUP);

	// configure interrupt function to be called when user presses or releases the button
	attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), buttonInterruptHandler, CHANGE);
}

void loop()
{
}

void buttonInterruptHandler()
{
	// find out if button was pressed or released
	int buttonState = digitalRead(BUTTON_PIN);

	// depending on that turn LED on or off
	digitalWrite(BUILTIN_LED, buttonState);
}
