#ifndef ENERGY_H
#define ENERGY_H

struct ENERGY {
  float voltage[3] = { 0, 0, 0 };               // 123.1 V
  float current[3] = { 0, 0, 0 };               // 123.123 A
  float active_power[3] = { 0, 0, 0 };          // 123.1 W
  float apparent_power[3] = { NAN, NAN, NAN };  // 123.1 VA
  float reactive_power[3] = { NAN, NAN, NAN };  // 123.1 VAr
  float power_factor[3] = { NAN, NAN, NAN };    // 0.12
  float frequency[3] = { NAN, NAN, NAN };       // 123.1 Hz

  float start_energy = 0;                       // 12345.12345 kWh total previous
  float daily = 0;                              // 123.123 kWh
  float total = 0;                              // 12345.12345 kWh total energy
  float export_active = NAN;                    // 123.123 KWh

  unsigned long kWhtoday_delta = 0;             // 1212312345 Wh 10^-5 (deca micro Watt hours) - Overflows to Energy.kWhtoday (HLW and CSE only)
  unsigned long kWhtoday_offset = 0;            // 12312312 Wh * 10^-2 (deca milli Watt hours) - 5764 = 0.05764 kWh = 0.058 kWh = Energy.daily
  unsigned long kWhtoday;                       // 12312312 Wh * 10^-2 (deca milli Watt hours) - 5764 = 0.05764 kWh = 0.058 kWh = Energy.daily
  unsigned long period = 0;                     // 12312312 Wh * 10^-2 (deca milli Watt hours) - 5764 = 0.05764 kWh = 0.058 kWh = Energy.daily

  uint8_t fifth_second = 0;
  uint8_t command_code = 0;
  uint8_t data_valid[3] = { 0, 0, 0 };

  uint8_t phase_count = 1;                      // Number of phases active
  bool voltage_common = false;                  // Use single voltage and frequency

  bool voltage_available = true;                // Enable if voltage is measured
  bool current_available = true;                // Enable if current is measured

  bool type_dc = false;
  bool power_on = true;

#ifdef USE_ENERGY_MARGIN_DETECTION
  uint16_t power_history[3] = { 0 };
  uint8_t power_steady_counter = 8;  // Allow for power on stabilization
  bool power_delta = false;
  bool min_power_flag = false;
  bool max_power_flag = false;
  bool min_voltage_flag = false;
  bool max_voltage_flag = false;
  bool min_current_flag = false;
  bool max_current_flag = false;

#ifdef USE_ENERGY_POWER_LIMIT
  uint16_t mplh_counter = 0;
  uint16_t mplw_counter = 0;
  uint8_t mplr_counter = 0;
  uint8_t max_energy_state  = 0;
#endif  // USE_ENERGY_POWER_LIMIT
#endif  // USE_ENERGY_MARGIN_DETECTION
};
struct ENERGY Energy;
#endif
