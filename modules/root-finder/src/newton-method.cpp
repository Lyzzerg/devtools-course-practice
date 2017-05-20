// Copyright 2017 Fedorov Igor

#include "include/newton-method.h"

#include <algorithm>
#include <iostream>
#include <cmath>

bool NewtonMethod::IsMonotone(float(*fun)(float)) {
    if (A_ > B_) {
        std::swap(A_, B_);
    }
    if (fun(A_) > fun(B_)) {
        float i = A_;
        float temp_i = i;
        while (temp_i < B_) {
            if (fun(i) < fun(temp_i))
                return false;
            i = temp_i;
            temp_i += Acc_;
            }
    } else if (fun(A_) < fun(B_)) {
        float i = A_;
        float temp_i = i;
        while (temp_i < B_) {
            if (fun(i) > fun(temp_i))
                return false;
            i = temp_i;
            temp_i += Acc_;
        }
    }
    if (A_ == B_) {
        return false;
    }
    if (fun(A_) == fun(B_)) {
        return false;
    }
    return true;
}

float NewtonMethod::FindRoot(float(*fun)(float),
    float(*deriv_fun)(float), float(*deriv2_fun)(float)) {
    if (IsMonotone(fun)) {
        float xn = fun(A_)*deriv2_fun(A_) > 0 ? A_ : B_;
        float x1 = xn - fun(xn) / deriv_fun(xn);
        float x0 = xn;
        float xsum = std::abs(x0 - x1);
        while (xsum > Acc_) {
            if (x1 < A_ || x1 > B_)
                throw("segment have not desidion");
            x0 = x1;
            x1 = x1 - fun(x1) / deriv_fun(x1);
            xsum = std::abs(x0 - x1);
        }
        return x1;
    } else {
        throw("function isnot monotone or its point");
    }
}
