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
    void CreateMatrix(int _rows, int _columns) {
        if (rows_ != 0 && columns_ != 0) {
            matrix_ = new ALNumber*[rows_];
            for (unsigned int i = 0; i < rows_; ++i) {
                matrix_[i] = new ALNumber[columns_];
            }
        } else {
            rows_ = columns_ = 0;
            matrix_ = nullptr;
        }
    }
    void DeleteMatix() {
        if (columns_ != 0 && rows_ != 0) {
            for (unsigned int i = 0; i < rows_; ++i) {
                delete[] matrix_[i];
            }
            delete[] matrix_;
        }
    }
    void CopyMatrix(const ALMatrix& _matrix) {
        for (unsigned int i = 0; i < rows_; ++i) {
            for (unsigned int j = 0; j < columns_; ++j) {
                this->matrix_[i][j] = _matrix.matrix_[i][j];
            }
        }
    }
};
#endif  // MODULES_MATRIX_MULTIPLICATION_INCLUDE_MATRIX_H_
