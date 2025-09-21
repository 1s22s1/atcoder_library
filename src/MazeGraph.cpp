#include <vector>
#include <queue>
#include <string>

using namespace std;

#define ll long long

class Point
{
public:
    ll x;
    ll y;

    Point(ll x, ll y) : x(x), y(y) {}
};

class MazeGraph
{
public:
    vector<vector<ll>> visited;

    MazeGraph(vector<string> _maze, char wall = '#')
    {
        maze = _maze;
    }

    void bfs(vector<Point> starts = {Point{0, 0}}, char wall = '#')
    {
        visited.assign(maze.size(), vector<ll>(maze.at(0).size(), -1));

        queue<Point> queue;
        for (auto start : starts)
        {
            queue.push(start);
            visited.at(start.x).at(start.y) = 0;
        }

        vector<pair<ll, ll>> moves = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
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

                queue.emplace(Point{next_x, next_y});
                visited.at(next_x).at(next_y) = visited.at(current.x).at(current.y) + 1;
            }
        }
    }

private:
    vector<string> maze;
};
