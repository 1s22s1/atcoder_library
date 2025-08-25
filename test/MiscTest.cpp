#include <gtest/gtest.h>

#include "../Misc.cpp"

using namespace std;

TEST(MiscTest, BasicAssertions)
{
    EXPECT_EQ(0, mod(2, 3, 4));

    vector<pair<char, long long>> expected_visited = {{'a', 1}, {'b', 2}, {'c', 3}};
    EXPECT_EQ(expected_visited, rle("abbccc"));
}
