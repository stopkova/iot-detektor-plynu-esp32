# IoT detektor plynu s využitím mikrokontroléra ESP32

**Katolícka univerzita v Ružomberku**  
Pedagogická fakulta  
Katedra pedagogiky a špeciálnej pedagogiky  

**Projekt z predmetu:** Internet vecí  

**Autor:** PaedDr. Michaela Stopková, PhD.  
**Študijný program:** RŠ informatiky  
**Miesto a rok:** Ružomberok  

---

## 1 Úvod

Projekt sa zameriava na návrh a realizáciu jednoduchého IoT detektora plynu, ktorý slúži na monitorovanie prítomnosti horľavých plynov a dymu v uzavretých priestoroch. Projekt je postavený na mikrokontroléri ESP32, ktorý umožňuje spracovanie nameraných údajov, ich lokálne zobrazenie a zároveň prenos dát do cloudovej IoT platformy prostredníctvom Wi-Fi pripojenia.

Cieľom projektu je demonštrovať praktické využitie mikrokontroléra ESP32 v oblasti bezpečnosti a internetu vecí (IoT), konkrétne pri včasnej detekcii potenciálne nebezpečných situácií, ako je únik plynu.

---

## 2 Účel projektu

Hlavným účelom projektu je:

- monitorovanie koncentrácie plynov a dymu,
- upozornenie používateľa na nebezpečný stav,
- zvýšenie bezpečnosti v domácnosti alebo menších priestoroch.

Systém je navrhnutý tak, aby:

- poskytoval okamžitú vizuálnu informáciu o stave vzduchu,
- pri prekročení nastavenej hranice spustil zvukový alarm,
- umožnil vzdialené sledovanie nameraných hodnôt pomocou mobilnej aplikácie.

Projekt je vhodný ako edukačný a demonštračný príklad použitia IoT technológií v praxi.

---

## 3 Použitý hardvér

Projekt využíva nasledovné hardvérové komponenty:

- **ESP32** – hlavná riadiaca jednotka systému, zabezpečuje:
  - čítanie dát zo senzora,
  - spracovanie nameraných hodnôt,
  - komunikáciu cez Wi-Fi,
  - ovládanie výstupných zariadení.

- **Senzor plynu MQ-2** – slúži na detekciu:
  - horľavých plynov (LPG, propán, metán),
  - dymu.

- **OLED displej (128 × 64, I2C)** – zobrazuje:
  - aktuálnu nameranú hodnotu,
  - stav systému (normálny stav / alarm).

- **Bzučiak (buzzer)** – slúži ako zvuková signalizácia pri prekročení bezpečnej hranice.

- **Napájanie cez USB** – zabezpečuje napájanie mikrokontroléra ESP32.

---

## 4 Použitý softvér a nástroje

- Arduino IDE – vývojové prostredie pre programovanie ESP32
- Programovací jazyk C/C++ (Arduino)
- IoT platforma Blynk – vzdialené zobrazovanie nameraných hodnôt
- Wi-Fi pripojenie – komunikácia medzi zariadením a cloudom

---

## 5 Princíp fungovania systému

Po zapnutí zariadenia sa mikrokontrolér ESP32 pripojí k Wi-Fi sieti a nadviaže spojenie s IoT platformou Blynk. Následne systém v pravidelných časových intervaloch vykonáva meranie hodnoty zo senzora MQ-2.

Namerané údaje sú:

- spracované pomocou analógovo-digitálneho prevodníka (ADC) mikrokontroléra ESP32,
- zobrazené na OLED displeji,
- odoslané do mobilnej aplikácie Blynk.

Ak nameraná hodnota prekročí nastavenú hraničnú hodnotu, systém automaticky:

- zobrazí varovanie na displeji,
- aktivuje zvukový alarm pomocou bzučiaka.

Meranie prebieha nepretržite a bez blokovania hlavnej slučky programu, čo zabezpečuje plynulý chod systému aj komunikácie s IoT platformou.

---

## 6 Záver

Projekt IoT detektora plynu demonštruje praktické využitie mikrokontroléra ESP32 v oblasti bezpečnostných systémov a internetu vecí. Výsledné riešenie je jednoduché, funkčné a rozšíriteľné, pričom poskytuje základ pre ďalší vývoj, napríklad doplnenie notifikácií, ukladanie dát alebo kalibráciu senzora.
