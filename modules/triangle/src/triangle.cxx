// Copyright 2017 Karev Boris

#include "include/triangle.h"

#include <stdbool.h>
#include <string>
#include <limits>

Triangle::Triangle() : point1_coordx_(0), point1_coordy_(0), point2_coordx_(0), point2_coordy_(1), point3_coordx_(1), point3_coordy_(0) {}

Triangle::Triangle(const double point1_coordx, const double point1_coordy, const double point2_coordx, const double point2_coordy, const double point3_coordx, const double point3_coordy)
    : point1_coordx_(point1_coordx), point1_coordy_(point1_coordy), point2_coordx_(point2_coordx), point2_coordy_(point2_coordy), point3_coordx_(point3_coordx), point3_coordy_(point3_coordy) {
    if (!isTriangle(*this)) {
        throw std::string("These coordinates do not form a triangle");
    }
}

Triangle::Triangle(const Triangle& t)
    : point1_coordx_(t.Get_coordX_point(1)), point1_coordy_(t.Get_coordY_point(1)), point2_coordx_(t.Get_coordX_point(2)), point2_coordy_(t.Get_coordY_point(2)), point3_coordx_(t.Get_coordX_point(3)), point3_coordy_(t.Get_coordY_point(3)) {}

Triangle& Triangle::operator=(const Triangle& t) {
    point1_coordx_ = t.Get_coordX_point(1);
    point1_coordy_ = t.Get_coordY_point(1);
    point2_coordx_ = t.Get_coordX_point(2);
    point2_coordy_ = t.Get_coordY_point(2);
    point3_coordx_ = t.Get_coordX_point(3);
    point3_coordy_ = t.Get_coordY_point(3);
    return *this;
}

double Triangle::Get_coordX_point(const int number_point) const {
    if (number_point == 1) return point1_coordx_;
    if (number_point == 2) return point2_coordx_;
    if (number_point == 3) return point3_coordx_;
    throw std::string("Unknown number of point");

}

double Triangle::Get_coordY_point(const int number_point) const {
    if (number_point == 1) return point1_coordy_;
    if (number_point == 2) return point2_coordy_;
    if (number_point == 3) return point3_coordy_;
    throw std::string("Unknown number of point");
}

void Triangle::Set_coordX_point(const double x, const int number_point) {
    if (number_point == 1) point1_coordx_ = x;
    else if (number_point == 2) point2_coordx_ = x;
    else if (number_point == 3) point3_coordx_ = x;
    else throw std::string("Unknown number of point");
    if (!isTriangle(*this)) {
        throw std::string("New coordinates do not form a triangle.");
    }
}

void Triangle::Set_coordY_point(const double y, const int number_point) {
    if (number_point == 1) point1_coordy_ = y;
    else if (number_point == 2) point2_coordy_ = y;
    else if (number_point == 3) point3_coordy_ = y;
    else throw std::string("Unknown number of point");
    if (!isTriangle(*this)) {
        throw std::string("New coordinates do not form a triangle.");
    }
}

bool Triangle::isTriangle(const Triangle& t) const {
    double side1, side2, side3;
    side1 = sqrt((point1_coordx_ - point2_coordx_)*(point1_coordx_ - point2_coordx_) + (point1_coordy_ - point2_coordy_)*(point1_coordy_ - point2_coordy_));
    side2 = sqrt((point3_coordx_ - point2_coordx_)*(point3_coordx_ - point2_coordx_) + (point3_coordy_ - point2_coordy_)*(point3_coordy_ - point2_coordy_));
    side3 = sqrt((point1_coordx_ - point3_coordx_)*(point1_coordx_ - point3_coordx_) + (point1_coordy_ - point3_coordy_)*(point1_coordy_ - point3_coordy_));
    return ((side1 < side2 + side3) && (side2 < side1 + side3) && (side3 < side1 + side2));
}

bool Triangle::operator == (const Triangle& t) const {
    double side1, side2, side3, tside1, tside2, tside3;
    bool result = false;
    side1 = sqrt((point1_coordx_ - point2_coordx_)*(point1_coordx_ - point2_coordx_) + (point1_coordy_ - point2_coordy_)*(point1_coordy_ - point2_coordy_));
    side2 = sqrt((point3_coordx_ - point2_coordx_)*(point3_coordx_ - point2_coordx_) + (point3_coordy_ - point2_coordy_)*(point3_coordy_ - point2_coordy_));
    side3 = sqrt((point1_coordx_ - point3_coordx_)*(point1_coordx_ - point3_coordx_) + (point1_coordy_ - point3_coordy_)*(point1_coordy_ - point3_coordy_));
    tside1 = sqrt((t.Get_coordX_point(1) - t.Get_coordX_point(2)) * (t.Get_coordX_point(1) - t.Get_coordX_point(2)) + (t.Get_coordY_point(1) - t.Get_coordY_point(2))*(t.Get_coordY_point(1) - t.Get_coordY_point(2)));
    tside2 = sqrt((t.Get_coordX_point(3) - t.Get_coordX_point(2)) * (t.Get_coordX_point(3) - t.Get_coordX_point(2)) + (t.Get_coordY_point(3) - t.Get_coordY_point(2))*(t.Get_coordY_point(3) - t.Get_coordY_point(2)));
    tside3 = sqrt((t.Get_coordX_point(1) - t.Get_coordX_point(3)) * (t.Get_coordX_point(1) - t.Get_coordX_point(3)) + (t.Get_coordY_point(1) - t.Get_coordY_point(3))*(t.Get_coordY_point(1) - t.Get_coordY_point(3)));

    if (side1 == tside1)
        if (((side2 == tside2) && (side3 == tside3)) || ((side2 == tside3) && (side3 == tside2))) result = true;
    if (side1 == tside2)
        if (((side2 == tside1) && (side3 == tside3)) || ((side2 == tside3) && (side3 == tside1))) result = true;
    if (side1 == tside3)
        if (((side2 == tside2) && (side3 == tside1)) || ((side2 == tside1) && (side3 == tside2))) result = true;
    return result;
}

bool Triangle::operator != (const Triangle& t) const {
    return !(*this == t);
}

double Triangle::Calculate_side(const int number_side) const{
    if (number_side == 1) return sqrt((point3_coordx_ - point2_coordx_)*(point3_coordx_ - point2_coordx_) + (point3_coordy_ - point2_coordy_)*(point3_coordy_ - point2_coordy_));
    if (number_side == 2) return sqrt((point1_coordx_ - point3_coordx_)*(point1_coordx_ - point3_coordx_) + (point1_coordy_ - point3_coordy_)*(point1_coordy_ - point3_coordy_));
    if (number_side == 3) return sqrt((point1_coordx_ - point2_coordx_)*(point1_coordx_ - point2_coordx_) + (point1_coordy_ - point2_coordy_)*(point1_coordy_ - point2_coordy_));
    throw std::string("Unknown number of side");
}

double Triangle::Calculate_corner(const int number_corner) const{
    double side1, side2, side3;
    side1 = sqrt((point1_coordx_ - point2_coordx_)*(point1_coordx_ - point2_coordx_) + (point1_coordy_ - point2_coordy_)*(point1_coordy_ - point2_coordy_));
    side2 = sqrt((point3_coordx_ - point2_coordx_)*(point3_coordx_ - point2_coordx_) + (point3_coordy_ - point2_coordy_)*(point3_coordy_ - point2_coordy_));
    side3 = sqrt((point1_coordx_ - point3_coordx_)*(point1_coordx_ - point3_coordx_) + (point1_coordy_ - point3_coordy_)*(point1_coordy_ - point3_coordy_));
    if (number_corner == 1) return acos((side1*side1 + side3*side3 - side2*side2) / (2 * side1*side3));
    if (number_corner == 2) return acos((side1*side1 + side2*side2 - side3*side3) / (2 * side1*side2));
    if (number_corner == 3) return acos((side2*side2 + side3*side3 - side1*side1) / (2 * side2*side3));
    throw std::string("Unknown number of corner");
}

double Triangle::Calculate_perimeter() const{
    double side1, side2, side3;
    side1 = sqrt((point1_coordx_ - point2_coordx_)*(point1_coordx_ - point2_coordx_) + (point1_coordy_ - point2_coordy_)*(point1_coordy_ - point2_coordy_));
    side2 = sqrt((point3_coordx_ - point2_coordx_)*(point3_coordx_ - point2_coordx_) + (point3_coordy_ - point2_coordy_)*(point3_coordy_ - point2_coordy_));
    side3 = sqrt((point1_coordx_ - point3_coordx_)*(point1_coordx_ - point3_coordx_) + (point1_coordy_ - point3_coordy_)*(point1_coordy_ - point3_coordy_));
    return side1 + side2 + side3;
}

double Triangle::Calculate_square() const{
    double side1, side2, side3, per;
    side1 = sqrt((point1_coordx_ - point2_coordx_)*(point1_coordx_ - point2_coordx_) + (point1_coordy_ - point2_coordy_)*(point1_coordy_ - point2_coordy_));
    side2 = sqrt((point3_coordx_ - point2_coordx_)*(point3_coordx_ - point2_coordx_) + (point3_coordy_ - point2_coordy_)*(point3_coordy_ - point2_coordy_));
    side3 = sqrt((point1_coordx_ - point3_coordx_)*(point1_coordx_ - point3_coordx_) + (point1_coordy_ - point3_coordy_)*(point1_coordy_ - point3_coordy_));
    per = (side1 + side2 + side3) / 2;
    return sqrt(per * (per - side1) * (per - side2) * (per - side3));
}

double Triangle::Get_coordX_median() const{
    return (point1_coordx_ + point2_coordx_ + point3_coordx_) / 3;
}

double Triangle::Get_coordY_median() const{
    return (point1_coordy_ + point2_coordy_ + point3_coordy_) / 3;
}
