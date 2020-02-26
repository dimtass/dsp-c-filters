/**
* Second order Butterworth high-pass filter
* Dimitris Tassopoulos 2016-2020
*
* fc: corner frequency
*
* Butterworth low-pass and high-pass filters are specialized versions of the ordinary secondorder
* low-pass filter. Their Q values are fixed at 0.707, which is the largest value it can
* assume before peaking in the frequency response is observed.
*/
#pragma once
#include "filter_common.h"

tp_coeffs so_butterworth_hpf_calculate_coeffs(int fc, int fs);
F_SIZE so_butterworth_hpf_filter(F_SIZE sample);
void so_butterworth_hpf_set_offset(F_SIZE offset);
F_SIZE so_butterworth_hpf_get_offset(F_SIZE offset);