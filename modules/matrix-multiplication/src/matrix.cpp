// Copyright 2017 Baranov Evgeny

#include "include/matrix.h"
#include "include/number_of_arbitrary_length.h"

ALMatrix::ALMatrix() : matrix(nullptr), rows(0), columns(0) {
}

ALMatrix::ALMatrix(unsigned int _size) : rows(_size), columns(_size) {
    if (rows != 0 && columns != 0) {
        matrix = new ALNumber*[rows];
        for (unsigned int i = 0; i < rows; ++i) {
            matrix[i] = new ALNumber[columns];
        }
    } else {
        rows = columns = 0;
        matrix = nullptr;
    }
}

ALMatrix::ALMatrix(unsigned int _rows, unsigned int _columns):
    rows(_rows), columns(_columns) {
    if (rows != 0 && columns != 0) {
        matrix = new ALNumber*[rows];
        for (unsigned int i = 0; i < rows; ++i) {
            matrix[i] = new ALNumber[columns];
        }
    } else {
        rows = columns = 0;
        matrix = nullptr;
    }
}

ALMatrix::ALMatrix(const ALMatrix & _matrix) {
    if (_matrix.columns != 0 && _matrix.rows != 0) {
        this->columns = _matrix.columns;
        this->rows = _matrix.rows;
        this->matrix = new ALNumber*[rows];
        for (unsigned int i = 0; i < rows; ++i) {
            this->matrix[i] = new ALNumber[columns];
        }
        for (unsigned int i = 0; i < rows; ++i) {
            for (unsigned int j = 0; j < columns; ++j) {
                this->matrix[i][j] = _matrix.matrix[i][j];
            }
        }
    } else {
        throw "Can't copy";
    }
}

ALMatrix::~ALMatrix() {
    for (unsigned int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr;
}

ALMatrix ALMatrix::operator=(const ALMatrix& _matrix) {
    if (_matrix.columns != 0 && _matrix.rows != 0) {
        if (columns != 0 && rows != 0) {
            for (unsigned int i = 0; i < rows; ++i) {
                delete[] matrix[i];
            }
            delete[] matrix;
        }

        this->rows = _matrix.rows;
        this->columns = _matrix.columns;
        this->matrix = new ALNumber*[rows];
        for (unsigned int i = 0; i < rows; ++i) {
            this->matrix[i] = new ALNumber[columns];
        }

        for (unsigned int i = 0; i < rows; ++i) {
            for (unsigned int j = 0; j < columns; ++j) {
                this->matrix[i][j] = _matrix.matrix[i][j];
            }
        }
    } else {
        throw "Can't assign";
    }
    return *this;
}

ALMatrix ALMatrix::operator+(const ALMatrix& _matrix) const {
    ALMatrix sum_res;
    if (this->rows == _matrix.rows && this->columns == _matrix.columns) {
        sum_res = *this;
        for (unsigned int i = 0; i < rows; ++i) {
            for (unsigned int j = 0; j < columns; ++j) {
                sum_res.matrix[i][j] =
                    sum_res.matrix[i][j] + _matrix.matrix[i][j];
            }
        }
    } else {
        throw "Can't sum";
    }
    return sum_res;
}

ALMatrix ALMatrix::operator*(const ALMatrix& _matrix) const {
    ALMatrix compos_res;
    if (this->rows == _matrix.columns && this->columns == _matrix.rows) {
        ALMatrix composition(rows, rows);
        for (unsigned int i = 0; i < composition.rows; ++i) {
            for (unsigned int j = 0; j < composition.columns; ++j) {
                for (unsigned int k = 0; k < this->columns; ++k) {
                    composition.matrix[i][j] = composition[i][j] +
                        this->matrix[i][k] *_matrix.matrix[k][j];
                }
            }
        }
        compos_res = composition;
    } else {
        throw "Can't compos";
    }
    return compos_res;
}

unsigned int ALMatrix::get_rows() const {
    return rows;
}

unsigned int ALMatrix::get_columns() const {
    return columns;
}

ALNumber* ALMatrix::operator[](unsigned int _row) const {
    if (_row >= rows) {
        throw "wrong row";
    }
    return matrix[_row];
}
