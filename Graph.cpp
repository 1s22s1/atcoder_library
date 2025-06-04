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

class MazeGraph
{
public:
    vector<vector<int>> visited;

    MazeGraph(vector<string> maze, vector<pair<int, int>> starts)
    {
        visited.assign(maze.size(), vector<int>(maze.at(0).size(), -1));

        queue<pair<int, int>> queue;
        for (auto start : starts)
        {
            queue.push(start);
            visited.at(start.first).at(start.second) = 0;
        }

        vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while (!queue.empty())
        {
            auto current = queue.front();
            queue.pop();

            for (auto move : moves)
            {
                int next_x = current.first + move.first;
                int next_y = current.second + move.second;

                if (next_x < 0 || next_x >= maze.size() || next_y < 0 || next_y >= maze.at(0).size())
                {
                    continue;
                }

                if (maze.at(next_x).at(next_y) == '#')
                {
                    continue;
                }

                if (visited.at(next_x).at(next_y) != -1)
                {
                    continue;
                }

                queue.push({next_x, next_y});
                visited.at(next_x).at(next_y) = visited.at(current.first).at(current.second) + 1;
            }
        }
    }
};
