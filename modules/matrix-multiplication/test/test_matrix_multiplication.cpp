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

TEST(Baranov_Evgeny_MatrixMultiplicationTest, correct_num_str_comparison1) {
    // Arrange
    ALNumber number1("123");
    std::string number2("123");
    // Act
    bool flag = number1 == number2;
    // Assert
    EXPECT_EQ(1, flag);
}

TEST(Baranov_Evgeny_MatrixMultiplicationTest, correct_num_str_comparison2) {
    // Arrange
    ALNumber number1("123");
    std::string number2("213");
    bool flag;
    // Act
    flag = (number1 == number2);
    // Assert
    EXPECT_EQ(0, flag);
}

TEST(Baranov_Evgeny_MatrixMultiplicationTest, correct_num_str_comparison3) {
    // Arrange
    ALNumber number1("123");
    std::string number2("123");
    bool flag;
    // Act
    flag = (number1 != number2);
    // Assert
    EXPECT_EQ(0, flag);
}

TEST(Baranov_Evgeny_MatrixMultiplicationTest, correct_num_str_comparison4) {
    // Arrange
    ALNumber number1("123");
    std::string number2("213");
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

TEST(Baranov_Evgeny_MatrixMultiplicationTest, can_assign_equal_nums) {
    // Arrange
    ALNumber number1("123");
    ALNumber number2("123");
    // Act
    number1 = number2;
    // Assert
    EXPECT_EQ("123", number1.getValue());
}

TEST(Baranov_Evgeny_MatrixMultiplicationTest, can_correct_assign_str) {
    // Arrange
    ALNumber number1;
    // Act
    number1 = "465456456545645";
    // Assert
    EXPECT_EQ("465456456545645", number1.getValue());
}

TEST(Baranov_Evgeny_MatrixMultiplicationTest, can_correct_assign_equal_str) {
    // Arrange
    ALNumber number1("465456456545645");
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

TEST(Baranov_Evgeny_MatrixMultiplicationTest, can_create_matrix1) {
    // Arrange
    // Act
    // Assert
    ASSERT_NO_THROW(ALMatrix matrix(4));
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

TEST(Baranov_Evgeny_MatrixMultiplicationTest, can_correct_set_matrix) {
    // Arrange
    ALMatrix matrix(3, 4);
    ALNumber expected("11");
    // Act
    matrix[1][2] = "11";
    // Assert
    EXPECT_EQ(expected, matrix[1][2]);
}

TEST(Baranov_Evgeny_MatrixMultiplicationTest, can_correct_assign_matrixes) {
    // Arrange
    ALMatrix matrix1(3, 4);
    ALMatrix matrix2;
    ALNumber expected("2");
    // Act
    matrix1[1][2] = "2";
    matrix2 = matrix1;
    // Assert
    EXPECT_EQ(expected, matrix2[1][2]);
}

TEST(Baranov_Evgeny_MatrixMultiplicationTest, can_correct_sum_matrixes) {
    // Arrange
    ALMatrix matrix1(3, 4);
    ALMatrix matrix2(3, 4);
    ALMatrix sum_matrixes;
    ALMatrix result(3, 4);
    bool flag(true);
    // Act
    for (unsigned int i = 0; i < 3; ++i) {
        for (unsigned int j = 0; j < 4; ++j) {
            matrix1[i][j] = "990";
            matrix2[i][j] = "120";
            result[i][j] = "1110";
        }
    }
    sum_matrixes = matrix1 + matrix2;
    for (unsigned int i = 0; i < 3; ++i) {
        for (unsigned int j = 0; j < 4; ++j) {
            if (sum_matrixes[i][j] != result[i][j]) {
                flag = false;
                break;
            }
        }
    }
    // Assert
    EXPECT_EQ(1, flag);
}

TEST(Baranov_Evgeny_MatrixMultiplicationTest, can_correct_compos_matrixes) {
    // Arrange
    ALMatrix matrix1(3, 4);
    ALMatrix matrix2(4, 3);
    ALMatrix compos_matrixes;
    ALMatrix result(3, 3);
    bool flag(true);
    // Act
    for (unsigned int i = 0; i < matrix1.get_rows(); ++i) {
        for (unsigned int j = 0; j < matrix1.get_columns(); ++j) {
            matrix1[i][j] = "23";
        }
    }
    for (unsigned int i = 0; i < matrix2.get_rows(); ++i) {
        for (unsigned int j = 0; j < matrix2.get_columns(); ++j) {
            matrix2[i][j] = "23";
        }
    }
    for (unsigned int i = 0; i < result.get_rows(); ++i) {
        for (unsigned int j = 0; j < result.get_columns(); ++j) {
            result[i][j] = "2116";
        }
    }
    compos_matrixes = matrix1 * matrix2;
    for (unsigned int i = 0; i < compos_matrixes.get_rows(); ++i) {
        for (unsigned int j = 0; j < compos_matrixes.get_columns(); ++j) {
            if (compos_matrixes[i][j] != result[i][j]) {
                flag = false;
                break;
            }
        }
    }
    // Assert
    EXPECT_EQ(1, flag);
}

TEST(Baranov_Evgeny_MatrixMultiplicationTest, can_create_copy_matrix) {
    // Arrange
    ALMatrix matrix1(3, 4);
    bool flag(true);
    // Act
    for (unsigned int i = 0; i < matrix1.get_rows(); ++i) {
        for (unsigned int j = 0; j < matrix1.get_columns(); ++j) {
            matrix1[i][j] = "23";
        }
    }
    ALMatrix matrix2(matrix1);
    for (unsigned int i = 0; i < matrix2.get_rows(); ++i) {
        for (unsigned int j = 0; j < matrix2.get_columns(); ++j) {
            if (matrix2[i][j] != matrix1[i][j]) {
                flag = false;
                break;
            }
        }
    }
    // Assert
    EXPECT_EQ(1, flag);
}

TEST(Baranov_Evgeny_MatrixMultiplicationTest, cant_compos_wrong_matrixes) {
    // Arrange
    ALMatrix matrix1(3, 4);
    ALMatrix matrix2(3, 3);
    // Act
    for (unsigned int i = 0; i < matrix1.get_rows(); ++i) {
        for (unsigned int j = 0; j < matrix1.get_columns(); ++j) {
            matrix1[i][j] = "23";
        }
    }
    for (unsigned int i = 0; i < matrix2.get_rows(); ++i) {
        for (unsigned int j = 0; j < matrix2.get_columns(); ++j) {
            matrix2[i][j] = "23";
        }
    }
    // Assert
    ASSERT_ANY_THROW(matrix1*matrix2);
}

TEST(Baranov_Evgeny_MatrixMultiplicationTest, cant_sum_wrong_matrixes) {
    // Arrange
    ALMatrix matrix1(3, 4);
    ALMatrix matrix2(3, 3);
    // Act
    for (unsigned int i = 0; i < matrix1.get_rows(); ++i) {
        for (unsigned int j = 0; j < matrix1.get_columns(); ++j) {
            matrix1[i][j] = "23";
        }
    }
    for (unsigned int i = 0; i < matrix2.get_rows(); ++i) {
        for (unsigned int j = 0; j < matrix2.get_columns(); ++j) {
            matrix2[i][j] = "23";
        }
    }
    // Assert
    ASSERT_ANY_THROW(matrix1+matrix2);
}

TEST(Baranov_Evgeny_MatrixMultiplicationTest, cant_use_wrong_indexation) {
    // Arrange
    ALMatrix matrix1(3, 4);
    // Act
    // Assert
    ASSERT_ANY_THROW(matrix1[4][1]);
}
