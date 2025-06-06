#include <vector>
#include <queue>
#include <string>

using namespace std;

class LinearGraph
{

public:
    vector<int> visited;
    vector<int> previous;

    LinearGraph(vector<vector<int>> graph, int start = 0)
    {
        visited.assign(graph.size(), -1);
        previous.assign(graph.size(), -1);

        queue<int> queue;
        queue.push(start);

        visited.at(start) = 0;

        while (!queue.empty())
        {
            int current = queue.front();
            queue.pop();

            for (int next : graph.at(current))
            {
                if (visited.at(next) != -1)
                {
                    continue;
                }

                queue.push(next);
                visited.at(next) = visited.at(current) + 1;
                previous.at(next) = current;
            }
        }
    }
};

class Point
{
public:
    int x;
    int y;

    Point(int x, int y) : x(x), y(y) {}
};

class MazeGraph
{
public:
    vector<vector<int>> visited;

    MazeGraph(vector<string> maze, vector<Point> starts, char wall = '#')
    {
        visited.assign(maze.size(), vector<int>(maze.at(0).size(), -1));

        queue<Point> queue;
        for (auto start : starts)
        {
            queue.push(start);
            visited.at(start.x).at(start.y) = 0;
        }

        vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while (!queue.empty())
        {
            auto current = queue.front();
            queue.pop();

            for (auto move : moves)
            {
                int next_x = current.x + move.first;
                int next_y = current.y + move.second;

                if (next_x < 0 || next_x >= maze.size() || next_y < 0 || next_y >= maze.at(0).size())
                {
                    continue;
                }

                if (maze.at(next_x).at(next_y) == wall)
                {
                    continue;
                }

                if (visited.at(next_x).at(next_y) != -1)
                {
                    continue;
                }

                queue.push(Point{next_x, next_y});
                visited.at(next_x).at(next_y) = visited.at(current.x).at(current.y) + 1;
            }
        }
    }
};
