// include ESP8266 Wifi support
#include <ESP8266WiFi.h>

#define WIFI_SSID "*******" // TODO: replace with real SSID
#define WIFI_PASSWORD "********" // TODO: replace with real PASSWORD

void setup()
{
	// init debug output
	Serial.begin(9600);
	Serial.print("\n"); // skip garbage

	// connect to WiFi
	ConnectWiFi(WIFI_SSID, WIFI_PASSWORD);
}

void loop()
{
}

bool ConnectWiFi(const char* ssid, const char* password)
{
	// set station (client) mode
	WiFi.mode(WIFI_STA);

	// just in case
	WiFi.disconnect();

	Serial.printf("Connecting to %s\n", ssid);

	// start connect
	WiFi.begin(ssid, password);

	for (uint8_t attempt = 0; attempt < 60; attempt++) // 60 attempts max
	{
		// get WiFi status
		wl_status_t status = WiFi.status();
		
		if (WL_CONNECTED == status) // connected now
		{
			Serial.println("Connected");

			// print network info
			Serial.printf("MAC address: %s\n", WiFi.macAddress().c_str());
			Serial.printf("IP  address: %s\n", WiFi.localIP().toString().c_str());
			Serial.printf("Subnet mask: %s\n", WiFi.subnetMask().toString().c_str());
			Serial.printf("Gateway  IP: %s\n", WiFi.gatewayIP().toString().c_str());

			return true;
		}
		else if (WL_DISCONNECTED == status) // still not connected
		{
			Serial.printf("%d seconds, not yet connected\n", attempt);
		}
		else // error
		{
			Serial.printf("Cannot connect to WiFi, status %d\n", status);

			return false;
		}

		// wait 1 second before retry
		delay(1000);
	}

	Serial.println("Cannot connect to WiFi, timeout");
	return false;
}
