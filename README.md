# IoT-Based Weather Monitoring System with Automated Rain Response 🌦️

This project is an **IoT-enabled weather monitoring system** built using **ESP8266**, featuring real-time tracking of **temperature, humidity, atmospheric pressure, and rain levels**. It automates **clothes rope retraction and extension** based on rainfall detection, ensuring protection against unexpected weather changes.  

## 🚀 Features
- **Live Weather Monitoring:** Displays real-time sensor data via a **web interface**
- **Automated Rain Response:** **Retracts clothes rope** when rain exceeds **30%**, and **extends** it when conditions are dry
- **Buzzer Alert System:** Sounds an alarm for extreme conditions **(Heat > 40°C, Rain > 30%)**
- **WiFi-enabled Monitoring:** Accessible via a **web dashboard**
- **Remote Access:** View weather data from anywhere on your network

---

## 📷 Web Interface Display  
This project features a **custom web page dashboard** for **live sensor data monitoring**:  

### 🌍 Web Page - Real-Time Weather Detection  
![Web Dashboard - Metrics]! [WhatsApp Image 2025-05-20 at 11 05 32_f73fe2a4](https://github.com/user-attachments/assets/813281a6-96b3-4b06-a713-8994c7f76d10)

*Figure 1: Displays rainfall percentage, atmospheric pressure, temperature and  humidity *

![Web Dashboard - Rain Alert]! [WhatsApp Image 2025-05-20 at 11 12 00_b3441353](https://github.com/user-attachments/assets/59285240-30f9-474b-959f-f5cc9c63b227)

*Figure 2: Pop-up notification for heavy rain alert at 72% threshold.*

**Features:**  
- **Displays temperature, humidity, rain percentage, and pressure readings**  
- **Provides warnings for extreme heat (>40°C) and rain (>30%)**  
- **Dynamic UI updates every 2 seconds**  

---

## 🎥 Servo Motor Demonstration  
The servo motor **retracts and extends the clothes rope** based on detected rain levels:  

▶️ **[Watch Demo Video] https://github.com/user-attachments/assets/e840e166-5a72-4e65-9280-7f1b3952da6a**  


---

## 🛠️ Hardware Requirements  
- **ESP8266 NodeMCU**  
- **Sensors:**  
  - **BMP280** (Pressure sensor)  
  - **DHT11/DHT22** (Temperature & Humidity sensor)  
  - **Rain Sensor** (Analog input for rainfall detection)  
- **Actuators:**  
  - **Servo Motor** (Controls clothes rope retraction and extension)  
  - **Buzzer** (Alerts for extreme weather)  
- **Miscellaneous:**  
  - Breadboard & jumper wires  
  - 5V Power supply  

---

## 💻 Software Requirements  
- **Arduino IDE** (For programming ESP8266)  
- **ESP8266 Libraries:**  
  - `ESP8266WiFi`  
  - `ESP8266WebServer`  
  - `Wire`  
  - `Adafruit BMP280`  
  - `DHTesp`  
  - `Servo`  
- **Web Interface:** HTML & CSS for real-time weather dashboard  

---

## 🔌 Pin Configuration  
| Component       | ESP8266 Pin |
|---------------|------------|
| **DHT11 Sensor** | D5 (GPIO14) |
| **Rain Sensor** | A0 (Analog Input) |
| **BMP280 Sensor (SDA, SCL)** | D2 (SDA) / D1 (SCL) |
| **Servo Motor** | D7 (GPIO13) |
| **Buzzer** | D6 (GPIO12) |
| **LED Indicator** | GPIO2 (Onboard LED) |

---

## 🔧 Wiring Instructions  
1️⃣ **Connect BMP280** → SDA to D2, SCL to D1  
2️⃣ **Connect DHT11** → Data to D5  
3️⃣ **Rain Sensor** → Analog A0  
4️⃣ **Servo Motor** → Control pin to D7  
5️⃣ **Buzzer** → Control pin to D6  
6️⃣ **Onboard LED** → GPIO2  

---

## 🌧️ Automated Rain Response  
- **Rain Detection:** The system **retracts the clothes rope** when rain percentage **exceeds 30%** to prevent clothes from getting wet.  
- **Dry Weather:** When rain percentage **drops below 30%**, the servo **extends the rope**, allowing clothes to dry under natural sunlight.  
- **Buzzer Alert:** Sounds an **audible warning** when rain levels exceed the threshold.  

---

## 🚀 Installation & Setup  
1️⃣ Install **Arduino IDE** & required ESP8266 libraries  
2️⃣ Flash `weather_station.ino` to ESP8266  
3️⃣ Configure **WiFi credentials** in the code  
4️⃣ Open **Web Interface** at `ESP8266_IP`  
5️⃣ Monitor **live weather data & automated responses**  

---

## 🎯 Usage  
- **Rain Detection:** System **retracts the clothes rope** when rain percentage crosses **30%**  
- **Sunny Weather:** When rain levels drop, the **servo extends the rope** for clothes drying  
- **Extreme Heat Detection:** **Buzzer alarm** triggers if temperature exceeds **40°C**  
- **Web Interface:** Access **live weather data** in your browser  
- **Alerts & Notifications:** Real-time warnings for weather conditions  

---

## 📜 License  
This project is licensed under **MIT License**. See [LICENSE](LICENSE) for details.  

---

## 🙌 Acknowledgments  
- Built using **ESP8266 Web Server**  
- Leveraging **IoT-based environmental monitoring systems**  
