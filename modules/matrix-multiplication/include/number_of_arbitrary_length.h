// Copyright 2017 Baranov Evgeny

#ifndef MODULES_MATRIX_MULTIPLICATION_INCLUDE_NUMBER_OF_ARBITRARY_LENGTH_H_
#define MODULES_MATRIX_MULTIPLICATION_INCLUDE_NUMBER_OF_ARBITRARY_LENGTH_H_

#include <string>
#include <iostream>

class ALNumber {
 private:
    std::string number_representation;

    unsigned int size;

    ALNumber sum(const ALNumber& _firstnum,
        const ALNumber& _secondnum) const;

    ALNumber compos(const ALNumber& _firstnum,
        const ALNumber& _secondnum) const;

 public:
    ALNumber();

    explicit ALNumber(const std::string& _str);

    ALNumber(const ALNumber& _number);

    ~ALNumber();

    bool operator == (const ALNumber& _number) const;

	bool operator == (const std::string& _str) const;

    bool operator != (const ALNumber& _number) const;

	bool operator != (const std::string& _str) const;

    ALNumber& operator = (const ALNumber& _number);

    ALNumber& operator = (const std::string& _str);

    ALNumber operator + (const ALNumber& _number) const;

    ALNumber operator + (const std::string& _number) const;

    ALNumber operator * (const ALNumber& _number) const;

    ALNumber operator * (const std::string& _number) const;

    std::string getValue() const;

    friend std::ostream& operator << (std::ostream& os,
        const ALNumber& _number);

    friend std::istream& operator >> (std::istream& is,
        ALNumber& _number);
};
#endif  // MODULES_MATRIX_MULTIPLICATION_INCLUDE_NUMBER_OF_ARBITRARY_LENGTH_H_
