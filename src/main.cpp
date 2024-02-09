#include "../lib_src/sharedLibrary.hpp"
#include <iostream>
#include <vector>
#include <memory>
#include <chrono>
#include <random>
#include <algorithm>


int main()
{
    std::mt19937_64 rand(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<size_t> disVectorSize(10, 20);
    std::uniform_int_distribution<size_t> disCurveType(0, 2);
    std::uniform_real_distribution<> disSpace(-10, 10);
    std::uniform_real_distribution<> disPositive(0, 10);

    std::vector<std::shared_ptr<Curve3D>> curves;
    curves.reserve(disVectorSize(rand));
    for (size_t i = 0; i < curves.capacity(); i++)
    {
        switch (disCurveType(rand)) {
        case 0:
            curves.push_back(std::move(std::make_shared<Ellipse3D>(disSpace(rand), disSpace(rand), disPositive(rand), disPositive(rand))));
            break;
        case 1:
            curves.push_back(std::move(std::make_shared<Circle3D>(disSpace(rand), disSpace(rand), disPositive(rand))));
            break;
        case 2:
            curves.push_back(std::move(std::make_shared<Helix3D>(disSpace(rand), disSpace(rand), disSpace(rand), disPositive(rand), disPositive(rand))));
            break;
        default:
            curves.push_back(std::move(std::make_shared<Circle3D>(disSpace(rand), disSpace(rand), disPositive(rand))));
        }
    }

    for (auto& curve : curves)
    {
        curve->draw();
    }

    std::vector<std::shared_ptr<Circle3D>> circles;
    for (auto& curve : curves)
    {
        if (auto circle = std::dynamic_pointer_cast<Circle3D>(curve))
        {
            circles.push_back(std::move(circle));
        }
    }

    std::sort(circles.begin(), circles.end(), [](std::shared_ptr<Circle3D>& lhs, std::shared_ptr<Circle3D>& rhs) 
    {
        return lhs->getRadius() < rhs->getRadius();
        
    });

    double radiiSum = 0;
    for (const auto& circle : circles) {
        radiiSum += circle->getRadius();
        std::cout << circle->getRadius() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "The sum of the radii: " << radiiSum << std::endl;

}
