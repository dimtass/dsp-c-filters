#include "fo_apf.h"

static F_SIZE m_xnz1, m_xnz2, m_ynz1, m_ynz2, m_offset = 0;
static tp_coeffs m_coeffs = {0};

tp_coeffs fo_apf_calculate_coeffs(int fc, int fs)
{
	F_SIZE a = (tan(pi*fc / fs) - 1.0) / (tan(pi*fc / fs) + 1.0);
	m_coeffs.a0 = a;
	m_coeffs.a1 = 1.0;
	m_coeffs.a2 = 0.0;
	m_coeffs.b1 = a;
	m_coeffs.b2 = 0.0;
	return(m_coeffs);
}

F_SIZE fo_apf_filter(F_SIZE sample)
{
	F_SIZE xn = sample;
	F_SIZE yn = BIQUAD;
	SAVE_FILTER_STATE;

	return(yn+m_offset);
}

void fo_apf_set_offset(F_SIZE offset)
{
	m_offset = offset;
}

F_SIZE fo_apf_get_offset(F_SIZE offset)
{
	return(m_offset);
}