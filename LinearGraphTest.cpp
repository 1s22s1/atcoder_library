#include <gtest/gtest.h>

#include "LinearGraph.cpp"

using namespace std;

TEST(LinearGraphTest, BasicAssertions)
{
    vector<vector<int>> g(4);
    vector<vector<int>> vec = {{0, 1}, {1, 2}, {2, 3}, {3, 0}};

    for (const auto e : vec)
    {
        g.at(e.at(0)).push_back(e.at(1));
        g.at(e.at(1)).push_back(e.at(0));
    }

    LinearGraph linear_graph(g);

    vector<int> expected_visited = {0, 1, 2, 1};
    EXPECT_EQ(expected_visited, linear_graph.visited);

    vector<int> expected_previous = {-1, 0, 1, 0};
    EXPECT_EQ(expected_previous, linear_graph.previous);
}
