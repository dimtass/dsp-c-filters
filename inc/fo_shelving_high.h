/**
* First order high-shelving filter
* Dimitris Tassopoulos 2016-2020
*
* fc: high shelf frequency
* gain_db: Low-frequency gain/attenuation in dB
*
* Shelving filters are used in many tone controls, especially when there are only two, bass
* and treble, which are almost always implemented as shelf types. The filters have a corner
* frequency and gain or attenuation value.
*/
#pragma once
#include "filter_common.h"

tp_coeffs fo_shelving_high_calculate_coeffs(float gain_db, int fc, int fs);
F_SIZE fo_shelving_high_filter(F_SIZE sample);
void fo_shelving_high_set_offset(F_SIZE offset);
F_SIZE fo_shelving_high_get_offset(F_SIZE offset);