#include "so_hpf.h"

static F_SIZE m_xnz1, m_xnz2, m_ynz1, m_ynz2, m_offset = 0;
static tp_coeffs m_coeffs = {0};

tp_coeffs so_hpf_calculate_coeffs(float Q, int fc, int fs)
{
	F_SIZE w = 2.0 * pi * fc / fs;
	F_SIZE d = 1.0 / Q;
	F_SIZE b = 0.5*(1.0 - (d / 2)*sin(w)) / (1.0 + (d / 2.0)*sin(w));
	F_SIZE g = (0.5 + b)*cos(w);
	m_coeffs.a0 = (0.5 + b + g) / 2.0;
	m_coeffs.a1 = -(0.5 + b + g);
	m_coeffs.a2 = m_coeffs.a0;
	m_coeffs.b1 = -2.0 * g;
	m_coeffs.b2 = 2.0 * b;
	return(m_coeffs);
}

F_SIZE so_hpf_filter(F_SIZE sample)
{
	F_SIZE xn = sample;
	F_SIZE yn = BIQUAD;

	SAVE_FILTER_STATE;

	return(yn + m_offset);
}

void so_hpf_set_offset(F_SIZE offset)
{
	m_offset = offset;
}

F_SIZE so_hpf_get_offset(F_SIZE offset)
{
	return(m_offset);
}