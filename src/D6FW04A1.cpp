#include "D6FW04A1.h"

D6FW04A1::D6FW04A1(uint8_t pin, float adcReferenceVolts,
                     float sensorVoltageScale, uint16_t adcMaximum)
    : _pin(pin), _adcReferenceVolts(adcReferenceVolts),
      _sensorVoltageScale(sensorVoltageScale), _adcMaximum(adcMaximum) {}

void D6FW04A1::begin() {
  pinMode(_pin, INPUT);
}

uint16_t D6FW04A1::readRaw() const {
  return static_cast<uint16_t>(analogRead(_pin));
}

float D6FW04A1::readSensorVoltage() const {
  if (_adcMaximum == 0) return 0.0f;
  return (readRaw() * _adcReferenceVolts / _adcMaximum) * _sensorVoltageScale;
}

float D6FW04A1::readFlowMetersPerSecond() const {
  return flowFromVoltage(readSensorVoltage());
}

float D6FW04A1::flowFromVoltage(float volts) {
  if (volts >= 1.00f && volts <= 1.58f) return (volts - 1.0f) / 0.58f;
  if (volts > 1.58f && volts <= 2.88f) return ((volts - 1.58f) / 1.30f) + 1.0f;
  if (volts > 2.88f && volts <= 4.11f) return ((volts - 2.88f) / 1.23f) + 2.0f;
  if (volts > 4.11f && volts <= 5.00f) return ((volts - 4.11f) / 0.89f) + 3.0f;
  return 0.0f;
}
