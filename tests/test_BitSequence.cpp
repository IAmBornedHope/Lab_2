#include <gtest/gtest.h>
#include "../bit_sequence/BitSequence.hpp"
#include "../exceptions/Exceptions.hpp"


TEST(bit_sequence_constructor, basic_constructor_test) {
    BitSequence<int> sequence;
    EXPECT_EQ(sequence.get_length(), 0);
}

TEST(bit_sequence_constructor, constructor_from_array_test) {
    bool array[] = {1, 0, 0, 1};
    BitSequence<int> sequence(array, 4);

    ASSERT_EQ(sequence.get_length(), 4);

    EXPECT_EQ(sequence.get_bit_at(0), 1);
    EXPECT_EQ(sequence.get_bit_at(1), 0);
    EXPECT_EQ(sequence.get_bit_at(2), 0);
    EXPECT_EQ(sequence.get_bit_at(3), 1);
}

TEST(bit_sequence_constructor, constructor_from_array_test_2) {
    EXPECT_THROW(BitSequence<int> array(nullptr, 4), NullPointerException);
}

TEST(bit_sequence_constructor, constructor_by_size) {
    BitSequence<int> sequence(17);
    ASSERT_EQ(sequence.get_length(), 17);
}

TEST(bit_sequence_constructor, copy_constructor) {
    bool array[] = {1, 0, 1};
    BitSequence<int> source(array, 3);
    BitSequence<int> copy(source);

    ASSERT_EQ(copy.get_length(), 3);
    EXPECT_EQ(copy.get_bit_at(0), 1);
    EXPECT_EQ(copy.get_bit_at(1), 0);
    EXPECT_EQ(copy.get_bit_at(2), 1);
}



TEST(bit_sequence_elem_getters, correct_get_length) {
    bool array[] = {0, 1, 0};
    BitSequence<int> sequence(array, 3);
    EXPECT_EQ(sequence.get_length(), 3);
}

TEST(bit_sequence_elem_getters, correct_get_first) {
    bool array[] = {1, 1, 1};
    BitSequence<int> sequence(array, 3);
    EXPECT_EQ(sequence.get_bit_at(1), 1);
}

TEST(bit_sequence_elem_getters, correct_get_last) {
    bool array[] = {1, 1, 1};
    BitSequence<int> sequence(array, 3);
    EXPECT_EQ(sequence.get_bit_at(2), 1);
}

TEST(bit_sequence_elem_getters, correct_get_at) {
    bool array[] = {1, 1, 1};
    BitSequence<int> sequence(array, 3);
    EXPECT_EQ(sequence.get_bit_at(1), 1);
}

TEST(bit_sequence_elem_getters, get_out_of_sequence) {
    bool array[] = {1, 1, 1};
    BitSequence<int> sequence(array, 3);
    EXPECT_THROW(sequence.get_bit_at(3), IndexOutOfRangeException);
}

TEST(bit_sequence_elem_getters, get_below_zero) {
    bool array[] = {1, 1, 1};
    BitSequence<int> sequence(array, 3);
    EXPECT_THROW(sequence.get_bit_at(-1), IndexOutOfRangeException);
}

TEST(bit_sequence_elem_getters, get_from_empty) {
    BitSequence<int> sequence(0);
    EXPECT_THROW(sequence.get_bit_at(0), IndexOutOfRangeException);
    EXPECT_THROW(sequence.get_first(), EmptyListException);
    EXPECT_THROW(sequence.get_last(), EmptyListException);
}



TEST(bit_sequence_setters, correct_set_first) {
    bool array[] = {1, 0, 0};
    BitSequence<int> sequence(array, 3);
    sequence.set_bit_at(0, 0);
    EXPECT_EQ(sequence.get_bit_at(0), 0);
}

TEST(bit_sequence_setters, correct_set_last) {
    bool array[] = {1, 0, 0};
    BitSequence<int> sequence(array, 3);
    sequence.set_bit_at(2, 1);
    EXPECT_EQ(sequence.get_bit_at(2), 1);
}

TEST(bit_sequence_setters, correct_set_at) {
    bool array[] = {1, 0, 0};
    BitSequence<int> sequence(array, 3);
    sequence.set_bit_at(1, 1);
    EXPECT_EQ(sequence.get_bit_at(1), 1);
}

TEST(bit_sequence_setters, set_at_out_of_sequence) {
    BitSequence<int> sequence(3);
    EXPECT_THROW(sequence.set_bit_at(4, 1), IndexOutOfRangeException);
}

TEST(bit_sequence_setters, set_at_below_zero) {
    BitSequence<int> sequence(3);
    EXPECT_THROW(sequence.set_bit_at(-1, 1), IndexOutOfRangeException);
}



TEST(bit_sequence_inserts, correct_append) {
    bool array[] = {1, 0, 0};
    BitSequence<int> sequence(array, 3);
    sequence.append(Bit<int>(1));

    ASSERT_EQ(sequence.get_length(), 4);
    EXPECT_EQ(sequence.get_bit_at(3), 1);
}

TEST(bit_sequence_inserts, correct_prepend) {
    bool array[] = {0, 1, 0};
    BitSequence<int> sequence(array, 3);
    sequence.prepend(Bit<int>(1));

    ASSERT_EQ(sequence.get_length(), 4);
    EXPECT_EQ(sequence.get_bit_at(0), 1);
}

TEST(bit_sequence_inserts, correct_insert_at) {
    bool array[] = {1, 0, 1};
    BitSequence<int> sequence(array, 3);
    sequence.insert_at(Bit<int>(1), 1);

    ASSERT_EQ(sequence.get_length(), 4);
    EXPECT_EQ(sequence.get_bit_at(1), 1);
}

TEST(bit_sequence_inserts, insert_out_of_sequence) {
    BitSequence<int> sequence(3);
    EXPECT_THROW(sequence.insert_at(Bit<int>(1), 4), IndexOutOfRangeException);
}

TEST(bit_sequence_inserts, insert_below_zero) {
    BitSequence<int> sequence(3);
    EXPECT_THROW(sequence.insert_at(Bit<int>(1), -1), IndexOutOfRangeException);
}



TEST(bit_sequence_operations, correct_subsequence) {
    bool array[] = {0, 0, 1, 1, 0};

    BitSequence<int> sequence(array, 5);
    Sequence<Bit<int>>* subsequence = sequence.get_subsequence(0, 3);

    ASSERT_EQ(subsequence->get_length(), 4);
    EXPECT_EQ(subsequence->get(0).get_bit_at(0), 0);
    EXPECT_EQ(subsequence->get(1).get_bit_at(0), 0);
    EXPECT_EQ(subsequence->get(2).get_bit_at(0), 1);
    EXPECT_EQ(subsequence->get(3).get_bit_at(0), 1);
    delete subsequence;
}

TEST(bit_sequence_operations, incorrect_subsequence) {
    bool array[] = {0, 0, 1, 1, 0};

    BitSequence<int> sequence(array, 5);
    EXPECT_THROW(sequence.get_subsequence(0, 6), IndexOutOfRangeException);
}

TEST(bit_sequence_operations, correct_concat) {
    bool array_1[] = {0, 1};
    bool array_2[] = {1, 0};

    BitSequence<int> first(array_1, 2);
    BitSequence<int> second(array_2, 2);

    Sequence<Bit<int>>* result = first.concat(&second);

    ASSERT_EQ(result->get_length(), 4);
    EXPECT_EQ(result->get(0).get_bit_at(0), 0);
    EXPECT_EQ(result->get(1).get_bit_at(0), 1);
    EXPECT_EQ(result->get(2).get_bit_at(0), 1);
    EXPECT_EQ(result->get(3).get_bit_at(0), 0);
    delete result;
}

TEST(bit_sequence_operations, concat_nullptr) {
    bool array[] = {0, 1};
    BitSequence<int> sequence(array, 2);
    EXPECT_THROW(sequence.concat(nullptr), NullPointerException);
}

TEST(bit_sequence_operations, correct_and_operation) {
    bool array_1[] = {0, 0, 1, 1};
    bool array_2[] = {0, 1, 0, 1};

    BitSequence<int> first(array_1, 4);
    BitSequence<int> second(array_2, 4);

    BitSequence<int>* result = first.And(second);

    EXPECT_EQ(result->get_bit_at(0), 0);
    EXPECT_EQ(result->get_bit_at(1), 0);
    EXPECT_EQ(result->get_bit_at(2), 0);
    EXPECT_EQ(result->get_bit_at(3), 1);
    delete result;
}

TEST(bit_sequence_operations, correct_or_operation) {
    bool array_1[] = {0, 0, 1, 1};
    bool array_2[] = {0, 1, 0, 1};

    BitSequence<int> first(array_1, 4);
    BitSequence<int> second(array_2, 4);

    BitSequence<int>* result = first.Or(second);

    EXPECT_EQ(result->get_bit_at(0), 0);
    EXPECT_EQ(result->get_bit_at(1), 1);
    EXPECT_EQ(result->get_bit_at(2), 1);
    EXPECT_EQ(result->get_bit_at(3), 1);
    delete result;
}

TEST(bit_sequence_operations, correct_xor_operation) {
    bool array_1[] = {0, 0, 1, 1};
    bool array_2[] = {0, 1, 0, 1};

    BitSequence<int> first(array_1, 4);
    BitSequence<int> second(array_2, 4);

    BitSequence<int>* result = first.Xor(second);

    EXPECT_EQ(result->get_bit_at(0), 0);
    EXPECT_EQ(result->get_bit_at(1), 1);
    EXPECT_EQ(result->get_bit_at(2), 1);
    EXPECT_EQ(result->get_bit_at(3), 0);
    delete result;
}

TEST(bit_sequence_operations, correct_not_operation) {
    bool array[] = {0, 0, 1, 1};
    BitSequence<int> sequence(array, 4);

    BitSequence<int>* result = sequence.Not();

    EXPECT_EQ(result->get_bit_at(0), 1);
    EXPECT_EQ(result->get_bit_at(1), 1);
    EXPECT_EQ(result->get_bit_at(2), 0);
    EXPECT_EQ(result->get_bit_at(3), 0);
    delete result;
}

TEST(bit_sequence_operations, length_mismatch) {
    bool array_1[] = {0, 0, 1, 1, 0};
    bool array_2[] = {0, 1, 0, 1};

    BitSequence<int> first(array_1, 5);
    BitSequence<int> second(array_2, 4);
    EXPECT_THROW(first.And(second), SequenceLengthMismatchException);
}



TEST(bit_sequence_functions, correct_map) {
    bool array[] = {0, 0, 1, 1};
    BitSequence<int> sequence(array, 4);

    auto flip = [](Bit<int> bit) {
        return Bit<int>(!bit.get_bit_at(0));
    };

    Sequence<Bit<int>>* mapped = sequence.map(flip);
    ASSERT_EQ(mapped->get_length(), 4);
    EXPECT_EQ(mapped->get(0).get_bit_at(0), 1);
    EXPECT_EQ(mapped->get(1).get_bit_at(0), 1);
    EXPECT_EQ(mapped->get(2).get_bit_at(0), 0);
    EXPECT_EQ(mapped->get(3).get_bit_at(0), 0);
    delete mapped;
}

TEST(bit_sequence_functions, correct_where) {
    bool array[] = {0, 0, 1, 1};
    BitSequence<int> sequence(array, 4);

    auto pred = [](Bit<int> bit) {
        return bit.get_bit_at(0);
    };

    Sequence<Bit<int>>* filtered = sequence.where(pred);
    ASSERT_EQ(filtered->get_length(), 2);
    EXPECT_EQ(filtered->get(0).get_bit_at(0), 1);
    EXPECT_EQ(filtered->get(1).get_bit_at(0), 1);
    delete filtered;
}

TEST(bit_sequence_functions, correct_reduce) {
    bool array[] = {0, 0, 1, 1};
    BitSequence<int> sequence(array, 4);

    auto reducer = [](Bit<int> a, Bit<int> b) {
        return Bit<int>(a.get_bit_at(0) || b.get_bit_at(0));
    };
    Bit<int> reduced = sequence.reduce(reducer, Bit<int>(0));
    EXPECT_EQ(reduced.get_bit_at(0), 1);
}

TEST(bit_sequence_functions, correct_reduce_2) {
    bool array[] = {0, 0, 0, 0};
    BitSequence<int> sequence(array, 4);

    auto reducer = [](Bit<int> a, Bit<int> b) {
        return Bit<int>(a.get_bit_at(0) || b.get_bit_at(0));
    };
    Bit<int> reduced = sequence.reduce(reducer, Bit<int>(0));
    EXPECT_EQ(reduced.get_bit_at(0), 0);
}

