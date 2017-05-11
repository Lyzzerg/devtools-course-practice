// Copyright 2017 Baranov Evgeny

#include "include/matrix.h"
#include "include/number_of_arbitrary_length.h"

ALMatrix::ALMatrix() : matrix_(nullptr), rows_(0), columns_(0) {
}

ALMatrix::ALMatrix(unsigned int _size) : rows_(_size), columns_(_size) {
    CreateMatrix(_size, _size);
}

ALMatrix::ALMatrix(unsigned int _rows, unsigned int _columns):
    rows_(_rows), columns_(_columns) {
    CreateMatrix(_rows, _columns);
}

ALMatrix::ALMatrix(const ALMatrix& _matrix) {
    CreateMatrix(_matrix.rows_, _matrix.columns_);
    CopyMatrix(_matrix);
}

ALMatrix::~ALMatrix() {
    DeleteMatix();
    matrix_ = nullptr;
}

ALMatrix ALMatrix::operator=(const ALMatrix& _matrix) {
    DeleteMatix();
    CreateMatrix(_matrix.rows_, _matrix.columns_);
    CopyMatrix(_matrix);
    return *this;
}

ALMatrix ALMatrix::operator+(const ALMatrix& _matrix) const {
    ALMatrix sum_res(*this);
    if (this->rows_ == _matrix.rows_ && this->columns_ == _matrix.columns_) {
        for (unsigned int i = 0; i < rows_; ++i) {
            for (unsigned int j = 0; j < columns_; ++j) {
                sum_res.matrix_[i][j] =
                    sum_res.matrix_[i][j] + _matrix.matrix_[i][j];
            }
        }
    } else {
        throw "Can't sum";
    }
    return sum_res;
}

ALMatrix ALMatrix::operator*(const ALMatrix& _matrix) const {
    ALMatrix composition(rows_, rows_);
    if (this->rows_ == _matrix.columns_ && this->columns_ == _matrix.rows_) {
        for (unsigned int i = 0; i < composition.rows_; ++i) {
            for (unsigned int j = 0; j < composition.columns_; ++j) {
                for (unsigned int k = 0; k < this->columns_; ++k) {
                    composition.matrix_[i][j] = composition[i][j] +
                        this->matrix_[i][k] *_matrix.matrix_[k][j];
                }
            }
        }
    } else {
        throw "Can't compos";
    }
    return composition;
}

unsigned int ALMatrix::GetRows() const {
    return rows_;
}

unsigned int ALMatrix::GetColumns() const {
    return columns_;
}

ALNumber* ALMatrix::operator[](unsigned int _row) const {
    if (_row >= rows_) {
        throw "wrong row";
    }
    return matrix_[_row];
}
