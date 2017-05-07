// Copyright 2017 Baranov Evgeny

#include <gtest/gtest.h>

#include <string>
#include <utility>

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

TEST(Baranov_Evgeny_MatrixMultiplicationTest, can_correct_get_value) {
    // Arrange
    ALNumber number1("12");
    std::string num;
    // Act
    num = number1.getValue();
    // Assert
    EXPECT_EQ("12", num);
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
    // Assert
    ASSERT_NO_THROW(ALNumber number2(number1));
}

TEST(Baranov_Evgeny_MatrixMultiplicationTest, copy_eq_source_num) {
    // Arrange
    ALNumber number1("11124654846321654612");
    // Act
    ALNumber number2(number1);
    // Assert
    EXPECT_EQ("11124654846321654612", number2.getValue());
}

TEST(Baranov_Evgeny_MatrixMultiplicationTest, correct_num_comparison1) {
    // Arrange
    ALNumber number1("123");
    ALNumber number2("123");
    // Act
    bool flag = number1 == number2;
    // Assert
    EXPECT_EQ(1, flag);
}

TEST(Baranov_Evgeny_MatrixMultiplicationTest, correct_num_comparison2) {
    // Arrange
    ALNumber number1("123");
    ALNumber number2("213");
    bool flag;
    // Act
    flag = (number1 == number2);
    // Assert
    EXPECT_EQ(0, flag);
}

TEST(Baranov_Evgeny_MatrixMultiplicationTest, correct_num_comparison3) {
    // Arrange
    ALNumber number1("123");
    ALNumber number2("123");
    bool flag;
    // Act
    flag = (number1 != number2);
    // Assert
    EXPECT_EQ(0, flag);
}

TEST(Baranov_Evgeny_MatrixMultiplicationTest, correct_num_comparison4) {
    // Arrange
    ALNumber number1("123");
    ALNumber number2("213");
    // Act
    bool flag = number1 != number2;
    // Assert
    EXPECT_EQ(1, flag);
}

TEST(Baranov_Evgeny_MatrixMultiplicationTest, can_correct_assign_num) {
    // Arrange
    ALNumber number1("123");
    ALNumber number2("1");
    // Act
    number1 = number2;
    // Assert
    EXPECT_EQ("1", number1.getValue());
}

TEST(Baranov_Evgeny_MatrixMultiplicationTest, can_correct_assign_str) {
    // Arrange
    ALNumber number1;
    // Act
    number1 = "465456456545645";
    // Assert
    EXPECT_EQ("465456456545645", number1.getValue());
}

TEST(Baranov_Evgeny_MatrixMultiplicationTest, cant_assign_corrupted_str) {
    // Arrange
    ALNumber number1;
    // Act
    // Assert
    ASSERT_ANY_THROW(number1 = "4654s56456as54564s5");
}

TEST(Baranov_Evgeny_MatrixMultiplicationTest, can_correct_sum) {
    // Arrange
    ALNumber number1("1");
    ALNumber number2("1");
    ALNumber number3;
    // Act
    number3 = number1 + number2;
    // Assert
    EXPECT_EQ("2", number3.getValue());
}

TEST(Baranov_Evgeny_MatrixMultiplicationTest, can_correct_compos_nums) {
    // Arrange
    ALNumber number1("12");
    ALNumber number2("33");
    ALNumber number3;
    // Act
    number3 = number1 * number2;
    // Assert
    EXPECT_EQ("396", number3.getValue());
}

TEST(Baranov_Evgeny_MatrixMultiplicationTest, can_correct_compos_str) {
    // Arrange
    ALNumber number1("12");
    ALNumber number3;
    // Act
    number3 = number1 * "33";
    // Assert
    EXPECT_EQ("396", number3.getValue());
}

TEST(Baranov_Evgeny_MatrixMultiplicationTest, can_create_matrix) {
    // Arrange
    // Act
    // Assert
    ASSERT_NO_THROW(ALMatrix matrix);
}

TEST(Baranov_Evgeny_MatrixMultiplicationTest, can_create_matrix2) {
    // Arrange
    // Act
    // Assert
    ASSERT_NO_THROW(ALMatrix matrix(3, 4));
}

TEST(Baranov_Evgeny_MatrixMultiplicationTest, can_correct_get_row) {
    // Arrange
    ALMatrix matrix(3, 4);
    // Act
    // Assert
    EXPECT_EQ(3, matrix.get_rows());
}

TEST(Baranov_Evgeny_MatrixMultiplicationTest, can_correct_get_columns) {
    // Arrange
    ALMatrix matrix(3, 4);
    // Act
    // Assert
    EXPECT_EQ(4, matrix.get_columns());
}

TEST(Baranov_Evgeny_MatrixMultiplicationTest, can_create_matrix_correct) {
    // Arrange
    ALMatrix matrix(3, 4);
    std::pair<int, int> rows_columns;
    std::pair<int, int> result;
    // Act
    rows_columns.first = matrix.get_rows();
    result.first = 3;
    rows_columns.second = matrix.get_columns();
    result.second = 4;
    // Assert
    EXPECT_EQ(result, rows_columns);
}

TEST(Baranov_Evgeny_MatrixMultiplicationTest, can_create_matrix_correct) {
    // Arrange
    ALMatrix matrix(3, 4);
    ALNumber result;
    // Act
    matrix[1][2] = "2";
    result = matrix[1][2];
    // Assert
    EXPECT_EQ("2", result);
}
