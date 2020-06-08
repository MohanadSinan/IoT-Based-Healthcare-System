#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define USE_ARDUINO_INTERRUPTS true
#include <PulseSensorPlayground.h>


//------------------------------------------------------------------------------------------
const char * SSID_NAME = "FastEnough";
const char * SSID_PASS = "A1B2c3d4";
const char * TOKEN = "BBFF-xlbHxBMzBq28K0tXBpE5D8AAuZxQeC";
const char * SERVER = "industrial.api.ubidots.com";
const char * DEVICE_LABEL = "mega2560";
const char * VARIABLE_LABEL1 = "temperature";
const char * VARIABLE_LABEL2 = "humidity";
const char * VARIABLE_LABEL3 = "bpm";
const char * USER_AGENT = "MEGA2560";
const char * VERSION = "1.0";
const int PORT = 9012;
//------------------------------------------------------------------------------------------

const int PulseWire = 1;
const int LED13 = 13;
int Threshold = 550;

#define DHTPIN 7
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);
PulseSensorPlayground pulseSensor;


void setup() {
  Serial.begin(115200);
  Serial3.begin(115200);

  dht.begin();
  lcd.backlight();
  lcd.init();
  pulseSensor.analogInput(PulseWire);
  pulseSensor.blinkOnPulse(LED13);
  pulseSensor.setThreshold(Threshold);

  if (pulseSensor.begin()) {
    Serial.println("We created a pulseSensor Object !");
  }

  Serial3.println("AT");
  if (Serial3.find("Error")) {
    Serial.println("ERROR!\nAT Commands system does NOT works correctly.");
    return;
  }
  delay(100);
  Serial3.println("AT+CWMODE=3");
  delay(100);
  Serial3.println("AT+CIPMUX=1");
  delay(100);

  if (Serial3.find("OK")) {
    Serial.println("Connecting to ");
    Serial.println(SSID_NAME);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Connecting to: ");
    lcd.setCursor(0, 1);
    lcd.print(SSID_NAME);
    delay(3000);
  }

  String cmd = "AT+CWJAP=\"";
  cmd += SSID_NAME;
  cmd += "\"\,\"";
  cmd += SSID_PASS;
  cmd += "\"";
  Serial3.println(cmd);
  delay(3000);
  Serial3.println("AT+CIPSTATUS=?");
  delay(2000);

  if ( Serial3.find("OK") ) {
    Serial.println("\nConnected.");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Connected");
    delay(1000);
  }
  else {
    Serial.println("ERROR!\nUnable to connect to the selected access point.");
  }
  delay(1000);
}

void loop() {
  Serial.println("\n========================================");

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t))
  {
    lcd.init();
    lcd.setCursor(1, 0);
    lcd.print("Failed to read");
    lcd.setCursor(0, 1);
    lcd.print("from DHT sensor!");
    return;
  }

  int myBPM = pulseSensor.getBeatsPerMinute();
  int BPM = myBPM - 172;


  // AT+CIPSTART=4,"TCP","industrial.api.ubidots.com",9012
  String atTcpPortConnectCmd = "AT+CIPSTART=4,\"TCP\",\"";
  atTcpPortConnectCmd += SERVER;
  atTcpPortConnectCmd += "\",9012";
  Serial3.println(atTcpPortConnectCmd);
  delay(300);
  if ( Serial3.find("OK") ) {
    Serial.println("connection to ubidots is established");
    lcd.setCursor(15, 0);
    lcd.print("*");
  }
  else {
    Serial.println("ERROR!\nUnable to connect to ubidots.");
    lcd.setCursor(15, 0);
    lcd.print("!");
  }

  Serial.print("\nTemperature: ");
  Serial.print(t);
  Serial.println("°C");
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.println("%");
  if (BPM < 0)  {
    Serial.println("No HeartBeat Happened !");
  }
  else {
    Serial.println("♥  A HeartBeat Happened ! ");
    Serial.print("BPM: ");
    Serial.println(BPM);
  }


  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.print(t);
  lcd.print((char)223);
  lcd.print("C   ");
  lcd.setCursor(0, 1);
  lcd.print("Humidity:");
  lcd.print(h);
  lcd.print("%");
  delay(5000);
  if (BPM < 0)  {
    lcd.setCursor(0, 0);
    lcd.print("  No HeartBeat");
    lcd.setCursor(0, 1);
    lcd.print("   Happened !   ");
  }
  else {
    lcd.setCursor(0, 0);
    lcd.print("BPM:");
    lcd.print(BPM);
    lcd.print("      ");
    lcd.setCursor(0, 1);
    lcd.print("                ");
  }


  // USER_AGENT/VERSION|POST|TOKEN|DEVICE_LABEL=>VARIABLE_LABEL1:t,VARIABLE_LABEL2:h,VARIABLE_LABEL3:BPM|end
  String atGETCmd = USER_AGENT;
  atGETCmd += "/";
  atGETCmd += VERSION;
  atGETCmd += "|POST|";
  atGETCmd += TOKEN;
  atGETCmd += "|";
  atGETCmd += DEVICE_LABEL;
  atGETCmd += "=>";
  atGETCmd += VARIABLE_LABEL1;
  atGETCmd += ":";
  atGETCmd += t;
  atGETCmd += ",";
  atGETCmd += VARIABLE_LABEL2;
  atGETCmd += ":";
  atGETCmd += h;
  atGETCmd += ",";
  atGETCmd += VARIABLE_LABEL3;
  atGETCmd += ":";
  atGETCmd += BPM;
  atGETCmd += "|end";



  // send data length
  Serial3.println("AT+CIPSEND=4," + String(atGETCmd.length() + 4));
  delay(3000);


  Serial3.println(atGETCmd);
  delay(2000);

  if ( Serial3.find("OK") ) {
    Serial.println("\nData Sent.");
    lcd.setCursor(15, 0);
    lcd.print("^");

  }

  Serial3.println("AT+CIPCLOSE=4");
  delay(200);
  if ( Serial3.find("OK") ) {
    Serial.println("Disconnected from ubidots");
  }
}
