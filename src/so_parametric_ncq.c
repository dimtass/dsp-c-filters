#include "so_parametric_ncq.h"

static F_SIZE m_xnz1, m_xnz2, m_ynz1, m_ynz2, m_offset = 0;
static tp_coeffs m_coeffs = {0};

tp_coeffs so_parametric_ncq_calculate_coeffs(float gain_db, float Q, int fc, int fs)
{
	F_SIZE w = 2.0 * pi * fc / fs;
	F_SIZE m = pow(10.0, gain_db / 20.0);
	F_SIZE z = 4.0 / (1.0 + m);
	F_SIZE b = 0.5 * ((1.0 - z*tan(w / (2.0*Q)) / (1 + z*tan(w / (2.0*Q)))));
	F_SIZE g = (0.5 + b) * cos(w);
	m_coeffs.a0 = 0.5 - b;
	m_coeffs.a1 = 0.0;
	m_coeffs.a2 = -(0.5 - b);
	m_coeffs.b1 = -2.0*g;
	m_coeffs.b2 = 2.0 * b;
	m_coeffs.c0 = m - 1.0;
	m_coeffs.d0 = 1.0;
	return(m_coeffs);
}

F_SIZE so_parametric_ncq_filter(F_SIZE sample)
{
	F_SIZE xn = sample;
	F_SIZE ynn = BIQUAD;
	F_SIZE yn = m_coeffs.d0*xn + m_coeffs.c0*ynn;

	SAVE_FILTER_STATE;

	return(yn + m_offset);
}

void so_parametric_ncq_set_offset(F_SIZE offset)
{
	m_offset = offset;
}

F_SIZE so_parametric_ncq_get_offset(F_SIZE offset)
{
	return(m_offset);
}