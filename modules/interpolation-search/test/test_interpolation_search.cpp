// Copyright 2017 Yashkov Vladislav

#include <gtest/gtest.h>

#include "include/interpolation_search.h"

TEST(InterpolationSearch, Can_Create_Search) {
  const int length = 3;
  int * sortedArray = new int[length] {1, 2, 3};
  ASSERT_NO_THROW(InterpolationSearch interpolationSearch(sortedArray, length));
}

TEST(InterpolationSearch, Throws_When_Array_Unsorted) {
  const int len = 3;
  int * unSortedArr = new int[len] {3, 2, 1};
  ASSERT_ANY_THROW(InterpolationSearch interpolationSearch(unSortedArr, len));
}

TEST(InterpolationSearch, No_Throws_When_Array_Sorted) {
  const int len = 3;
  int * sortedArr = new int[len] {1, 2, 3};
  ASSERT_NO_THROW(InterpolationSearch interpolationSearch(sortedArr, len));
}

TEST(InterpolationSearch, Cant_Create_Search_With_Null_Array) {
  const int length = 3;
  ASSERT_ANY_THROW(InterpolationSearch interpolationSearch(NULL, length));
}

TEST(InterpolationSearch, Cant_Create_Search_With_Negative_Array_Lenght) {
  const int length = 3;
  int * sortedArray = new int[length] {1, 2, 3};
  ASSERT_ANY_THROW(InterpolationSearch interpolationSearch(sortedArray, -1));
}

TEST(InterpolationSearch, Cant_Create_Search_With_Zero_Array_Lenght) {
  const int len = 0;
  int * sortedArray = new int[len];
  ASSERT_ANY_THROW(InterpolationSearch interpolationSearch(sortedArray, len));
}

TEST(InterpolationSearch, Can_Set_Array) {
  const int length = 3;
  int * sortedArray1 = new int[length] {1, 2, 3};
  int * sortedArray2 = new int[length] {2, 3, 4};
  InterpolationSearch interpolationSearch(sortedArray1, length);
  ASSERT_NO_THROW(interpolationSearch.SetArray(sortedArray2, length));
}

TEST(InterpolationSearch, Search_Return_Missing) {
  const int length = 3;
  int * sortedArray = new int[length] {1, 2, 3};
  InterpolationSearch interpolationSearch(sortedArray, length);
  EXPECT_EQ(-1, interpolationSearch.Search(4));
}

TEST(InterpolationSearch, Search_Return_Low) {
  const int length = 3;
  int * sortedArray = new int[length] {1, 2, 3};
  InterpolationSearch interpolationSearch(sortedArray, length);
  EXPECT_EQ(0, interpolationSearch.Search(1));
}

TEST(InterpolationSearch, Search_Return_Mid) {
  const int length = 3;
  int * sortedArray = new int[length] {1, 2, 3};
  InterpolationSearch interpolationSearch(sortedArray, length);
  EXPECT_EQ(1, interpolationSearch.Search(2));
}

TEST(InterpolationSearch, Search_Return_Mid_From_Low) {
  const int length = 4;
  int * sortedArray = new int[length] {5, 6, 7, 20};
  InterpolationSearch interpolationSearch(sortedArray, length);
  EXPECT_EQ(2, interpolationSearch.Search(7));
}

TEST(InterpolationSearch, Search_Return_Mid_From_High) {
  const int length = 4;
  int * sortedArray = new int[length] {5, 17, 19, 20};
  InterpolationSearch interpolationSearch(sortedArray, length);
  EXPECT_EQ(1, interpolationSearch.Search(17));
}

TEST(InterpolationSearch, Search_Return_High) {
  const int length = 3;
  int * sortedArray = new int[length] {1, 2, 3};
  InterpolationSearch interpolationSearch(sortedArray, length);
  EXPECT_EQ(2, interpolationSearch.Search(3));
}

TEST(InterpolationSearch, Cant_Search_With_Unsorted_Array) {
  const int length = 3;
  int * sortedArray = new int[length] {1, 2, 3};
  InterpolationSearch interpolationSearch(sortedArray, length);
  sortedArray[1] = 5;
  ASSERT_ANY_THROW(interpolationSearch.Search(1));
}
