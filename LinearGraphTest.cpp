#include <gtest/gtest.h>

#include "LinearGraph.cpp"

using namespace std;

TEST(GraphTest, BasicAssertions)
{
    vector<vector<int>> g(4);

    vector<vector<int>> vec = {{0, 1}, {1, 2}, {2, 3}, {3, 0}};

    for (const auto e : vec)
    {
        g.at(e.at(0)).push_back(e.at(1));
        g.at(e.at(1)).push_back(e.at(0));
    }

    LinearGraph linear_graph(g);
    vector<int> actual = linear_graph.visited;

    EXPECT_TRUE(0 == actual.at(0));
    EXPECT_TRUE(1 == actual.at(1));
    EXPECT_TRUE(2 == actual.at(2));
    EXPECT_TRUE(1 == actual.at(3));
}
