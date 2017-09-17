#include "Vector.h"

#include <cassert>

CVector CVector::Zero = CVector(0.f, 0.f);

CVector::CVector(float x, float y) :
	_x(x),
	_y(y)
{

}

CVector::CVector()
{
	_x = 0.f; _y = 0.f;
}

void CVector::operator=(const CVector & other)
{
	this->_x = other._x;
	this->_y = other._y;
}

CVector CVector::operator+(const CVector& other)
{
	return CVector(
		this->_x + other._x,
		this->_y + other._y
	);
}

CVector CVector::operator-(const CVector& other)
{
	return CVector(
		this->_x - other._x,
		this->_y - other._y
	);
}

CVector CVector::operator*(const CVector& other)
{
	return CVector(
		this->_x * other._x,
		this->_y * other._y
	);
}

CVector CVector::operator/(const CVector& other)
{
	return CVector(
		this->_x / other._x,
		this->_y / other._y
	);
}

CVector CVector::operator*(const float & other)
{
	return CVector(
		this->_x * other,
		this->_y * other
	);
}

CVector CVector::operator/(const float & other)
{
	return CVector(
		this->_x / other,
		this->_y / other
	);
}

void CVector::operator+=(const CVector& other)
{
	this->_x += other._x;
	this->_y += other._y;
}

void CVector::operator-=(const CVector& other)
{
	this->_x -= other._x;
	this->_y -= other._y;
}

void CVector::operator*=(const CVector& other)
{
	this->_x *= other._x;
	this->_y *= other._y;
}

void CVector::operator/=(const CVector& other)
{
	this->_x /= other._x;
	this->_y /= other._y;
}

bool CVector::IsZero()
{
	return (
		this->_x != 0 &&
		this->_y != 0
	);
}

float CVector::operator[](int idx)
{
	assert(idx <= 2 && idx >= 0);
	switch (idx)
	{
	case 0: return _x;
	case 1: return _y;
	}
}

CVector CVector::LerpTo(const CVector& other, float t)
{
	float flTimeFraction = (t - 1.f);
	return CVector(
		flTimeFraction * this->_x + t * other._x,
		flTimeFraction * this->_y + t * other._y
	);
}