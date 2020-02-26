#include "so_lpf.h"

static F_SIZE m_xnz1, m_xnz2, m_ynz1, m_ynz2, m_offset = 0;
static tp_coeffs m_coeffs = {0};

tp_coeffs so_lpf_calculate_coeffs(float Q, int fc, int fs)
{
	F_SIZE w = 2.0 * pi * fc / fs;
	F_SIZE d = 1.0 / Q;
	F_SIZE b = 0.5*(1.0 - (d / 2)*arm_sin_f32(w)) / (1.0 + (d / 2.0)*arm_sin_f32(w));
	F_SIZE g = (0.5 + b)*arm_cos_f32(w);
	m_coeffs.a0 = (0.5 + b - g) / 2.0;
	m_coeffs.a1 = 0.5 + b - g;
	m_coeffs.a2 = m_coeffs.a0;
	m_coeffs.b1 = -2.0 * g;
	m_coeffs.b2 = 2.0 * b;
	return(m_coeffs);
}

F_SIZE so_lpf_filter(F_SIZE sample)
{
	F_SIZE xn = sample;
	
#ifdef USE_FPU
	F_SIZE A[] = {m_coeffs.a0, m_coeffs.a1, m_coeffs.a2, -m_coeffs.b1, -m_coeffs.b2};
	F_SIZE B[] = {xn, m_xnz1, m_xnz2, m_ynz1, m_xnz2};
	F_SIZE yn = 0;
	arm_dot_prod_f32((F_SIZE*) &A, (F_SIZE*) &B, 5, &yn);
#else
	F_SIZE yn = BIQUAD;
#endif

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