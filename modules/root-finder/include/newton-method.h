// Copyright 2017 Fedorov Igor

#ifndef MODULES_ROOT_FINDER_INCLUDE_NEWTON_METHOD_H_
#define MODULES_ROOT_FINDER_INCLUDE_NEWTON_METHOD_H_

class NewtonMethod {
 public:
    void SetAB(float a, float b) {
        A_ = a;
        B_ = b;
    }
    void SetAccuracy(float acc) {
        Acc_ = acc;
    }

    float FindRoot(float(*fun)(float),
        float(*deriv_fun)(float), float(*deriv2_fun)(float));

 private:
    float A_;
    float B_;
    float Acc_;
    bool IsMonotone(float(*fun)(float));
};
#endif  // MODULES_ROOT_FINDER_INCLUDE_NEWTON_METHOD_H_

