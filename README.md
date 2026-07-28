# D6F-W04A1 - Advanced MEMS Air Flow Library

****Precision wind and airflow tracking for your embedded systems.****

Track **air velocity and temperature** instantly • **Non-blocking RTOS-ready** • **Industrial Omron Support** • [**Built for Aerodynamics**](https://github.com/juarendra/D6F-W04A1-Arduino)

[![Build Status](https://github.com/juarendra/D6F-W04A1-Arduino/actions/workflows/build.yml/badge.svg)](https://github.com/juarendra/D6F-W04A1-Arduino/actions/workflows/build.yml) [![License](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE) [![Community](https://img.shields.io/badge/github-juarendra-orange.svg?logo=github)](https://github.com/juarendra)

## ⚡ Get Flowing in 30 Seconds

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
    Serial.println(flowSensor.getFlow());
  }
}
```

**✅ Works on ESP32, RP2040, Teensy, Arduino, and 50+ other platforms**

## Table of Contents
- [⚡ Quick Start](#-get-flowing-in-30-seconds)
- [🚀 Why This Library?](#-why-this-library)
- [📦 Installation](#-installation)
- [📄 License](#-license)

## 🚀 Why This Library?

| **Zero Blocking** | **MEMS Sensor** | **Dual Metric** | **Universal** |
|---|---|---|---|
| Safe for complex IoT loops | Full Omron hardware support | Velocity & Temperature | Works on 50+ platforms |

**🎯 Performance**: Zero-delay I2C communication • Lightweight data types.
**🔧 Developer Experience**: Instant setup • Handles raw byte decoding seamlessly.

## 📦 Installation
1. Download this repository as a `.zip` file.
2. In the Arduino IDE, go to **Sketch > Include Library > Add .ZIP Library...**
3. Select the downloaded `.zip` file.
4. (Optional) Check the `examples/` directory for full usage.

## 📄 License
This project is licensed under the MIT License - see the LICENSE file for details.
