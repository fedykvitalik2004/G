#pragma once
#include "Object.h"
#include <ostream>
#include <istream>

using namespace std;

class Pair
	:public Object
{
protected:
	double x1;
	double y1;
public:
	Pair();
	Pair(double value1, double value2);
	Pair(const Pair&);

	Pair& operator=(const Pair&);  //used all;
	friend ostream& operator <<(ostream&, const Pair&);
	friend istream& operator >>(istream&, Pair&);
	operator string() const;

	Pair& operator ++();     //used all
	Pair& operator --();
	Pair operator ++(int);
	Pair operator --(int);

	void MoveX1(double value);
	void MoveY1(double value);
	double LengthOO();
	double LengthPP(Pair r, Pair l);
	void PolarCo();
	bool Compare(Pair r, Pair l);

	double GetX1();
	double GetY1();
	void SetX1(double value);
	void SetY1(double value);
};
