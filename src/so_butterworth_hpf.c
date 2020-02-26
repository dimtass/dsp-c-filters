#include "so_butterworth_hpf.h"

static F_SIZE m_xnz1, m_xnz2, m_ynz1, m_ynz2, m_offset = 0;
static tp_coeffs m_coeffs = {0};

tp_coeffs so_butterworth_hpf_calculate_coeffs(int fc, int fs)
{
	F_SIZE c = tanf(pi*fc / fs);
	m_coeffs.a0 = 1.0 / (1.0 + sqrt2*c + powf(c, 2.0));
	m_coeffs.a1 = -2.0 * m_coeffs.a0;
	m_coeffs.a2 = m_coeffs.a0;
	m_coeffs.b1 = 2.0 * m_coeffs.a0*(powf(c, 2.0) - 1.0);
	m_coeffs.b2 = m_coeffs.a0 * (1.0 - sqrt2*c + powf(c, 2.0));
	return(m_coeffs);
}
F_SIZE so_butterworth_hpf_filter(F_SIZE sample)
{
	F_SIZE xn = sample;
	F_SIZE yn = BIQUAD;

	SAVE_FILTER_STATE;

	return(yn + m_offset);
}

void so_butterworth_hpf_set_offset(F_SIZE offset)
{
	m_offset = offset;
}

F_SIZE so_butterworth_hpf_get_offset(F_SIZE offset)
{
	return(m_offset);
}
