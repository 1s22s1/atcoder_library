#include <vector>
#include <queue>

using namespace std;

class Graph
{

public:
    vector<int> visited;

    Graph(vector<vector<int>> graph, int start = 0)
    {
        visited.assign(graph.size(), -1);

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
            }
        }
    }
};
