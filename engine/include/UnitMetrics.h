#pragma once
#include <memory>
#include <ratio>

#include "EngineMath.h"

typedef std::kilo Kilometers; //10e3
typedef std::hecto Hectometers; //10e2
typedef std::deca Decameters; //10e1
typedef std::ratio<1i64, 1i64> Meters;
typedef std::deci Decimeters; //10e-1
typedef std::centi Centimeters; //10e-2
typedef std::milli Millimeters; //10e-3

class CUnitMetrics
{
public:
	CUnitMetrics(CUnitMetrics const&) = delete;
	CUnitMetrics& operator=(CUnitMetrics const&) = delete;

	static std::shared_ptr<CUnitMetrics> Instance()
	{
		static std::shared_ptr<CUnitMetrics> s_pInstance{ new CUnitMetrics };
		return s_pInstance;
	}

	void SetPixelsPerMeter(float pixels);
	void SetPixelsPerMeter(float pixels, float meter);

	template<typename GivenUnits>
	long ConvertToPixels(float flInput)
	{
		float flConversionFactor = GivenUnits::num / GivenUnits::den;
		float flUnitInMeters = flInput * flConversionFactor;
		return std::lroundf(m_flPixelsPerMeter * flUnitInMeters);
	}

	template<typename GivenUnits>
	float ConvertFromPixels(double long input)
	{
		float flConversionFactor = GivenUnits::num / GivenUnits::den;
		float flMeters = (1 / m_flPixelsPerMeter) * input;
		return flMeters * flConversionFactor;
	}

	template<typename GivenUnits>
	CVector ConvertToPixels(CVector vecInput)
	{
		return CVector(
			ConvertToPixels<GivenUnits>(vecInput._x),
			ConvertToPixels<GivenUnits>(vecInput._y)
		);
	}

	template<typename GivenUnits>
	CVector ConvertFromPixels(CVector vecInput)
	{
		return CVector(
			ConvertFromPixels<GivenUnits>(vecInput._x),
			ConvertFromPixels<GivenUnits>(vecInput._y)
		);
	}

private:
	CUnitMetrics() {}
private:
	float m_flPixelsPerMeter = 1.f;
};