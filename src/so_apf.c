#include "so_apf.h"

static F_SIZE m_xnz1, m_xnz2, m_ynz1, m_ynz2, m_offset = 0;
static tp_coeffs m_coeffs = {0};

tp_coeffs so_apf_calculate_coeffs(float Q, int fs)
{
	F_SIZE a = (tan(pi*Q / fs) - 1.0) / (tan(pi*Q / fs) + 1.0);
	F_SIZE b = -cos(pi*Q / fs);
	m_coeffs.a0 = -a;
	m_coeffs.a1 = b*(1.0 - a);
	m_coeffs.a2 = 1.0;
	m_coeffs.b1 = m_coeffs.a1;
	m_coeffs.b2 = m_coeffs.a0;
	return(m_coeffs);
}

F_SIZE so_apf_filter(F_SIZE sample)
{
	F_SIZE xn = sample;
	F_SIZE yn = BIQUAD;

	SAVE_FILTER_STATE;

	return(yn + m_offset);
}

void so_apf_set_offset(F_SIZE offset)
{
	m_offset = offset;
}

F_SIZE so_apf_get_offset(F_SIZE offset)
{
	return(m_offset);
}