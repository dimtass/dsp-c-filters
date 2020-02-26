/**
* Second order Butterworth band-stop filter
* Dimitris Tassopoulos 2016-2020
*
* fc: corner frequency
* bw: bandwidth of peak/notch = fc/Q
*
* Butterworth BPF and BSF are made by cascading (BPF) or paralleling (BSF) a Butterworth
* LPF and Butterworth HPF.
*/
#pragma once
#include "filter_common.h"

tp_coeffs so_butterworth_bsf_calculate_coeffs(float bw, int fc, int fs);
F_SIZE so_butterworth_bsf_filter(F_SIZE sample);
void so_butterworth_bsf_set_offset(F_SIZE offset);
F_SIZE so_butterworth_bsf_get_offset(F_SIZE offset);