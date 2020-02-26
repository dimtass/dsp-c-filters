/**
* Second order high-pass filter
* Dimitris Tassopoulos 2016-2020
* 
* fc: corner frequency
* Q: quality factor controlling resonant peaking
*/
#pragma once
#include "filter_common.h"

tp_coeffs so_hpf_calculate_coeffs(float Q, int fc, int fs);
F_SIZE so_hpf_filter(F_SIZE sample);
void so_hpf_set_offset(F_SIZE offset);
F_SIZE so_hpf_get_offset(F_SIZE offset);