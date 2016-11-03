#include "vector3d.hpp"

#include <cmath>

const vector3d vector3d::X = {1, 0, 0};
const vector3d vector3d::Y = {0, 1, 0};
const vector3d vector3d::Z = {0, 0, 1};
const vector3d vector3d::ZERO = {0, 0, 0};

vector3d::vector3d(): vector3d(0, 0, 0) {
}

vector3d::vector3d(double x0, double y0, double z0) {
    x = x0;
    y = y0;
    z = z0;
}

vector3d vector3d::operator+(const vector3d &a) const{
    return vector3d(x + a.x, y + a.y, z + a.z);
}

vector3d vector3d::operator-(const vector3d &a) const{
    return vector3d(x - a.x, y - a.y, z - a.z);
}

vector3d vector3d::operator-() const{
    return vector3d(-x, -y, -z);
}

double vector3d::operator*(const vector3d &a){
    return (x*a.x + y*a.y + z*a.z);
}

vector3d vector3d::operator^(const vector3d &a) const{
    return vector3d(y*a.z - z*a.y, z*a.x - x*a.z, x*a.y - y*a.x);
}

bool vector3d::operator==(const vector3d &a) const{
    return (x == a.x and y == a.y and z == a.z);
}

bool vector3d::operator!=(const vector3d &a) const{
    return !(*this == a);
}

double vector3d::length() const {
    return pow((pow(x, 2) + pow(y, 2) + pow(z, 2)), 0.5);
}

vector3d vector3d::normalize(){
    double l = length();
    x = x/l; y = y/l; z = z/l;
    return vector3d(x, y, z);
}

vector3d operator*(const double i, vector3d &vector){
    return vector3d(vector.x*i, vector.y*i, vector.z*i);
}

vector3d operator*(vector3d &vector, const double i){
    return i*vector;
}

std::ostream &operator<<(std::ostream &stream, const vector3d & a){
    return stream << "{" << a.x<< ", " << a.y << ", " << a.z << "}";
}