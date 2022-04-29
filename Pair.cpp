#include "Pair.h"
#include <cmath>
#include <iostream>
#include <sstream>

using namespace std;

Pair::Pair()
	:x1(0), y1(0)
{}

Pair::Pair(double value1, double value2)
	: x1(value1), y1(value2)
{}

Pair::Pair(const Pair& r)
	: x1(r.x1), y1(r.y1)
{}

Pair& Pair::operator=(const Pair& r)
{
	x1 = r.x1;
	y1 = r.y1;
	return *this;
}

Pair::operator string() const
{
	stringstream ss;
	ss << "x=" << x1 << "; y=" << y1 << endl;
	return ss.str();
}

Pair& Pair::operator++()
{
	++x1;
	return *this;
}

Pair& Pair::operator--()
{
	--x1;
	return *this;
}

Pair Pair::operator++(int)
{
	Pair t = *this;
	y1++;
	return t;
}

Pair Pair::operator--(int)
{
	Pair t = *this;
	y1--;
	return t;
}

void Pair::MoveX1(double value)
{
	x1 += value;
}

void Pair::MoveY1(double value)
{
	y1 += value;
}

double Pair::LengthOO()
{
	return sqrt(x1 * x1 + y1 * y1);
}

double Pair::LengthPP(Pair r, Pair l)
{
	return sqrt(pow(r.x1 - l.x1, 2) + pow(r.y1 - l.y1, 2));
}

void Pair::PolarCo()
{
	const double PI = 3.141592;
	double a = LengthOO();

	if (x1 > 0)
	{
		y1 = atan(y1 / x1);
		x1 = a;
	}
	else
	{
		if (x1 < 0)
		{
			if (y1 >= 0)
				y1 = atan(y1 / x1) + PI;
			else
				y1 = atan(y1 / x1) - PI;
			x1 = a;

		}
		else
		{
			if (y1 > 0)
			{
				y1 = PI / 2;
				x1 = a;
			}
			if (y1 < 0)
			{
				y1 = -PI / 2;
				x1 = a;
			}
			if (y1 == 0)
				cout << "Not defined!" << endl;
		}
	}
}

bool Pair::Compare(Pair r, Pair l)
{
	if (r.x1 == l.x1 && r.y1 == l.y1) return true;
	else return false;
}

double Pair::GetX1()
{
	return x1;
}

double Pair::GetY1()
{
	return y1;
}

void Pair::SetX1(double value)
{
	x1 = value;
}

void Pair::SetY1(double value)
{
	y1 = value;
}

ostream& operator<<(ostream& out, const Pair& r)
{
	out << string(r);
	return out;
}

istream& operator>>(istream& in, Pair& r)
{
	cout << "x="; in >> r.x1;
	cout << "y="; in >> r.y1;
	return in;
}
