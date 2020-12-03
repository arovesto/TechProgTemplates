//
// Created by akhtyamovpavel on 5/1/20.
//

#include <gtest/gtest.h>

#include "AddTestCase.h"
#include "Functions.h"

TEST(A, Addition) {
	ASSERT_EQ(4, Add(2, 2));
}