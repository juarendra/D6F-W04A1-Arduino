#include <D6FW04A1.h>

constexpr uint8_t D6F_PIN = 34;
// With a 5 V output sensor on a 3.3 V ESP32 ADC, use a suitable divider.
// For a 1:2 divider, sensorVoltageScale is 2.0f.
D6FW04A1 airflow(D6F_PIN, 3.3f, 2.0f, 4095);

void setup() {
  Serial.begin(115200);
  airflow.begin();
}

void loop() {
  Serial.print("Sensor voltage: ");
  Serial.print(airflow.readSensorVoltage(), 3);
  Serial.print(" V, flow: ");
  Serial.print(airflow.readFlowMetersPerSecond(), 2);
  Serial.println(" m/s");
  delay(1000);
}
