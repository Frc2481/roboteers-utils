#pragma once
#include "Interpolable.h"
#include "InverseInterpolable.h"

class InterpolatingDouble : public Interpolable<InterpolatingDouble>, InverseInterpolable<InterpolatingDouble>
{
	public:
		double m_value;
		InterpolatingDouble(double val);
		virtual ~InterpolatingDouble();
		InterpolatingDouble interpolate(const InterpolatingDouble &other, double x) const;
		double inverseInterpolate(const InterpolatingDouble &upper, const InterpolatingDouble &query) const ;
		friend bool operator<(const InterpolatingDouble &lhs, const InterpolatingDouble &rhs);
		bool operator==(const InterpolatingDouble &other);
};
