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