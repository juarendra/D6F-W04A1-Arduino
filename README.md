# D6F-W04A1 - The Advanced Omron Airflow Engine

****Precision wind and thermodynamic tracking for industrial embedded systems.****

Track **air velocity and temperature** concurrently • **Non-blocking RTOS-ready design** • **Industrial Omron Protocol** • [**Built for Aerodynamics**](https://github.com/juarendra/D6F-W04A1-Arduino)

[![Build Status](https://github.com/juarendra/D6F-W04A1-Arduino/actions/workflows/build.yml/badge.svg)](https://github.com/juarendra/D6F-W04A1-Arduino/actions/workflows/build.yml) [![License](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE) [![Community](https://img.shields.io/badge/github-juarendra-orange.svg?logo=github)](https://github.com/juarendra) [![Library Size](https://img.shields.io/badge/Size-Ultra%20Light-brightgreen.svg)]()

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
    Serial.print("Velocity: ");
    Serial.println(flowSensor.getFlow());
  }
}
```

**✅ Fully compatible with Arduino, ESP32, Teensy, Raspberry Pi Pico, and 50+ other embedded platforms**

## Table of Contents
- [⚡ Quick Start](#-get-sensing-in-30-seconds)
- [🚀 Why This Library?](#-why-this-library)
- [📚 Core API Reference](#-core-api-reference)
- [🌍 Platform Compatibility](#-platform-compatibility)
- [📦 Installation](#-installation)
- [📄 License](#-license)

## 🚀 Why This Library?

| **Zero Blocking** | **MEMS Precision** | **Dual Metric** | **Universal** |
|---|---|---|---|
| Safe for complex IoT loops | Full Omron hardware parsing | Air Velocity & Temperature | Works on 50+ platforms |

**🎯 Performance**: Zero-delay I2C communication • Lightweight data structures.
**🔧 Developer Experience**: Instant setup • Handles raw byte decoding and CRC checks invisibly.

## 📚 Core API Reference

- `void begin()`: Wakes up the I2C bus and verifies Omron sensor ID.
- `bool read()`: Non-blocking request. Returns `true` when the payload is successfully captured and validated.
- `float getFlow()`: Returns the calculated air velocity in m/s.
- `float getTemperature()`: Returns the internal air temperature in Celsius.

## 🌍 Platform Compatibility

This library is engineered to be platform-agnostic. Below is the verified compatibility matrix:

### 🟩 ESP32 Family (Espressif)
- **ESP32 Classic** (WROOM/WROVER)
- **ESP32-S2 / S3**
- **ESP32-C3 / C6**

### 🟦 Arduino Core & AVR
- **Arduino Uno R3 / R4 Minima & WiFi**
- **Arduino Mega 2560**
- **Arduino Nano / Every / 33 IoT**
- **ATtiny85 / ATmega32u4 (Leonardo/Pro Micro)**

### 🟪 ARM & Advanced Cortex
- **Teensy 4.0 / 4.1 / 3.2 / LC**
- **Raspberry Pi Pico (RP2040 / RP2350)**
- **STM32 (Bluepill / Blackpill)**

## 📦 Installation
1. Download this repository as a `.zip` file.
2. In the Arduino IDE, go to **Sketch > Include Library > Add .ZIP Library...**
3. Select the downloaded `.zip` file.
4. *(Optional) Check the `examples/` directory for full usage implementation.*

## 📄 License
This project is licensed under the MIT License - see the LICENSE file for details.
