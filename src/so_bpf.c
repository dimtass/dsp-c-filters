#include "so_bpf.h"

static F_SIZE m_xnz1, m_xnz2, m_ynz1, m_ynz2, m_offset = 0;
static tp_coeffs m_coeffs = {0};

tp_coeffs so_bpf_calculate_coeffs(float Q, int fc, int fs)
{
	F_SIZE w = 2.0 * pi * fc / fs;
	F_SIZE b = 0.5*((1.0 - tan(w / (2.0*Q))) / (1.0 + tan(w / (2.0*Q))));
	F_SIZE g = (0.5 + b)*cos(w);
	m_coeffs.a0 = 0.5 - b;
	m_coeffs.a1 = 0.0;
	m_coeffs.a2 = -(0.5 - b);
	m_coeffs.b1 = -2.0 * g;
	m_coeffs.b2 = 2.0 * b;
	return(m_coeffs);
}

F_SIZE so_bpf_filter(F_SIZE sample)
{
	F_SIZE xn = sample;
	F_SIZE yn = BIQUAD;

	SAVE_FILTER_STATE;

	return(yn + m_offset);
}

void so_bpf_set_offset(F_SIZE offset)
{
	m_offset = offset;
}

F_SIZE so_bpf_get_offset(F_SIZE offset)
{
	return(m_offset);
}