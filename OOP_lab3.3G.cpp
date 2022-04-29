#include <iostream>
#include "Triangle.h"

int main()
{
    Triangle t = Triangle(Triangle(6, 0, 0, 0, 0, 8));
    cout << "Height 1: " << t.Height1() << endl << "Height 2: " << t.Height2() << endl << "Height 2: " << t.Height3() << endl;
    cout << t;
    cin >> t;

    cout << "The triangle is " << t.Define();
    cout << "t++" << endl << t++ << endl;
    cout << "++t" << endl << ++t << endl;
    cout << "t--" << endl << t-- << endl;
    cout << "t++" << endl << --t << endl;

    cout << "Square is " << t.Square() << endl;
    cout << "Perimetr is " << t.Perimtr() << endl;
    cout << endl << t.Count << endl << endl;

    Triangle* y = new Triangle();
    cout << "Dobutok is " << y->Square() << endl;
    cout << endl << y->Count << endl << endl;

    Pair r[1];
    r[0] = Pair(6, 8);
    cout << r[0] << endl;
    cin >> r[0];
    cout << r[0] << endl;
    cout << "Move r[0] on 4" << endl;
    r[0].MoveX1(4);
    r[0].MoveY1(4);
    cout << "In polar coordinates: " << endl;
    r[0].PolarCo();
    cout << r[0] << endl;

    cout << endl << r[0].Count << endl << endl;

    return 0;
}
