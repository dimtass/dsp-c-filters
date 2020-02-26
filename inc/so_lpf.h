/**
* Second order Low-pass filter
* Dimitris Tassopoulos 2016-2020
*
* fc , corner frequency
* Q , quality factor controlling resonant peaking
*/

#pragma once
#include "filter_common.h"

tp_coeffs so_lpf_calculate_coeffs(float Q, int fc, int fs);
F_SIZE so_lpf_filter(F_SIZE sample);
void so_apf_set_offset(F_SIZE offset);
F_SIZE so_apf_get_offset(F_SIZE offset);