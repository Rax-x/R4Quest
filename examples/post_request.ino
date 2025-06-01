#include <R4Quest.h>
#include <WiFi.h>

#define IP "192.168.1.100"

char ssid[] = "YOUR_NETWORK_SSID";
char pass[] = "YOUR_NETWORK_PASS";

static HTTPClient client;
int status = WL_IDLE_STATUS; 

void setup() {
    Serial.begin(9600);
    if (WiFi.status() == WL_NO_MODULE) {
        Serial.println("Communication with WiFi module failed!");
        while (true)
        ;
    }

    String fv = WiFi.firmwareVersion();
    if (fv < WIFI_FIRMWARE_LATEST_VERSION) {
        Serial.println("Please upgrade the firmware");
    }

    while (status != WL_CONNECTED) {
        Serial.print("Attempting to connect to SSID: ");
        Serial.println(ssid);
        
        status = WiFi.begin(ssid, pass);
        delay(10000);
    }
}

void loop() {
    client.set_header("Content-Type", "application/json");
    int status_code = client.request_post(IP, "{\"name\": \"HTTPLib\"}");

    if (status_code == HTTP_OK)
        Serial.println("OK");
}