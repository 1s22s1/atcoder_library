#include <gtest/gtest.h>

#include "RLE.cpp"

using namespace std;

TEST(RLETest, BasicAssertions)
{

    vector<pair<char, int>> expected_visited = {{'a', 1}, {'b', 2}, {'c', 3}};
    EXPECT_EQ(expected_visited, rle("abbccc"));
}
