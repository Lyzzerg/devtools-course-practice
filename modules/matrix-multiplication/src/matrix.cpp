// Copyright 2017 Baranov Evgeny

#include "include/matrix.h"
#include "include/number_of_arbitrary_length.h"

ALMatrix::ALMatrix() : matrix_(nullptr), rows_(0), columns_(0) {
}

ALMatrix::ALMatrix(unsigned int _size) : rows_(_size), columns_(_size) {
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

ALMatrix::ALMatrix(unsigned int _rows, unsigned int _columns):
    rows_(_rows), columns_(_columns) {
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

ALMatrix::ALMatrix(const ALMatrix & _matrix) {
    if (_matrix.columns_ != 0 && _matrix.rows_ != 0) {
        this->columns_ = _matrix.columns_;
        this->rows_ = _matrix.rows_;
        this->matrix_ = new ALNumber*[rows_];
        for (unsigned int i = 0; i < rows_; ++i) {
            this->matrix_[i] = new ALNumber[columns_];
        }
        for (unsigned int i = 0; i < rows_; ++i) {
            for (unsigned int j = 0; j < columns_; ++j) {
                this->matrix_[i][j] = _matrix.matrix_[i][j];
            }
        }
    } else {
        throw "Can't copy";
    }
}

ALMatrix::~ALMatrix() {
    for (unsigned int i = 0; i < rows_; ++i) {
        delete[] matrix_[i];
    }
    delete[] matrix_;
    matrix_ = nullptr;
}

ALMatrix ALMatrix::operator=(const ALMatrix& _matrix) {
    if (_matrix.columns_ != 0 && _matrix.rows_ != 0) {
        if (columns_ != 0 && rows_ != 0) {
            for (unsigned int i = 0; i < rows_; ++i) {
                delete[] matrix_[i];
            }
            delete[] matrix_;
        }

        this->rows_ = _matrix.rows_;
        this->columns_ = _matrix.columns_;
        this->matrix_ = new ALNumber*[rows_];
        for (unsigned int i = 0; i < rows_; ++i) {
            this->matrix_[i] = new ALNumber[columns_];
        }

        for (unsigned int i = 0; i < rows_; ++i) {
            for (unsigned int j = 0; j < columns_; ++j) {
                this->matrix_[i][j] = _matrix.matrix_[i][j];
            }
        }
    } else {
        throw "Can't assign";
    }
    return *this;
}

ALMatrix ALMatrix::operator+(const ALMatrix& _matrix) const {
    ALMatrix sum_res;
    if (this->rows_ == _matrix.rows_ && this->columns_ == _matrix.columns_) {
        sum_res = *this;
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
    ALMatrix compos_res;
    if (this->rows_ == _matrix.columns_ && this->columns_ == _matrix.rows_) {
        ALMatrix composition(rows_, rows_);
        for (unsigned int i = 0; i < composition.rows_; ++i) {
            for (unsigned int j = 0; j < composition.columns_; ++j) {
                for (unsigned int k = 0; k < this->columns_; ++k) {
                    composition.matrix_[i][j] = composition[i][j] +
                        this->matrix_[i][k] *_matrix.matrix_[k][j];
                }
            }
        }
        compos_res = composition;
    } else {
        throw "Can't compos";
    }
    return compos_res;
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
