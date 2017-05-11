// Copyright 2017 Baranov Evgeny

#ifndef MODULES_MATRIX_MULTIPLICATION_INCLUDE_MATRIX_H_
#define MODULES_MATRIX_MULTIPLICATION_INCLUDE_MATRIX_H_

#include "include/number_of_arbitrary_length.h"

class ALMatrix {
 public:
     ALMatrix();

     explicit ALMatrix(unsigned int _size);

     ALMatrix(unsigned int _rows, unsigned int _columns);

     ALMatrix(const ALMatrix& _matrix);

     ~ALMatrix();

     ALMatrix operator = (const ALMatrix& _matrix);

     ALMatrix operator + (const ALMatrix& _matrix) const;

     ALMatrix operator * (const ALMatrix& _matrix) const;

     unsigned int GetRows() const;

     unsigned int GetColumns() const;

     ALNumber* operator[] (unsigned int _row) const;

 private:
    ALNumber ** matrix_;
    unsigned int rows_;
    unsigned int columns_;
};
#endif  // MODULES_MATRIX_MULTIPLICATION_INCLUDE_MATRIX_H_
