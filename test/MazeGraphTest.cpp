#include <gtest/gtest.h>

#include "../src/MazeGraph.cpp"

using namespace std;

TEST(MazeGraphTest, BasicAssertions)
{
    vector<string> maze = {"...#.", ".#.#.", ".#..."};
    vector<Point> starts = {{0, 0}};

    MazeGraph maze_graph(maze);
    maze_graph.bfs();

    vector<vector<int>> expected_visited = {{0, 1, 2, -1, 8}, {1, -1, 3, -1, 7}, {2, -1, 4, 5, 6}};
    EXPECT_EQ(expected_visited, maze_graph.visited);
}
