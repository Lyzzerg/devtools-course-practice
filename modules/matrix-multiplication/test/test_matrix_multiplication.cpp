// Copyright 2017 Baranov Evgeny

#include <gtest/gtest.h>

#include <string>

#include "include/number_of_arbitrary_length.h"
#include "include/matrix.h"

TEST(Baranov_Evgeny_MatrixMultiplicationTest, can_create_num) {
    // Arrange
    // Act
    // Assert
    ASSERT_NO_THROW(ALNumber number);
}

TEST(Baranov_Evgeny_MatrixMultiplicationTest, can_create_num_as_str) {
    // Arrange
    std::string str = "123";
    // Act
    // Assert
    ASSERT_NO_THROW(ALNumber number(str));
}

TEST(Baranov_Evgeny_MatrixMultiplicationTest, corr_create_num_as_str) {
    // Arrange
    std::string str = "123";
    // Act
    ALNumber number(str);
    // Assert
    EXPECT_EQ("123", number.getValue());
}

TEST(Baranov_Evgeny_MatrixMultiplicationTest, corr_create_big_num_as_str) {
    // Arrange
    std::string str = "1234567891011121314151617181920212223242526";
    // Act
    ALNumber number(str);
    // Assert
    EXPECT_EQ("1234567891011121314151617181920212223242526", number.getValue());
}

TEST(Baranov_Evgeny_MatrixMultiplicationTest, cant_create_trash_num) {
    // Arrange
    std::string str = "12345s91011121314a1819202122d2526";
    // Act
    // Assert
    ASSERT_ANY_THROW(ALNumber number(str));
}

TEST(Baranov_Evgeny_MatrixMultiplicationTest, can_create_copy_num) {
    // Arrange
    ALNumber number1("11124654846321654612");
    // Act
    ALNumber number2(number1);
    // Assert
    ASSERT_ANY_THROW(ALNumber number2(number1));
}
