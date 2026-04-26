#include <gtest/gtest.h>
#include "../linked_list/LinkedList.hpp"
#include "../exceptions/Exceptions.hpp"

TEST(linked_list_constructor, basic_constructor_test) {
    LinkedList<int> list;
    EXPECT_EQ(list.get_length(), 0);
}

TEST(linked_list_constructor, constructor_from_array_test) {
    int arr[] = {1, 4, 6, -2};
    LinkedList<int> array(arr, 4);

    ASSERT_EQ(array.get_length(), 4);

    EXPECT_EQ(array.get(0), 1);
    EXPECT_EQ(array.get(1), 4);
    EXPECT_EQ(array.get(2), 6);
    EXPECT_EQ(array.get(3), -2);
}

TEST(linked_list_constructor, constructor_initializer_list) {
    LinkedList<int> list{100, 101, 102};
    ASSERT_EQ(list.get_length(), 3);
    EXPECT_EQ(list.get(0), 100);
    EXPECT_EQ(list.get(1), 101);
    EXPECT_EQ(list.get(2), 102);
}

TEST(linked_list_constructor, constructor_empty_initializer_list) {
    LinkedList<int> list{};
    ASSERT_EQ(list.get_length(), 0);
}

TEST(linked_list_constructor, copy_constructor) {
    int arr[] = {1, 2, 3};
    LinkedList<int> source(arr, 3);
    LinkedList<int> copy(source);

    ASSERT_EQ(copy.get_length(), 3);
    EXPECT_EQ(copy.get(0), 1);
    EXPECT_EQ(copy.get(1), 2);
    EXPECT_EQ(copy.get(2), 3);
}



TEST(linked_list_elem_getters, correct_get_size) {
    LinkedList<int> list{10, 15, 20};
    EXPECT_EQ(list.get_length(), 3);
}

TEST(linked_list_elem_getters, correct_get_first) {
    LinkedList<int> list{10, 15, 20};
    EXPECT_EQ(list.get(0), 10);
}

TEST(linked_list_elem_getters, correct_get_last) {
    LinkedList<int> list{10, 15, 20};
    EXPECT_EQ(list.get(2), 20);
}

TEST(linked_list_elem_getters, correct_get_at) {
    LinkedList<int> list{10, 15, 20};
    EXPECT_EQ(list.get(1), 15);
}

TEST(linked_list_elem_getters, get_out_of_array) {
    LinkedList<int> list{10, 15, 20};
    EXPECT_THROW(list.get(3), IndexOutOfRangeException);
}

TEST(linked_list_elem_getters, get_at_below_zero) {
    LinkedList<int> list{10, 15, 20};
    EXPECT_THROW(list.get(-1), IndexOutOfRangeException);
}

