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
