// Copyright 2017 Lapin Artem

#ifndef MODULES_LINE_PLANE_INTERSEC_INCLUDE_LINE_PLANE_INTERSEC_H_
#define MODULES_LINE_PLANE_INTERSEC_INCLUDE_LINE_PLANE_INTERSEC_H_
#include <vector>

class Intersection {
 private:
    double linex0_;
    double liney0_;
    double linez0_;
    double linedirx_;
    double linediry_;
    double linedirz_;
    double planeA_;
    double planeB_;
    double planeC_;
    double planeD_;

 public:
    Intersection();
    Intersection(double linex0, double liney0, double linez0,
        double dirx0, double diry0, double dirz0,
        double planeA, double planeB, double planeC, double planeD);
    Intersection(std::vector<double>lineStart,
        std::vector<double>lineDirection, std::vector<double>plane);

    void SetLine(double linex0_, double liney0_, double linez0_,
        double linedirx_, double linediry_, double linedirz_);
    void SetLine(std::vector<double>lineStart,
        std::vector<double>lineDirection);
    void SetPlane(std::vector<double>plane);
    void SetPlane(double planeA_, double planeB_, double planeC_,
        double planeD_);

    std::vector <double> GetLine(void);
    std::vector <double> GetPlane(void);

    std::vector <double> CalculateIntersection(void);
};

#endif  // MODULES_LINE_PLANE_INTERSEC_INCLUDE_LINE_PLANE_INTERSEC_H_
