#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <ostream>
//#include <bits/mathdef.h>

class vector3d {
public:
    double x, y, z;
    const static vector3d X;
    const static vector3d Y;
    const static vector3d Z;
    const static vector3d ZERO;

    vector3d();
    vector3d(double x, double y, double z);

    vector3d operator+(const vector3d &a) const;
    vector3d operator-(const vector3d &a) const;
    vector3d operator-() const;
    double operator*(const vector3d &a);
    vector3d operator^(const vector3d &a) const;

    bool operator==(const vector3d &a) const;

    double length() const;
    vector3d normalize(const vector3d &a);


};

double operator*(const double i, const vector3d &vector);
double operator*(const vector3d &vector, const double i);

//std::ostream &operator<<(std::ostream &stream, const vector3d & a);

#endif
