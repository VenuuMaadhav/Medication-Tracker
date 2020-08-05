#include <ESP8266WiFi.h>
#include <Adafruit_MQTT.h>
#include <Adafruit_MQTT_Client.h>
#include <DHT.h>
int led1 =D0;
int led2 =D1;
int led3 =D2;
int led4 =D4;
int led5 =D5;
int led6 =D6;
int led7 =D7;
int loff=D8;
 int count =0;
#define DHTPIN D3
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);
/********* WiFi Access Point ***********/

#define WLAN_SSID       # "Your wifi name"
#define WLAN_PASS       # "Password"

/********* Adafruit.io Setup ***********/

#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883                   // use 8883 for SSL
#define AIO_USERNAME    # "Adafruit user name"
#define AIO_KEY         # "Adafruit aiokey"

/**** Global State (you don't need to change this!) ******/

// Create an ESP8266 WiFiClient class to connect to the MQTT server.
WiFiClient client;
// or... use WiFiFlientSecure for SSL
//WiFiClientSecure client;

// Setup the MQTT client class by passing in the WiFi client and MQTT server and login details.
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);

/********** Feeds *************/

// Setup a feeds for publishing.
// Notice MQTT paths for AIO follow the form: <username>/feeds/<feedname>
Adafruit_MQTT_Publish Temperature = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/Temperature");
Adafruit_MQTT_Publish Humidity = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/Humidity");
Adafruit_MQTT_Publish Light1 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/Light1");
Adafruit_MQTT_Publish Light2 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/Light2");
Adafruit_MQTT_Publish Light3 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/Light3");
Adafruit_MQTT_Publish Light4 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/Light4");
Adafruit_MQTT_Publish Light5 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/Light5");
Adafruit_MQTT_Publish Light6 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/Light6");
Adafruit_MQTT_Publish Light7 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/Light7");

Adafruit_MQTT_Publish Flag = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/Flag");


// Setup a feed called 'Light1' for subscribing to changes.
Adafruit_MQTT_Subscribe onoffbutton1 = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/Light1");
Adafruit_MQTT_Subscribe onoffbutton2= Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/Light2");
Adafruit_MQTT_Subscribe onoffbutton3 = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/Light3");
Adafruit_MQTT_Subscribe onoffbutton4 = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/Light4");
Adafruit_MQTT_Subscribe onoffbutton5 = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/Light5");
Adafruit_MQTT_Subscribe onoffbutton6 = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/Light6");
Adafruit_MQTT_Subscribe onoffbutton7 = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/Light7");


/********* Sketch Code ************/

// Bug workaround for Arduino 1.6.6, it seems to need a function declaration
// for some reason (only affects ESP8266, likely an arduino-builder bug).
void MQTT_connect();

void setup() {
  Serial.begin(9600);
  delay(10);
    dht.begin();
  Serial.println(F("Adafruit MQTT demo"));

  // Connect to WiFi access point.
  Serial.println(); Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WLAN_SSID);

  WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.println("WiFi connected");
  Serial.println("IP address: "); Serial.println(WiFi.localIP());

  // Setup MQTT subscription for onoff feed.
  mqtt.subscribe(&onoffbutton1);
  mqtt.subscribe(&onoffbutton2);
  mqtt.subscribe(&onoffbutton3);
  mqtt.subscribe(&onoffbutton4);
  mqtt.subscribe(&onoffbutton5);
  mqtt.subscribe(&onoffbutton6);
  mqtt.subscribe(&onoffbutton7);

   pinMode(led1,OUTPUT);
  digitalWrite(led1,LOW);
  pinMode(led2,OUTPUT);
  digitalWrite(led2,LOW);
  pinMode(led3,OUTPUT);
  digitalWrite(led3,LOW);
  pinMode(led4,OUTPUT);
  digitalWrite(led4,LOW);
  pinMode(led5,OUTPUT);
  digitalWrite(led5,LOW);
  pinMode(led6,OUTPUT);
  digitalWrite(led6,LOW);
  pinMode(led7,INPUT);
  //digitalWrite(led7,LOW);
  
  
}

uint32_t x=0;
int q;
void loop() {
  // Ensure the connection to the MQTT server is alive (this will make the first
  // connection and automatically reconnect when disconnected).  See the MQTT_connect
  // function definition further below.
  MQTT_connect();

  // this is our 'wait for incoming subscription packets' busy subloop
  // try to spend your time here
 Adafruit_MQTT_Subscribe *subscription;
  while ((subscription = mqtt.readSubscription(5000))) {
    if (subscription == &onoffbutton1) {
      Serial.print(F("Got: "));
      Serial.println((char *)onoffbutton1.lastread);
      if(!strcmp((char*) onoffbutton1.lastread, "ON"))
      {
        digitalWrite(led1,HIGH);
                digitalWrite(led6,HIGH);

        q=1;
        count=0;
        //Light1.publish("ON");
      }
         else if (!strcmp((char*) onoffbutton1.lastread, "OFF"))
         {
        digitalWrite(led1,LOW);
                        digitalWrite(led6,LOW);

        q=0;
        //Light1.publish("OFF");
      }
      else{
        Light1.publish("ERROR");
      }
    }
  
    if (subscription == &onoffbutton2) {
      Serial.print(F("Got: "));
      Serial.println((char *)onoffbutton2.lastread);
      if(!strcmp((char*) onoffbutton2.lastread, "ON"))
      {
        digitalWrite(led2,HIGH);
                digitalWrite(led6,HIGH);

        q=1;
        count=0;
        //Light1.publish("ON");
      }
         else if (!strcmp((char*) onoffbutton2.lastread, "OFF"))
         {
        digitalWrite(led2,LOW);
                                digitalWrite(led6,LOW);

        q=0;
        //Light1.publish("OFF");
      }
      else{
        Light1.publish("ERROR");
      }
    }
  
    if (subscription == &onoffbutton3) {
      Serial.print(F("Got: "));
      Serial.println((char *)onoffbutton3.lastread);
      if(!strcmp((char*) onoffbutton3.lastread, "ON"))
      {
        digitalWrite(led3,HIGH);
                digitalWrite(led6,HIGH);

        q=1;
        count=0;
        //Light1.publish("ON");
      }
         else if (!strcmp((char*) onoffbutton3.lastread, "OFF"))
         {
        digitalWrite(led3,LOW);
                                digitalWrite(led6,LOW);

        q=0;
        //Light1.publish("OFF");
      }
      else{
        Light1.publish("ERROR");
      }
    }
  
    if (subscription == &onoffbutton4) {
      Serial.print(F("Got: "));
      Serial.println((char *)onoffbutton4.lastread);
      if(!strcmp((char*) onoffbutton4.lastread, "ON"))
      {
        digitalWrite(led4,HIGH);
                digitalWrite(led6,HIGH);

        q=1;
        count=0;
        //Light1.publish("ON");
      }
         else if (!strcmp((char*) onoffbutton4.lastread, "OFF"))
         {
        digitalWrite(led4,LOW);
                                digitalWrite(led6,LOW);

        q=0;
        //Light1.publish("OFF");
      }
      else{
        Light1.publish("ERROR");
      }
    }
  
    if (subscription == &onoffbutton5) {
      Serial.print(F("Got: "));
      Serial.println((char *)onoffbutton5.lastread);
      if(!strcmp((char*) onoffbutton5.lastread, "ON"))
      {
        digitalWrite(led5,HIGH);
                digitalWrite(led6,HIGH);

        q=1;
        count=0;
        //Light1.publish("ON");
      }
         else if (!strcmp((char*) onoffbutton5.lastread, "OFF"))
         {
        digitalWrite(led5,LOW);
                                digitalWrite(led6,LOW);

        q=0;
        //Light1.publish("OFF");
      }
      else{
        Light1.publish("ERROR");
      }
    }
  
    /*if (subscription == &onoffbutton6) {
      Serial.print(F("Got: "));
      Serial.println((char *)onoffbutton6.lastread);
      if(!strcmp((char*) onoffbutton6.lastread, "ON"))
      {
        digitalWrite(led6,HIGH);
        q=1;
        count=0;
        //Light1.publish("ON");
      }
         else if (!strcmp((char*) onoffbutton6.lastread, "OFF"))
         {
        digitalWrite(led6,LOW);
        q=0;
        //Light1.publish("OFF");
      }
      else{
        Light1.publish("ERROR");
      }
    }
  
    if (subscription == &onoffbutton7) {
      Serial.print(F("Got: "));
      Serial.println((char *)onoffbutton7.lastread);
      if(!strcmp((char*) onoffbutton7.lastread, "ON"))
      {
        digitalWrite(led7,HIGH);
        q=1;
        count=0;
        //Light1.publish("ON");
      }
         else if (!strcmp((char*) onoffbutton7.lastread, "OFF"))
         {
        digitalWrite(led7,LOW);
        q=0;
        //Light1.publish("OFF");
      }
      else{
        Light1.publish("ERROR");
      }
    }*/
  }
  
   delay(1000);
      Serial.print("Light1 :");
  Serial.println(digitalRead(led1));
  Serial.print("Light2 :");
  Serial.println(digitalRead(led2));
  Serial.print("Light3 :");
  Serial.println(digitalRead(led3));
  Serial.print("Light4 :");
  Serial.println(digitalRead(led4));
  Serial.print("Light5 :");
  Serial.println(digitalRead(led5));
  Serial.print("Light6 :");
  Serial.println(digitalRead(led6));
  Serial.print("Light7 :");
  Serial.println(digitalRead(led7));
  
if(digitalRead(led7)==1)
{
  digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW);
  digitalWrite(led5,LOW);
  digitalWrite(led6,LOW);
  //digitalWrite(led7,LOW);

}
//home automation
/*
if(digitalRead(led7)==1){
  digitalWrite(led6,HIGH);
  Light7.publish("ON");
  delay(3000);
    digitalWrite(led6,LOW);

}
*/
//Light7.publish("OFF");

  // Now we can publish stuff!
  delay(1000);
  float h = dht.readHumidity();       //Read Humidity
  //delay(1000);
  float t = dht.readTemperature();    //Read Temperature
  Serial.print(F("\nSending Temperature  val "));
  Serial.println(t);
  Serial.print("...");
  //float temp1=analogRead(sensor);
  if (! Temperature.publish(t)){
    Serial.println(F("Failed"));
  } else {
    Serial.println(F("OK!"));
  }
  //delay(1000);
  Serial.print(F("\nSending Humidity  val "));
    Serial.println(h);
  if (! Humidity.publish(h)){
    Serial.println(F("Failed"));
  } else {
    Serial.println(F("OK!"));
  }
count=count+10;
if(count>60){
  if(digitalRead(led1)==1||digitalRead(led2)==1||digitalRead(led3)==1||digitalRead(led4)==1||digitalRead(led5)==1){
    Flag.publish("ON");
    count=0;
  }
}


}

// Function to connect and reconnect as necessary to the MQTT server.
// Should be called in the loop function and it will take care if connecting.
void MQTT_connect() {
  int8_t ret;

  // Stop if already connected.
  if (mqtt.connected()) {
    return;
  }

  Serial.print("Connecting to MQTT... ");

  uint8_t retries = 3;
  while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected
       Serial.println(mqtt.connectErrorString(ret));
       Serial.println("Retrying MQTT connection in 5 seconds...");
       mqtt.disconnect();
       delay(5000);  // wait 5 seconds
       retries--;
       if (retries == 0) {
         // basically die and wait for WDT to reset me
         while (1);
       }
  }
  Serial.println("MQTT Connected!");
}
