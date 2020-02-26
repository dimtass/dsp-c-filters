#include "so_linkwitz_riley_hpf.h"

static F_SIZE m_xnz1, m_xnz2, m_ynz1, m_ynz2, m_offset = 0;
static tp_coeffs m_coeffs = {0};

tp_coeffs so_linkwitz_riley_hpf_calculate_coeffs(int fc, int fs)
{
	F_SIZE th = pi * fc / fs;
	F_SIZE Wc = pi * fc;
	F_SIZE k = Wc / tan(th);

	F_SIZE d = pow(k, 2.0) + pow(Wc, 2.0) + 2.0 * k * Wc;
	m_coeffs.a0 = pow(k, 2.0) / d;
	m_coeffs.a1 = -2.0 * pow(k, 2.0) / d;
	m_coeffs.a2 = m_coeffs.a0;
	m_coeffs.b1 = (-2.0 * pow(k, 2.0) + 2.0 * pow(Wc, 2.0)) / d;
	m_coeffs.b2 = (-2.0 * k * Wc + pow(k, 2.0) + pow(Wc, 2.0)) / d;
	return(m_coeffs);
}

F_SIZE so_linkwitz_riley_hpf_filter(F_SIZE sample)
{
	F_SIZE xn = sample;
	F_SIZE yn = BIQUAD;

	SAVE_FILTER_STATE;

	return(yn + m_offset);
}

void so_linkwitz_riley_hpf_set_offset(F_SIZE offset)
{
	m_offset = offset;
}

F_SIZE so_linkwitz_riley_hpf_get_offset(F_SIZE offset)
{
	return(m_offset);
}