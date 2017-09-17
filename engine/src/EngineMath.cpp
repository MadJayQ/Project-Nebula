#include "EngineMath.h"

float Math::Lerp(float f0, float f1, float t)
{
	return (1.f - t) * f0 + t * f1;
}

v2 Math::Lerp(v2 v0, v2 v1, float t)
{
	return v2(
		Lerp(v0._x, v1._x, t),
		Lerp(v0._y, v1._y, t)
	);
}