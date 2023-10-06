#pragma once

#define _USE_MATH_DEFINES
#include <cmath>
#include <algorithm>
#include <vector>
#include "TF2/vector.h"

#define DIST_EPSILON (0.03125f)
#define floatCompare(x, y) (fabsf(x - y) <= FLT_EPSILON * fmaxf(1.0f, fmaxf(fabsf(x), fabsf(y))))

namespace Maths
{
	inline void SinCos(float radians, float* sine, float* cosine)
	{
		_asm
		{
			fld		DWORD PTR[radians]
			fsincos

			mov edx, DWORD PTR[cosine]
			mov eax, DWORD PTR[sine]

			fstp DWORD PTR[edx]
			fstp DWORD PTR[eax]
		}
	}
	inline double __declspec (naked) __fastcall FastSqrt(double n)
	{
		_asm fld qword ptr[esp + 4]
			_asm fsqrt
		_asm ret 8
	}
}