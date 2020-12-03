//
// Created by akhtyamovpavel on 5/1/20.
//

#include <gtest/gtest.h>

#include "LeapTestCase.h"
#include "Functions.h"

TEST(B, LeapYear) {
    ASSERT_TRUE(IsLeap(2000)); 
    ASSERT_FALSE(IsLeap(1900)); 
    ASSERT_FALSE(IsLeap(2003));
    ASSERT_TRUE(IsLeap(2020));
    ASSERT_THROW(IsLeap(-10), std::invalid_argument);
};

