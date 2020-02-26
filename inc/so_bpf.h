/**
* Second order band-pass filter
* Dimitris Tassopoulos 2016-2020
*
* fc: corner frequency
* Q: quality factor controlling width of peak or notch = 1/BW
*/
#pragma once
#include "filter_common.h"

tp_coeffs so_bpf_calculate_coeffs(float Q, int fc, int fs);
F_SIZE so_bpf_filter(F_SIZE sample);
void so_bpf_set_offset(F_SIZE offset);
F_SIZE so_bpf_get_offset(F_SIZE offset);