#pragma once

#include <math.h>

class CVector
{
public:
	explicit CVector(float x, float y);
	CVector();

	void operator=(const CVector& other);
	CVector operator+(const CVector& other);
	CVector operator-(const CVector& other);
	CVector operator*(const CVector& other);
	CVector operator/(const CVector& other);

	CVector operator*(const float& other);
	CVector operator/(const float& other);

	void operator+=(const CVector& other);
	void operator-=(const CVector& other);
	void operator*=(const CVector& other);
	void operator/=(const CVector& other);

	float operator[](int idx);

	CVector LerpTo(const CVector& other, float t);

	bool IsZero();

	static CVector Zero;

	float _x, _y;
};