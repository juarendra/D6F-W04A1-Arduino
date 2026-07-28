#include "D6FW04A1.h"

D6FW04A1::D6FW04A1(uint8_t pin, float adcReferenceVolts,
                     float sensorVoltageScale, uint16_t adcMaximum)
    : _pin(pin), _adcReferenceVolts(adcReferenceVolts),
      _sensorVoltageScale(sensorVoltageScale), _adcMaximum(adcMaximum),
      _zeroOffsetVolts(0.0f) {}

void D6FW04A1::begin() {
  pinMode(_pin, INPUT);
}

uint16_t D6FW04A1::readRaw() const {
  return static_cast<uint16_t>(analogRead(_pin));
}

float D6FW04A1::readSensorVoltage() const {
  if (_adcMaximum == 0) return 0.0f;
  float rawVolts = (readRaw() * _adcReferenceVolts / _adcMaximum) * _sensorVoltageScale;
  return rawVolts - _zeroOffsetVolts;
}

bool D6FW04A1::isConnected() const {
  if (_adcMaximum == 0) return false;
  float rawVolts = (readRaw() * _adcReferenceVolts / _adcMaximum) * _sensorVoltageScale;
  return (rawVolts > 0.5f && rawVolts < 5.2f);
}

float D6FW04A1::readFlowMetersPerSecond() const {
  return flowFromVoltage(readSensorVoltage());
}

float D6FW04A1::readVolumetricFlowLitersPerMinute(float crossSectionalAreaCm2) const {
  float velocity = readFlowMetersPerSecond();
  // Q (L/min) = v (m/s) * A (cm^2) * 6
  return velocity * crossSectionalAreaCm2 * 6.0f;
}

float D6FW04A1::readFlowMetersPerSecondAveraged(uint8_t samples) const {
  if (samples == 0) samples = 1;
  float sum = 0.0f;
  for (uint8_t i = 0; i < samples; ++i) {
    sum += readFlowMetersPerSecond();
    uint32_t start = millis();
    while (millis() - start < 2) { yield(); } // Non-blocking delay
  }
  return sum / static_cast<float>(samples);
}

void D6FW04A1::setZeroOffsetVolts(float offset) {
  _zeroOffsetVolts = offset;
}

void D6FW04A1::calibrateZero(uint8_t samples) {
  if (samples == 0) samples = 1;
  _zeroOffsetVolts = 0.0f; // Reset before measuring
  float sumVolts = 0.0f;
  for (uint8_t i = 0; i < samples; ++i) {
    sumVolts += readSensorVoltage();
    uint32_t start = millis();
    while (millis() - start < 5) { yield(); } // Non-blocking delay
  }
  float averageVolts = sumVolts / static_cast<float>(samples);
  // Normal baseline in still air is 1.0V
  _zeroOffsetVolts = averageVolts - 1.0f;
}

float D6FW04A1::flowFromVoltage(float volts) {
  if (volts >= 1.00f && volts <= 1.58f) return (volts - 1.0f) / 0.58f;
  if (volts > 1.58f && volts <= 2.88f) return ((volts - 1.58f) / 1.30f) + 1.0f;
  if (volts > 2.88f && volts <= 4.11f) return ((volts - 2.88f) / 1.23f) + 2.0f;
  if (volts > 4.11f && volts <= 5.00f) return ((volts - 4.11f) / 0.89f) + 3.0f;
  return 0.0f;
}
