#pragma once
template <class T>
class Interpolable {
public:
	virtual ~Interpolable() {}
	virtual T interpolate(const T &other, double x) const = 0;
}; 
