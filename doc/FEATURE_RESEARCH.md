# D6F-W04A1 Feature Research & Roadmap

## 1. Hardware Disconnection Detection
**Status:** Not Implemented
**Description:** The Omron D6F-W04A1 outputs a voltage between 1.0 VDC (0 m/s) and 5.0 VDC (4 m/s). If the sensor is unplugged or the wire breaks, the analog pin will float or read 0V. The current code simply returns `0.0f` for anything outside the bounds, making it impossible to distinguish between "zero air flow" (1.0V) and a "broken cable" (0V).
**Proposed Addition:** Add `bool isConnected()` and `bool hasError()` to check if voltage is abnormally low (< 0.5V) or high (> 5.2V).

## 2. Software Low-Pass Filter (Oversampling)
**Status:** Not Implemented
**Description:** Air flow MEMS sensors are highly sensitive to turbulence, and raw ADC reads pick up electrical noise. This results in erratic flow readings.
**Proposed Addition:** Implement an optional oversampling method `readFlowMetersPerSecondAveraged(uint8_t samples = 10)` to smooth out spikes and provide stable readings.

## 3. Zero-Calibration Offset
**Status:** Not Implemented
**Description:** Manufacturing tolerances or long cable resistances can shift the 1.0V baseline slightly. 
**Proposed Addition:** Add a `setZeroOffsetVolts(float offset)` method or a `calibrateZero()` function that records the current still-air voltage as the new 0 m/s baseline.
