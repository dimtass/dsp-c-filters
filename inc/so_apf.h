/**
* Second order all-pass filter
* Dimitris Tassopoulos 2016-2020
*
* fc: corner frequency
* Q: steepness of phase shift at fc (second-order only)
*/
#pragma once
#include "filter_common.h"

tp_coeffs so_apf_calculate_coeffs(float Q, int fs);
F_SIZE so_apf_filter(F_SIZE sample);
void so_apf_set_offset(F_SIZE offset);
F_SIZE so_apf_get_offset(F_SIZE offset);