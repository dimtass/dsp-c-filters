#pragma once
#ifndef FILTER_COMMON_H__
#define FILTER_COMMON_H__

#include <stdint.h>
#include "stm32f30x.h"
#include "math.h"
#include "arm_math.h"

// #define F_COEFF_SIZE_DOUBLE
#define F_COEFF_SIZE_FLOAT

#ifdef F_COEFF_SIZE_DOUBLE
#define F_SIZE double
#endif

#ifdef F_COEFF_SIZE_FLOAT
#define F_SIZE float32_t
#endif

#ifndef pi
#define  pi 3.1415926535897932384626433832795
#endif

#ifndef sqrt2
#define sqrt2 (2.0 * 0.707106781186547524401)
#endif

#ifndef sqrt2over2
#define  sqrt2over2  0.707106781186547524401
#endif

typedef struct {
	F_SIZE a0;
	F_SIZE a1;
	F_SIZE a2;
	F_SIZE b1;
	F_SIZE b2;
	F_SIZE c0;
	F_SIZE d0;
} tp_coeffs;

// This is the generic biquad structure that is used for all filters
// I've made this as a definition, so I do not repeat my self
#define BIQUAD (m_coeffs.a0*xn + m_coeffs.a1*m_xnz1 + m_coeffs.a2*m_xnz2 - m_coeffs.b1*m_ynz1 - m_coeffs.b2*m_ynz2)

#define SAVE_FILTER_STATE \
	m_xnz2 = m_xnz1; \
	m_xnz1 = xn; \
	m_ynz2 = m_ynz1; \
	m_ynz1 = yn

#endif