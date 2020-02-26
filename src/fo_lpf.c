#include "fo_lpf.h"

static F_SIZE m_xnz1, m_xnz2, m_ynz1, m_ynz2, m_offset = 0;
static tp_coeffs m_coeffs = {0};

tp_coeffs fo_lpf_calculate_coeffs(int fc, int fs)
{
	F_SIZE th = 2.0 * pi * fc / fs;
	F_SIZE g = cos(th) / (1.0 + sin(th));
	m_coeffs.a0 = (1.0 - g) / 2.0;
	m_coeffs.a1 = (1.0 - g) / 2.0;
	m_coeffs.a2 = 0.0;
	m_coeffs.b1 = -g;
	m_coeffs.b2 = 0.0;
	return(m_coeffs);
}

F_SIZE fo_lpf_filter(F_SIZE sample)
{
	F_SIZE xn = sample;
	F_SIZE yn = BIQUAD;
	SAVE_FILTER_STATE;
	
	return(yn + m_offset);
}

void fo_lpf_set_offset(F_SIZE offset)
{
	m_offset = offset;
}

F_SIZE fo_lpf_get_offset(F_SIZE offset)
{
	return(m_offset);
}