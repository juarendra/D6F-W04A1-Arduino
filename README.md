# D6F-W04A1 Arduino Library

Robust non-blocking Arduino library for the Omron D6F-W04A1 MEMS air flow sensor.

## 🚀 Key Features & Upgrades
- **Non-Blocking Operations**: Eliminates blocking delays using `yield()`, maintaining high responsiveness in complex IoT setups.
- Direct I2C interfacing for air velocity and temperature.

## 📖 Usage Manual

```cpp
#include <D6F_W04A1.h>

D6F_W04A1 flowSensor;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  flowSensor.begin(); 
}

void loop() {
  if (flowSensor.read()) {
    Serial.print("Flow: ");
    Serial.println(flowSensor.getFlow());
  }
}
```

## 🛠 Installation
1. Download this repository as a `.zip` file.
2. In the Arduino IDE, go to **Sketch > Include Library > Add .ZIP Library...**
3. Select the downloaded `.zip` file.

## 📄 License
MIT License.
