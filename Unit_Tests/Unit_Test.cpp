#include <gtest/gtest.h>
#include "../vectorClass.h"
#include "../MainIncludes.h"

/* Member_Functions */
TEST(Member_Functions, Copy_Assigment) {
    vectorClass<int> Copy_Assigment1;
    vectorClass<int> Copy_Assigment2;

    Copy_Assigment1.push_back(10);
    Copy_Assigment1.push_back(20);

    Copy_Assigment2 = Copy_Assigment1;

    EXPECT_EQ(Copy_Assigment2.front(), 10);
    EXPECT_EQ(Copy_Assigment2.back(), 20);
}

TEST(Member_Functions, Move_Assignment) {
    vectorClass<int> Move_Assignment1;
    vectorClass<int> Move_Assignment2;
    Move_Assignment1.push_back(10);
    Move_Assignment1.push_back(20);

    Move_Assignment2 = std::move(Move_Assignment1);

    EXPECT_EQ(Move_Assignment2.front(), 10);
    EXPECT_EQ(Move_Assignment2.back(), 20);
}

TEST(Member_Functions, Assigment) {
    vectorClass<int> Assigment;

    Assigment.assign(5, 10);

    EXPECT_EQ(Assigment.size(), 5);
    for (int i = 0; i < Assigment.size(); ++i) {
        EXPECT_EQ(10, Assigment[i]);
    }
}

/* Element_Access */
TEST(Element_Access, At) {
    vectorClass<int> at;
    at.push_back(10);
    at.push_back(20);
    at.push_back(30);

    EXPECT_EQ(at.at(1), 20);
}

TEST(Element_Access, Operator) {
    vectorClass<int> op;
    op.push_back(10);
    op.push_back(20);
    op.push_back(30);

    EXPECT_EQ(op[2], 30);
}

TEST(Element_Access, Front) {
    vectorClass<int> front;
    front.push_back(10);
    front.push_back(20);
    front.push_back(30);

    EXPECT_EQ(front.front(), 10);
}

TEST(Element_Access, Back) {
    vectorClass<int> back;
    back.push_back(10);
    back.push_back(20);
    back.push_back(30);

    EXPECT_EQ(back.back(), 30);
}

/* Iterators */
TEST(Iterators, Begin_End_Iterators) {
    vectorClass<int> begin;
    begin.push_back(1);
    begin.push_back(2);
    begin.push_back(3);

    int expected_value = 1;
    for (auto it = begin.begin(); it != begin.end(); ++it) {
        EXPECT_EQ(expected_value, *it);
        ++expected_value;
    }
}

TEST(Iterators, RBegin_REnd_Iterators) {
    vectorClass<int> RBegin;
    RBegin.push_back(1);
    RBegin.push_back(2);
    RBegin.push_back(3);

    int expected_value = 3;
    for (auto it = RBegin.rbegin(); it != RBegin.rend(); ++it) {
        EXPECT_EQ(expected_value, *it);
        --expected_value;
    }
}

/* Capacity */
TEST(Capacity, Empty) {
    vectorClass<int> empty;
    EXPECT_TRUE(empty.empty());

    empty.push_back(10);
    EXPECT_FALSE(empty.empty());
}

TEST(Capacity, Size) {
    vectorClass<int> size;
    EXPECT_EQ(size.size(), 0);

    size.push_back(1);
    size.push_back(2);
    size.push_back(3);

    EXPECT_EQ(size.size(), 3);
}

TEST(Capacity, MaxSize) {
    vectorClass<int> MaxSize;
    EXPECT_GE(MaxSize.max_size(), 0); // EXPECT_GE - expect greater
}

TEST(Capacity, Reserve_Capacity) {
    vectorClass<int> reserve;
    reserve.reserve(10);
    EXPECT_GE(reserve.get_capacity(), 10);

    reserve.reserve(5);
    EXPECT_GE(reserve.get_capacity(), 10);
}

TEST(Capacity, Shrink_To_Fit) {
    vectorClass<int> shrink;
    shrink.reserve(100);
    shrink.push_back(10);
    shrink.push_back(20);
    shrink.push_back(30);
    shrink.shrink_to_fit();
    EXPECT_EQ(shrink.size(), 3);
    EXPECT_EQ(shrink.get_capacity(), 3);
}

/* Modifiers */
TEST(Modifiers, Clear) {
    vectorClass<int> clear;
    clear.push_back(1);
    clear.push_back(2);
    clear.push_back(3);

    clear.clear();

    EXPECT_TRUE(clear.empty());
}

TEST(Modifiers, Insert) {
    vectorClass<int> insert;
    insert.push_back(1);
    insert.push_back(3);

    insert.insert(1, 2);

    EXPECT_EQ(insert.size(), 3);
    EXPECT_EQ(insert[1], 2);
}

TEST(Modifiers, Erase) {
    vectorClass<int> erase;
    erase.push_back(1);
    erase.push_back(2);
    erase.push_back(3);

    erase.erase(1);

    EXPECT_EQ(erase.size(), 2);
    EXPECT_EQ(erase[1], 3);
}

TEST(Modifiers, PushBack) {
    vectorClass<int> push;
    push.push_back(1);
    EXPECT_EQ(push.size(), 1);
    EXPECT_EQ(push[0], 1);
}

TEST(Modifiers, PopBack) {
    vectorClass<int> pop;
    pop.push_back(1);
    pop.push_back(2);

    pop.pop_back();

    EXPECT_EQ(pop.size(), 1);
    EXPECT_EQ(pop[0], 1);
}

TEST(Modifiers, Resize) {
    vectorClass<int> resize;
    resize.push_back(1);
    resize.push_back(2);
    resize.push_back(3);

    resize.resize(2);

    EXPECT_EQ(resize.size(), 2);
    EXPECT_EQ(resize[0], 1);
    EXPECT_EQ(resize[1], 2);
}

TEST(Modifiers, Swap) {
    vectorClass<int> swap1;
    vectorClass<int> swap2;
    swap1.push_back(1);
    swap1.push_back(2);

    swap2.push_back(3);

    swap1.swap(swap2);

    EXPECT_EQ(swap1.size(), 1);
    EXPECT_EQ(swap2.size(), 2);
    EXPECT_EQ(swap1[0], 3);
    EXPECT_EQ(swap2[0], 1);
    EXPECT_EQ(swap2[1], 2);
}