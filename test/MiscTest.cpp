#include <gtest/gtest.h>

#include "../Misc.cpp"

using namespace std;

TEST(MiscTest, BasicAssertions)
{
    EXPECT_EQ(0, mod(2, 3, 4));
}
