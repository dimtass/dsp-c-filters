#include "fo_shelving_low.h"

static F_SIZE m_xnz1, m_xnz2, m_ynz1, m_ynz2, m_offset = 0;
static tp_coeffs m_coeffs = {0};

tp_coeffs fo_shelving_low_calculate_coeffs(float gain_db, int fc, int fs)
{
	F_SIZE th = 2.0 * pi * fc / fs;
	F_SIZE m = pow(10.0, gain_db / 20.0);
	F_SIZE b = 4.0 / (1.0 + m);
	F_SIZE d = b * tan(th / 2.0);
	F_SIZE g = (1.0 - d) / (1.0 + d);
	m_coeffs.a0 = (1.0 - g) / 2.0;
	m_coeffs.a1 = (1.0 - g) / 2.0;
	m_coeffs.a2 = 0.0;
	m_coeffs.b1 = -g;
	m_coeffs.b2 = 0.0;
	m_coeffs.c0 = m - 1.0;
	m_coeffs.d0 = 1.0;
	return(m_coeffs);
}

F_SIZE fo_shelving_low_filter(F_SIZE sample)
{
	F_SIZE xn = sample;
	F_SIZE ynn = BIQUAD;
	F_SIZE yn = m_coeffs.d0*xn + m_coeffs.c0*ynn;

	SAVE_FILTER_STATE;

	return(yn + m_offset);
}

void fo_shelving_low_set_offset(F_SIZE offset)
{
	m_offset = offset;
}

F_SIZE fo_shelving_low_get_offset(F_SIZE offset)
{
	return(m_offset);
}