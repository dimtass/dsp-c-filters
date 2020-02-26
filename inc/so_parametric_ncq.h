/**
* Second order parametric/peaking filter with non-constant-Q
* Dimitris Tassopoulos 2016-2020
*
* fc: center frequency
* Q: quality factor
* Gain/attenuation in dB
* 
* Parametric EQs allow you to adjust the center frequency, Q and boost or cut creating any
* arbitrary bumps or notches in the frequency response. The parametric EQ is a
* variation on the ordinary band-pass and band-stop fi lters that generates symmetrical boost/
* cut curves and mixes in the dry signal to create the fi nal response. A true digital parametric
* EQ not only has independent controls, but each control only varies one coeffi cient in the
* fi lter. The parametric EQs in this section afford the same frequency response but adjustments
* in any parameter require a recalculation of all the coeffi cients. These filters are also called
* peaking fi lters.
* This parametric EQ is not constant-Q, which means the bandwidth varies depending on the
* boost/cut value. Some analog fi lters have the same issue, although there is occasional debate
* over whether or not this is desirable in an EQ design.
*/
#pragma once
#include "filter_common.h"

tp_coeffs so_parametric_ncq_calculate_coeffs(float gain_db, float Q, int fc, int fs);
F_SIZE so_parametric_ncq_filter(F_SIZE sample);
void so_parametric_ncq_set_offset(F_SIZE offset);
F_SIZE so_parametric_ncq_get_offset(F_SIZE offset);