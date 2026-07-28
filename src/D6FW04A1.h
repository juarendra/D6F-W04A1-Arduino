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

  /** Convert flow velocity to volumetric flow rate (Liters per Minute) based on duct area. */
  float readVolumetricFlowLitersPerMinute(float crossSectionalAreaCm2) const;

  /** Return an averaged flow rate over N samples (software low-pass filter). */
  float readFlowMetersPerSecondAveraged(uint8_t samples = 10) const;

  /** Check if the sensor is physically connected and producing a valid baseline voltage (>0.5V). */
  bool isConnected() const;

  /** Set a calibration offset for the 1.0V baseline (zero-flow). */
  void setZeroOffsetVolts(float offset);

  /** Automatically calibrate the zero offset. Run only when the sensor is in completely still air. */
  void calibrateZero(uint8_t samples = 20);

  /** Convert a D6F-W04A1 output voltage to air flow (m/s). */
  static float flowFromVoltage(float sensorVolts);

private:
  uint8_t _pin;
  float _adcReferenceVolts;
  float _sensorVoltageScale;
  uint16_t _adcMaximum;
  float _zeroOffsetVolts;
};
