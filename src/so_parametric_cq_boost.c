#include "so_parametric_cq_boost.h"

static F_SIZE m_xnz1, m_xnz2, m_ynz1, m_ynz2, m_offset = 0;
static tp_coeffs m_coeffs = {0};

tp_coeffs so_parametric_cq_boost_calculate_coeffs(float gain_db, float Q, int fc, int fs)
{
	F_SIZE K = 2.0 * pi * fc / fs;
	F_SIZE V0 = pow(10.0, gain_db / 20.0);
	F_SIZE dd = 1.0 + K/Q + pow(K, 2.0);
	// F_SIZE e = 1.0 + K/(V0*Q) + pow(K, 2.0);
	F_SIZE a = 1.0 + (V0*K)/Q + pow(K, 2.0);
	F_SIZE b = 2.0*(pow(K, 2.0) - 1.0);
	F_SIZE g = 1.0 - (V0*K)/Q + pow(K, 2.0);
	F_SIZE d = 1.0 - K/Q + pow(K, 2.0);
	// F_SIZE h = 1.0 - K / (V0*Q) + pow(K, 2.0);
	m_coeffs.a0 = a/dd;
	m_coeffs.a1 = b/dd;
	m_coeffs.a2 = g/dd;
	m_coeffs.b1 = b/dd;
	m_coeffs.b2 = d/dd;
	m_coeffs.c0 = 1.0;
	m_coeffs.d0 = 0.0;
	return(m_coeffs);
}

F_SIZE so_parametric_cq_boost_filter(F_SIZE sample)
{
	F_SIZE xn = sample;
	// Modified biquad
	F_SIZE ynn = BIQUAD;
	F_SIZE yn = m_coeffs.d0*xn + m_coeffs.c0*ynn;

	SAVE_FILTER_STATE;

	return(yn + m_offset);
}

void so_parametric_cq_boost_set_offset(F_SIZE offset)
{
	m_offset = offset;
}

F_SIZE so_parametric_cq_boost_get_offset(F_SIZE offset)
{
	return(m_offset);
}