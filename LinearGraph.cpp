#include <vector>
#include <queue>
#include <string>

using namespace std;

class LinearGraph
{

public:
    vector<int> visited;
    vector<int> previous;

    LinearGraph(vector<vector<int>> _graph)
    {
        graph = _graph;
    }

    vector<int> bfs(int start = 0)
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

        return visited;
    }

private:
    vector<vector<int>> graph;
};
