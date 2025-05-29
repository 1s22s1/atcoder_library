#include <gtest/gtest.h>

#include "Graph.cpp"

using namespace std;

TEST(GraphTest, BasicAssertions)
{
    Graph G(4);

    vector<vector<int>> vec = {{0, 1}, {1, 2}, {2, 3}, {3, 0}};

    for (const auto e : vec)
    {
        G.at(e.at(0)).push_back(e.at(1));
        G.at(e.at(1)).push_back(e.at(0));
    }

    vector<int> actual = bfs(G);
    EXPECT_TRUE(0 == actual.at(0));
    EXPECT_TRUE(1 == actual.at(1));
    EXPECT_TRUE(2 == actual.at(2));
    EXPECT_TRUE(1 == actual.at(3));
}
