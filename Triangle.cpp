// triangle.cpp
#define _USE_MATH_DEFINES
#include "triangle.h"
#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include <iomanip>

double Triangle::calculateAngleA() const {
    int a = sides.getA();
    int b = sides.getB();
    int c = sides.getC();

    return acos((b * b + c * c - a * a) / (2.0 * b * c)) * 180.0 / M_PI;
}

double Triangle::calculateAngleB() const {
    int a = sides.getA();
    int b = sides.getB();
    int c = sides.getC();;

    return acos((a * a + c * c - b * b) / (2.0 * a * c)) * 180.0 / M_PI;
}

double Triangle::calculateAngleC() const {
    int a = sides.getA();
    int b = sides.getB();
    int c = sides.getC();

    return acos((a * a + b * b - c * c) / (2.0 * a * b)) * 180.0 / M_PI;
}


double Triangle::calculateArea() const {
    double s = sides.calculateSum() / 2.0;

    return sqrt(s * (s - sides.getA()) * (s - sides.getB()) * (s - sides.getC()));
}

std::string Triangle::toString(double a) const {
    std::stringstream ss;
    ss << std::setprecision(4) << a;

    return ss.str();
}

void Triangle::Display() const
{
    std::cout << "Triangle with sides: " << toString(sides.getA()) << ", " << toString(sides.getB()) << ", " << toString(sides.getC()) << std::endl;
    std::cout << "Area: " << toString(calculateArea()) << std::endl;
    std::cout << "Angles: " << toString(calculateAngleA()) << ", " << toString(calculateAngleB()) << ", " << toString(calculateAngleC()) << std::endl;
    std::cout << "Sum of sides: " << toString(sides.calculateSum()) << std::endl;
}

void Triangle::Init(int a, int b, int c)
{
    sides.Init(a, b, c);
}

void Triangle::SetSides(int a, int b, int c)
{
    sides.Init(a, b, c);
}

Triad Triangle::GetSides()
{
    return sides;
}

void Triangle::Read()
{
    int a, b, c;
    std::cout << "Enter Triad: ";
    std::cin >> a >> b >> c;
    sides.Init(a, b, c);
}

Triangle& Triangle::operator=(const Triangle& triangle)
{
	sides = triangle.sides;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Triangle& triangle)
{
	out << "Triangle with sides: " << triangle.toString(triangle.sides.getA()) << ", " << triangle.toString(triangle.sides.getB()) << ", " << triangle.toString(triangle.sides.getC()) << std::endl;
	out << "Area: " << triangle.toString(triangle.calculateArea()) << std::endl;
	out << "Angles: " << triangle.toString(triangle.calculateAngleA()) << ", " << triangle.toString(triangle.calculateAngleB()) << ", " << triangle.toString(triangle.calculateAngleC()) << std::endl;
	out << "Sum of sides: " << triangle.toString(triangle.sides.calculateSum()) << std::endl;
	return out;
}

std::istream& operator>>(std::istream& in, Triangle& triangle)
{
	int a, b, c;
	in >> a >> b >> c;
	triangle.SetSides(a, b, c);
	return in;
}

Triangle::operator std::string() const {
    return "Triangle sides: " + std::to_string(sides.getA()) + ", " +
        std::to_string(sides.getB()) + ", " +
        std::to_string(sides.getC());
}

Triangle& Triangle::operator++() {
	sides++;
	return *this;
}

Triangle& Triangle::operator--() {
	sides--;
	return *this;
}

Triangle Triangle::operator++(int) {
	Triangle t(*this);
	++sides;
	return t;
}

Triangle Triangle::operator--(int) {
	Triangle t(*this);
	--sides;
	return t;
}