#include <iostream>

#include "sharedLibrary.hpp"


void Circle3D::draw() const
{
	std::cout << "Circle: { " << std::fixed << std::setprecision(2)
		<< x + r * cos(M_PI / 4) << ", " << y + r * sin(M_PI / 4)
		<< ", " << z << " }," << "\t" << "{ " << r * -sin(M_PI / 4) << ", "
		<< r * cos(M_PI / 4) << ", " << z << " }" << std::endl;
}

double  Circle3D::getRadius()
{
	return r;
}

void Ellipse3D::draw() const
{
	{
		std::cout << "Ellipse:{ " << std::fixed << std::setprecision(2)
			<< x + r1 * cos(M_PI / 4) << ", " << y + r2 * sin(M_PI / 4) << ", " << z
			<< " }," << "\t" << "{ " << r1 * -sin(M_PI / 4) << ", " << r2 * cos(M_PI / 4)
			<< ", " << z << " }" << std::endl;
	}
}

void Helix3D::draw() const
{
	std::cout << "Helix:  { " << std::fixed << std::setprecision(2)
		<< x + a * cos(M_PI / 4) << ", " << y + b * sin(M_PI / 4) << ", "
		<< z + (angleStart + M_PI / 4) / (M_PI * 2) * step << " }," << "\t" << "{ "
		<< a * -sin(M_PI / 4) << ", " << b * cos(M_PI / 4) << ", "
		<< step / (M_PI * 2) << " }" << std::endl;
}
