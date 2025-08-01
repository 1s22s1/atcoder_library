#include <gtest/gtest.h>

#include "LinearGraph.cpp"

using namespace std;

TEST(LinearGraphTest, BasicAssertions)
{
    vector<vector<long long>> g(4);
    vector<vector<long long>> vec = {{0, 1}, {1, 2}, {2, 3}, {3, 0}};

    for (const auto e : vec)
    {
        g.at(e.at(0)).push_back(e.at(1));
        g.at(e.at(1)).push_back(e.at(0));
    }

    LinearGraph linear_graph(g);
    linear_graph.bfs({0});

    vector<long long> expected_visited = {0, 1, 2, 1};
    EXPECT_EQ(expected_visited, linear_graph.visited);

    vector<long long> expected_previous = {-1, 0, 1, 0};
    EXPECT_EQ(expected_previous, linear_graph.previous);
}
