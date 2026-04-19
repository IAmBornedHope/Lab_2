#include <gtest/gtest.h>
#include "../dynamic_array/DynamicArray.hpp"
#include "../exceptions/Exceptions.hpp"

TEST(dynamic_array_constructor, basic_constructor_test) {
    DynamicArray<int> array;
    EXPECT_EQ(array.get_size(), 0);
}

TEST(dynamic_array_constructor, constructor_from_array_test) {
    int arr[] = {1, 4, 6, -2};
    DynamicArray<int> array(arr, 4);

    ASSERT_EQ(array.get_size(), 4);

    EXPECT_EQ(array.get(0), 1);
    EXPECT_EQ(array.get(1), 4);
    EXPECT_EQ(array.get(2), 6);
    EXPECT_EQ(array.get(3), -2);
}

TEST(dynamic_array_constructor, constructor_from_array_test_2) {
    EXPECT_THROW(DynamicArray<int> array(nullptr, 4), NullPointerException);
}

TEST(dynamic_array_constructor, constructor_by_size) {
    DynamicArray<int> array(17);
    ASSERT_EQ(array.get_size(), 17);
}

TEST(dynamic_array_constructor, copy_constructor) {
    int arr[] = {1, 2, 3};
    DynamicArray<int> source(arr, 3);
    DynamicArray<int> copy(source);

    ASSERT_EQ(copy.get_size(), 3);
    EXPECT_EQ(copy.get(0), 1);
    EXPECT_EQ(copy.get(1), 2);
    EXPECT_EQ(copy.get(2), 3);
}

TEST(dynamic_array_assignment, correct_assignment) {
    int arr[] = {12, 24, 36};
    DynamicArray<int> source(arr, 3);
    DynamicArray<int> pair;

    pair = source;
    
    ASSERT_EQ(pair.get_size(), 3);
    EXPECT_EQ(pair.get(0), 12);
    EXPECT_EQ(pair.get(1), 24);
    EXPECT_EQ(pair.get(2), 36);
}

TEST(dynamic_array_assignment, self_assignment) {
    int arr[] = {1, 24, 2};
    DynamicArray<int> source(arr, 3);

    source = source;

    ASSERT_EQ(source.get_size(), 3);
    EXPECT_EQ(source.get(0), 1);
    EXPECT_EQ(source.get(1), 24);
    EXPECT_EQ(source.get(2), 2);
}

