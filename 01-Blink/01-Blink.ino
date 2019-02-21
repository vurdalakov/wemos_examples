void setup()
{
	// init debug output
	Serial.begin(9600);

	// set mode of the builin LED pin to "output"
	pinMode(BUILTIN_LED, OUTPUT);
}

void loop()
{
	// print to debug output
	Serial.println("Blink!");

	// turn LED on
	digitalWrite(BUILTIN_LED, LOW);
	
	// wait 1 second
	delay(1000);

	// turn LED off
	digitalWrite(BUILTIN_LED, HIGH);
	
	// wait 1 second
	delay(1000);
}
