# Changelog
All notable changes to this project will be documented in this file.

## [Unreleased]
### Added
- Added `isConnected()` to detect hardware disconnections and wiring faults (voltage < 0.5V or > 5.2V).
- Added `readFlowMetersPerSecondAveraged(samples)` for software low-pass filtering to reduce turbulence and ADC noise using non-blocking yield loops.
- Added `calibrateZero()` and `setZeroOffsetVolts()` to compensate for baseline drift or long cable resistance.
