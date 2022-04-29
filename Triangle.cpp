#include "Triangle.h"
#include <iostream>
#include <sstream>

using namespace std;

Triangle::Triangle()
	:Pair(1, 0)
{
	x2 = 0;
	y2 = 0;
	x3 = 0;
	y3 = 1;
}

Triangle::Triangle(double a, double b, double c, double d, double e, double f)
	:Pair(a, b)
{
	while (a == c && b == d)
	{
		cout << "Wrong x2 and y2. Enter again:" << endl;
		cout << "x2="; cin >> c;
		cout << "y2="; cin >> d;
	}
	x2 = c;
	y2 = d;
	while ((e == a && f == b) || (e == c && f == d))
	{
		cout << "Wrong x3 and y3. Enter again:" << endl;
		cout << "x3="; cin >> e;
		cout << "y3="; cin >> f;
	}
	x3 = e;
	y3 = f;
}

Triangle::Triangle(const Triangle& r)
	:Pair(r.x1, r.y1)
{
	x2 = r.x2;
	y2 = r.y2;
	x3 = r.x3;
	y3 = r.y3;
}

Triangle& Triangle::operator=(const Triangle& r)
{
	x1 = r.x1;
	y1 = r.y1;
	x2 = r.x2;
	y2 = r.x2;
	x3 = r.x3;
	y3 = r.y3;
	return *this;
}

Triangle::operator string() const
{
	stringstream ss;
	ss << "Pair1:" << endl;
	ss << "x1=" << x1 << endl;
	ss << "y1=" << y1 << endl;
	ss << "Pair2:" << endl;
	ss << "x2=" << x2 << endl;
	ss << "y2=" << y2 << endl;
	ss << "Pair3:" << endl;
	ss << "x3=" << x3 << endl;
	ss << "y3=" << y3 << endl;
	return ss.str();
}

Triangle& Triangle::operator++()
{
	++x2;
	return *this;
}

Triangle& Triangle::operator--()
{
	--x2;
	return *this;
}

Triangle Triangle::operator++(int)
{
	Triangle r(*this);
	r.y2++;
	return r;
}

Triangle Triangle::operator--(int)
{
	Triangle r(*this);
	r.y2--;
	return r;
}

double Triangle::lengthPP(double x1, double y1, double x2, double y2)
{
	double a = x2 - x1;
	double b = y2 - y1;
	return sqrt(a * a + b * b);
}

double Triangle::Square()
{
	double a = lengthPP(x1, y1, x2, y2);
	double b = lengthPP(x2, y2, x3, y3);
	double c = lengthPP(x3, y3, x1, y1);
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

double Triangle::Perimtr()
{
	double a = lengthPP(x1, y1, x2, y2);
	double b = lengthPP(x2, y2, x3, y3);
	double c = lengthPP(x3, y3, x1, y1);
	return a + b + c;
}

istream& operator>>(istream& in, Triangle& r)
{
	cout << "Pair1:" << endl;
	cout << "x1="; in >> r.x1;
	cout << "y1="; in >> r.y1;
	do {
		cout << "Pair2:" << endl;
		cout << "x2="; in >> r.x2;
		cout << "y2="; in >> r.y2;
	} while ((r.x1 == r.x2) && (r.y1 = r.y2));
	do {
		cout << "Pair3:" << endl;
		cout << "x3="; in >> r.x3;
		cout << "y3="; in >> r.y3;
	} while ((r.x3 == r.x2 && r.y3 == r.y2) || (r.x1 == r.x3 && r.y1 == r.y3));
	return in;
}

ostream& operator<<(ostream& out, Triangle& r)
{
	out << string(r);
	return out;
}

double Triangle::Height1()
{
	double a = get_a();
	double b = Square();
	double height2 = 2 * b / a;
	return height2;
}

double Triangle::Height2()
{
	double a = get_b();
	double b = Square();
	double height1 = 2 * b / a;
	return height1;
}

double Triangle::Height3()
{
	double a = get_c();
	double b = Square();
	double height2 = 2 * b / a;
	return height2;
}

string Triangle::Define()
{
	stringstream sout;

	double b = get_b();
	double c = get_c();
	double b1 = x2 - x3;
	double b2 = y2 - y3;
	double c1 = x1 - x3;
	double c2 = y1 - y3;
	double multiplication1 = b1 * c1 + b2 * c2;

	double a = get_a();
	double a1 = x2 - x1;
	double a2 = y2 - y1;
	c1 = x3 - x1;
	c2 = y3 - y1;
	double multiplication2 = a1 * c1 + a2 * c2;

	a1 = x1 - x2;
	a2 = y1 - y2;
	b1 = x3 - x2;
	b2 = y3 - y2;
	double multiplication3 = a1 * b1 + a2 * b2;

	if (multiplication1 == 0 || multiplication2 == 0 || multiplication3 == 0)
		sout << "Pryamokutniy" << endl;
	else
	{
		if (multiplication1 < 0 || multiplication2 < 0 || multiplication3 < 0)
			sout << "Tupokutniy" << endl;
		else
			sout << "Hostrokutniy" << endl;
	}
	return sout.str();
}


double Triangle::get_A()
{
	double b = get_b();
	double c = get_c();
	double b1 = x2 - x3;
	double b2 = y2 - y3;
	double c1 = x1 - x3;
	double c2 = y1 - y3;
	double multiplication = b1 * c1 + b2 * c2;
	double cosb = multiplication / (b * c);

	return acos(cosb);
}

double Triangle::get_B()
{
	double a = get_a();
	double c = get_c();
	double a1 = x2 - x1;
	double a2 = y2 - y1;
	double c1 = x3 - x1;
	double c2 = y3 - y1;
	double multiplication = a1 * c1 + a2 * c2;
	double cosc = multiplication / (a * c);

	return acos(cosc);
}

double Triangle::get_C()
{
	double a = get_a();
	double b = get_b();
	double a1 = x1 - x2;
	double a2 = y1 - y2;
	double b1 = x3 - x2;
	double b2 = y3 - y2;
	double multiplication = a1 * b1 + a2 * b2;
	double cosa = multiplication / (a * b);

	return acos(cosa);
}