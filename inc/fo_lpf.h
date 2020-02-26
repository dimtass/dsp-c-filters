/**
* First order low-pass filter
* Dimitris Tassopoulos 2016-2020
*
* fc: corner frequency
*/
#pragma once
#include "filter_common.h"

tp_coeffs fo_lpf_calculate_coeffs(int fc, int fs);
F_SIZE fo_lpf_filter(F_SIZE sample);
void fo_lpf_set_offset(F_SIZE offset);
F_SIZE fo_lpf_get_offset(F_SIZE offset);