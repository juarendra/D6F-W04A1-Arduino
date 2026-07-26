#pragma once

#include <Arduino.h>

/** Analog-output driver for the Omron D6F-W04A1 air-flow sensor. */
class D6FW04A1 {
public:
  /**
   * @param pin Analog input pin.
   * @param adcReferenceVolts Voltage represented by the ADC full scale.
   * @param sensorVoltageScale Sensor voltage / ADC-pin voltage (use divider ratio).
   * @param adcMaximum Raw value at ADC full scale, e.g. 4095 for 12 bits.
   */
  D6FW04A1(uint8_t pin, float adcReferenceVolts = 3.3f,
            float sensorVoltageScale = 1.0f, uint16_t adcMaximum = 4095);

  void begin();
  uint16_t readRaw() const;
  float readSensorVoltage() const;
  float readFlowMetersPerSecond() const;

  /** Convert a D6F-W04A1 output voltage to air flow (m/s). */
  static float flowFromVoltage(float sensorVolts);

private:
  uint8_t _pin;
  float _adcReferenceVolts;
  float _sensorVoltageScale;
  uint16_t _adcMaximum;
};
