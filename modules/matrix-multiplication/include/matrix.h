// Copyright 2017 Baranov Evgeny

#ifndef MODULES_MATRIX_MULTIPLICATION_INCLUDE_MATRIX_H_
#define MODULES_MATRIX_MULTIPLICATION_INCLUDE_MATRIX_H_

#include "include/number_of_arbitrary_length.h"

class ALMatrix {
 private:
    ALNumber ** matrix;
    unsigned int rows;
    unsigned int columns;

 public:
     ALMatrix();

     explicit ALMatrix(unsigned int _size);

     ALMatrix(unsigned int _rows, unsigned int _columns);

     ALMatrix(const ALMatrix& _matrix);

     ~ALMatrix();

     ALMatrix operator = (const ALMatrix& _matrix);

     ALMatrix operator + (const ALMatrix& _matrix) const;

     ALMatrix operator * (const ALMatrix& _matrix) const;

     unsigned int get_rows() const;
     
     unsigned int get_columns() const;

     friend std::ostream& operator << (std::ostream& os,
         const ALMatrix& _matrix);

     friend std::istream& operator >> (std::istream& is,
         ALMatrix& _matrix);
};
#endif  // MODULES_MATRIX_MULTIPLICATION_INCLUDE_MATRIX_H_
