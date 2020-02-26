/**
* First order high-pass filter
* Dimitris Tassopoulos 2016-2020
*
* fc: corner frequency
*/
#pragma once
#include "filter_common.h"

tp_coeffs fo_hpf_calculate_coeffs(int fc, int fs);
F_SIZE fo_hpf_filter(F_SIZE sample);
void fo_hpf_set_offset(F_SIZE offset);
F_SIZE fo_hpf_get_offset(F_SIZE offset);