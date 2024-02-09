#ifndef _LIBRARY_H_
#define _LIBRARY_H_

#include <cmath>
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <iomanip>


class Curve3D
{
public:
	virtual void draw() const = 0;
	virtual ~Curve3D() = default;
};

class Circle3D : public Curve3D
{
public:
	Circle3D(double x, double y, double r) : x(x), y(y), z(0), r(r) {}
	void draw() const override;
	double getRadius();
private:
	double x, y, z, r;
};

class Ellipse3D : public Curve3D
{
public:
	Ellipse3D(double x, double y, double r1, double r2) : x(x), y(y), z(0), r1(r1), r2(r2) {}
	void draw() const override;
private:
	double x, y, z, r1, r2;
};

class Helix3D : public Curve3D
{
public:
	Helix3D(double x, double y, double a, double b, double step) : x(x), y(y), z(0), a(a), b(b), step(step), angleStart(0) {}
	void draw() const override;
private:
	double x, y, z, a, b, step, angleStart;
};


#endif /* _LIBRARY_H_ */
