/**
* Second order band-stop filter
* Dimitris Tassopoulos 2016-2020
*
* fc: corner frequency
* Q: quality factor controlling width of peak or notch = 1/BW
*/
#pragma once
#include "filter_common.h"

tp_coeffs so_bsf_calculate_coeffs(float Q, int fc, int fs);
F_SIZE so_bsf_filter(F_SIZE sample);
void so_bsf_set_offset(F_SIZE offset);
F_SIZE so_bsf_get_offset(F_SIZE offset);