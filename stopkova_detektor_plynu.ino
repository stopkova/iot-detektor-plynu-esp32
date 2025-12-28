// ==========================================
//      KOMPLETNÝ KÓD - DETEKTOR PLYNU
// ==========================================

// --- 1. ÚDAJE PRE BLYNK  ---
#define BLYNK_TEMPLATE_ID "TMPL4VQVmX8kJ"
#define BLYNK_TEMPLATE_NAME "Detektor plynu"
#define BLYNK_AUTH_TOKEN "9zM3J3U54wEndG_1NqmpHsu_Gmnlpe_0"

// --- 2. KNIŽNICE ---
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// --- 3. WIFI  ---
char ssid[] = "skuska";
char pass[] = "st12451248";

// --- 4. HARDVÉR ---
const int MQ2_PIN = 34;    // Senzor
const int BUZZER_PIN = 2;  // Bzučiak

// Nastavenie OLED displeja
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int ALARM_HRANICA = 1500; 
BlynkTimer timer;

// --- HLAVNÁ FUNKCIA ---
void posielajData() {
  int hodnotaPlynu = analogRead(MQ2_PIN);
  
  // Poslať do Blynku
  Blynk.virtualWrite(V0, hodnotaPlynu);
  
  // Výpis do PC
  Serial.print("Plyn: ");
  Serial.println(hodnotaPlynu);

  // Kreslenie na displej
  display.clearDisplay(); 
  
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("DETEKTOR PLYNU");
  display.drawLine(0, 10, 128, 10, WHITE);

  if (hodnotaPlynu > ALARM_HRANICA) {
    // --- POPLACH (ALARM) ---
    display.setCursor(0, 20);
    display.setTextSize(2);
    display.println("POZOR!");
    display.println("UNIK!!");
    
    display.setTextSize(1);
    display.setCursor(0, 50);
    display.print("Hodnota: ");
    display.print(hodnotaPlynu);
    
    // Pískanie tónom (pre pasívny bzučiak)
    tone(BUZZER_PIN, 1000); 
    
  } else {
    // --- VŠETKO OK ---
    display.setCursor(0, 25);
    display.setTextSize(1);
    display.println("Stav vzduchu:");
    
    display.setTextSize(2);
    display.setCursor(0, 40);
    display.println("NORMA");
    
    display.setTextSize(1);
    display.setCursor(80, 50);
    display.print(hodnotaPlynu);
    
    // Ticho
    noTone(BUZZER_PIN);
    digitalWrite(BUZZER_PIN, LOW); // Pre istotu vypneme aj prúd
  }
  
  display.display(); // Zobraziť všetko
}

void setup() {
  Serial.begin(115200);

  // Nastavenie pinov
  pinMode(MQ2_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);

  // Štart OLED displeja
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("Chyba OLED displeja!"));
    for(;;);
  }
  
  // Úvodná obrazovka
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 20);
  display.println("Pripajanie na WiFi:");
  display.println(ssid);
  display.display();

  // Pripojenie k Blynku
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Po pripojení
  display.clearDisplay();
  display.setCursor(0, 20);
  display.println("Blynk PRIROJENY!");
  display.display();
  delay(1000);

  timer.setInterval(1000L, posielajData);
}

void loop() {
  Blynk.run();
  timer.run();
}