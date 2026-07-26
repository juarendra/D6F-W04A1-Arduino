# D6F-W04A1 Arduino Library

Arduino wrapper for the Omron D6F-W04A1 analog air-flow sensor. It reads the
analog output, restores the sensor-side voltage after any input divider, and
applies the VIA firmware's piecewise 0–4 m/s calibration curve.

## Electrical note

The sensor output can reach 5 V. Do not connect it directly to a 3.3 V ADC.
Use a correctly designed voltage divider or signal-conditioning circuit. Set
`sensorVoltageScale` to the divider ratio (sensor voltage divided by ADC-pin
voltage).

## Example

```cpp
#include <D6FW04A1.h>

// ESP32 ADC at 3.3 V with a 1:2 input divider.
D6FW04A1 airflow(34, 3.3f, 2.0f, 4095);

void setup() { airflow.begin(); }

void loop() {
  float flowMs = airflow.readFlowMetersPerSecond();
}
```

The default calibration returns `0.0` outside the 1.00–5.00 V specified
range. Calibrate the complete sensor and ADC chain for measurements requiring
traceable accuracy.

## License

MIT. See [LICENSE](LICENSE).
