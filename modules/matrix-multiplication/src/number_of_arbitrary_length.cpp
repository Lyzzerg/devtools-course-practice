// Copyright 2017 Baranov Evgeny

#include "include/number_of_arbitrary_length.h"

#include <string>
#include <algorithm>
#include <locale>

ALNumber ALNumber::Sum(const ALNumber & _firstnum,
    const ALNumber & _secondnum) const {
    ALNumber sum_res;
    std::string suming;
    int i(_firstnum.size_ - 1);
    int j(_secondnum.size_ - 1);
    int sum(0);
    char temp;
    while ((i > -1) || (j > -1)) {
        temp = (i > -1) ? _firstnum.number_representation_[i] : '0';
        sum += std::atoi(&temp);
        temp = (j > -1) ? _secondnum.number_representation_[j] : '0';
        sum += std::atoi(&temp);
        suming += std::to_string(sum % 10);
        sum /= 10;
        i--;
        j--;
    }
    if (sum != 0) {
        suming += std::to_string(sum % 10);
    }
    std::reverse(suming.rbegin(), suming.rend());
    return sum_res = suming;
}

ALNumber ALNumber::Compos(const ALNumber & _firstnum,
    const ALNumber & _secondnum) const {
    ALNumber compos_res;
    std::string multiplication;
    int i(_firstnum.size_ >= _secondnum.size_ ?
        _firstnum.size_ - 1 : _secondnum.size_ - 1);
    int j(_firstnum.size_ >= _secondnum.size_ ?
        _secondnum.size_ - 1 : _firstnum.size_ - 1);
    int compos(0);
    char temp;
    while (i > -1) {
        while (j > -1) {
            temp = _firstnum.size_ >= _secondnum.size_ ?
                _secondnum.number_representation_[j] :
                _firstnum.number_representation_[j];
            compos = std::atoi(&temp);
            temp = _firstnum.size_ >= _secondnum.size_ ?
                _firstnum.number_representation_[i] :
                _secondnum.number_representation_[i];
            compos *= std::atoi(&temp);
            multiplication += std::to_string(compos);
            compos = 0;
            j--;
        }
        if (_secondnum.size_ > 1 && _firstnum.size_ > 1)
            std::reverse(multiplication.begin(), multiplication.end());
        for (unsigned int k = 0; k < (_firstnum.size_ >= _secondnum.size_ ?
            _firstnum.size_ : _secondnum.size_) - 1 - i; ++k)
            multiplication += '0';
        compos_res = compos_res + multiplication;
        multiplication.clear();
        i--;
        j = _firstnum.size_ >= _secondnum.size_ ?
            _secondnum.size_ - 1 : _firstnum.size_ - 1;
    }
    return compos_res = multiplication;
}

ALNumber::ALNumber() : number_representation_("0"), size_(1) {}

ALNumber::ALNumber(const std::string & _str)
    : number_representation_("0"), size_(1) {
    bool isNumber(true);
    for (unsigned int i = 0; i < _str.length(); i++) {
        if (!isdigit(_str[i])) {
            isNumber = false;
            break;
        }
    }
    if (!isNumber) {
        throw "STR isn't a number";
    } else {
       size_ = _str.length();
       number_representation_ = _str;
    }
}

ALNumber::ALNumber(const ALNumber & _number) {
    this->size_ = _number.size_;
    this->number_representation_ = _number.number_representation_;
}

ALNumber::~ALNumber() {}

bool ALNumber::operator==(const ALNumber & _number) const {
    bool res(true);
    if (this->size_ == _number.size_) {
        if (this->number_representation_ != _number.number_representation_) {
            res = false;
        }
    } else {
        res = false;
    }
    return res;
}

bool ALNumber::operator==(const std::string & _str) const {
    bool result(true);
    if (this->number_representation_ != _str) {
        result = false;
    }
    return result;
}

bool ALNumber::operator!=(const ALNumber & _number) const {
    return !(*this == _number);
}

bool ALNumber::operator!=(const std::string & _str) const {
    return !(*this == _str);
}

ALNumber & ALNumber::operator=(const ALNumber & _number) {
    if ((this->size_ != _number.size_) ||
        (this->number_representation_ != _number.number_representation_)) {
        this->size_ = _number.size_;
        this->number_representation_ = _number.number_representation_;
    }
    return *this;
}

ALNumber & ALNumber::operator=(const std::string & _str) {
    if ((this->number_representation_ != _str) && (_str.length() != 0)) {
        ALNumber number(_str);
        *this = number;
    }
    return *this;
}

ALNumber ALNumber::operator+(const ALNumber & _number) const {
    return Sum(*this, _number);
}

ALNumber ALNumber::operator+(const std::string & _number) const {
    ALNumber temp(_number);
    return *this + temp;
}

ALNumber ALNumber::operator*(const ALNumber & _number) const {
    return Compos(*this, _number);
}

ALNumber ALNumber::operator*(const std::string & _number) const {
    ALNumber temp(_number);
    return Compos(*this, temp);
}

std::string ALNumber::GetValue() const {
    return number_representation_;
}
