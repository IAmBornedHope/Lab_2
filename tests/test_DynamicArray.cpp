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



TEST(dynamic_array_elem_getters, correct_get_size) {
    int arr[] = {10, 15, 20};
    DynamicArray<int> array(arr, 3);
    EXPECT_EQ(array.get_size(), 3);
}

TEST(dynamic_array_elem_getters, correct_get_first) {
    int arr[] = {10, 15, 20};
    DynamicArray<int> array(arr, 3);
    EXPECT_EQ(array.get(0), 10);
}

TEST(dynamic_array_elem_getters, correct_get_last) {
    int arr[] = {10, 15, 20};
    DynamicArray<int> array(arr, 3);
    EXPECT_EQ(array.get(2), 20);
}

TEST(dynamic_array_elem_getters, correct_get_at) {
    int arr[] = {10, 15, 20};
    DynamicArray<int> array(arr, 3);
    EXPECT_EQ(array.get(1), 15);
}

TEST(dynamic_array_elem_getters, get_out_of_array) {
    int arr[] = {10, 15, 20};
    DynamicArray<int> array(arr, 3);
    EXPECT_THROW(array.get(3), IndexOutOfRangeException);
}

TEST(dynamic_array_elem_getters, get_at_below_zero) {
    int arr[] = {10, 15, 20};
    DynamicArray<int> array(arr, 3);
    EXPECT_THROW(array.get(-1), IndexOutOfRangeException);
}



TEST(dynamic_array_ref_getters, correct_get_ref_first) {
    int arr[] = {10, 15, 20};
    DynamicArray<int> array(arr, 3);
    int& reference = array.get_reference(0);
    reference = 67;
    EXPECT_EQ(array.get(0), 67);
}

TEST(dynamic_array_ref_getters, correct_get_ref_last) {
    int arr[] = {10, 15, 20};
    DynamicArray<int> array(arr, 3);
    int& reference = array.get_reference(2);
    reference = 17;
    EXPECT_EQ(array.get(2), 17);
}

TEST(dynamic_array_ref_getters, correct_get_ref_at) {
    int arr[] = {10, 15, 20};
    DynamicArray<int> array(arr, 3);
    int& reference = array.get_reference(1);
    reference = 3;
    EXPECT_EQ(array.get(1), 3);
}

TEST(dynamic_array_ref_getters, get_ref_out_of_array) {
    int arr[] = {10, 15, 20};
    DynamicArray<int> array(arr, 3);
    EXPECT_THROW(array.get_reference(5), IndexOutOfRangeException);
}

TEST(dynamic_array_ref_getters, get_ref_below_zero) {
    int arr[] = {10, 15, 20};
    DynamicArray<int> array(arr, 3);
    EXPECT_THROW(array.get_reference(-1), IndexOutOfRangeException);
}



TEST(dynamic_array_data_getters, correct_get_data) {
    int arr[] = {10, 15, 20};
    DynamicArray<int> array(arr, 3);

    int* data = array.get_data();

    EXPECT_EQ(data[0], 10);
    EXPECT_EQ(data[1], 15);
    EXPECT_EQ(data[2], 20);
}

TEST(dynamic_array_data_getters, correct_get_data_from_empty) {
    DynamicArray<int> array;
    int* data = array.get_data();
    EXPECT_EQ(data, nullptr);
}



TEST(dynamic_array_setters, correct_set_first) {
    int arr[] = {1, 5, 10};
    DynamicArray<int> array(arr, 3);
    array.set(0, 999);
    EXPECT_EQ(array.get(0), 999);
}

TEST(dynamic_array_setters, correct_set_last) {
    int arr[] = {1, 5, 10};
    DynamicArray<int> array(arr, 3);
    array.set(2, 999);
    EXPECT_EQ(array.get(2), 999);
}

TEST(dynamic_array_setters, correct_set_at) {
    int arr[] = {1, 5, 10};
    DynamicArray<int> array(arr, 3);
    array.set(1, 999);
    EXPECT_EQ(array.get(1), 999);
}

TEST(dynamic_array_setters, set_at_out_of_array) {
    int arr[] = {1, 5, 10};
    DynamicArray<int> array(arr, 3);
    EXPECT_THROW(array.set(5, 999), IndexOutOfRangeException);
}

TEST(dynamic_array_setters, set_at_below_zero) {
    int arr[] = {1, 5, 10};
    DynamicArray<int> array(arr, 3);
    EXPECT_THROW(array.set(-1, 999), IndexOutOfRangeException);
}



TEST(dynamic_array_resize, correct_resize_bigger) {
    int arr[] = {1, 5, 10};
    DynamicArray<int> array(arr, 3);
    array.resize(10);

    ASSERT_EQ(array.get_size(), 10);
    EXPECT_EQ(array.get(0), 1);
    EXPECT_EQ(array.get(1), 5);
    EXPECT_EQ(array.get(2), 10);
}

TEST(dynamic_array_resize, correct_resize_smaller) {
    int arr[] = {1, 5, 10, 15, 20};
    DynamicArray<int> array(arr, 5);
    array.resize(3);

    ASSERT_EQ(array.get_size(), 3);
    EXPECT_EQ(array.get(0), 1);
    EXPECT_EQ(array.get(1), 5);
    EXPECT_EQ(array.get(2), 10);
    EXPECT_THROW(array.get(3), IndexOutOfRangeException);
}

TEST(dynamic_array_resize, correct_resize_same_size) {
    int arr[] = {1, 5, 10};
    DynamicArray<int> array(arr, 3);
    array.resize(3);

    ASSERT_EQ(array.get_size(), 3);
    EXPECT_EQ(array.get(0), 1);
    EXPECT_EQ(array.get(1), 5);
    EXPECT_EQ(array.get(2), 10);
    EXPECT_THROW(array.get(3), IndexOutOfRangeException);
}

TEST(dynamic_array_resize, correct_resize_zero_size) {
    int arr[] = {1, 5, 10};
    DynamicArray<int> array(arr, 3);
    array.resize(0);

    ASSERT_EQ(array.get_size(), 0);
    EXPECT_THROW(array.get(0), IndexOutOfRangeException);
}


