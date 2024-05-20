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