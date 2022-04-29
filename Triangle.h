#pragma once
#include "Pair.h"

class Triangle
	:public Pair
{
private:
	double x2;
	double y2;
	double x3;
	double y3;
public:
	Triangle();
	Triangle(double a, double b, double c, double d, double e, double f);
	Triangle(const Triangle&);

	Triangle& operator =(const Triangle&);
	friend istream& operator >>(istream&, Triangle&);
	friend ostream& operator <<(ostream&, Triangle&);
	operator string() const;

	Triangle& operator ++();
	Triangle& operator --();
	Triangle operator ++(int);
	Triangle operator --(int);

	double lengthPP(double x1, double y1, double x2, double y2);
	double Square();
	double Perimtr();

	double Height1();
	double Height2();
	double Height3();

	double get_a() { return lengthPP(x1, y1, x2, y2); };
	double get_b() { return lengthPP(x2, y2, x3, y3); };
	double get_c() { return lengthPP(x1, y1, x3, y3); };

	double get_A();              //used all
	double get_B();
	double get_C();

	string Define();               //used

	double GetX2() { return x2; };
	double GetY2() { return y2; };
	double GetX3() { return x3; };
	double GetY3() { return y3; };

	void SetX2(double value) { x2 = value; };
	void SetY2(double value) { y2 = value; };
	void SetX3(double value) { x3 = value; };
	void SetY3(double value) { y3 = value; };
};