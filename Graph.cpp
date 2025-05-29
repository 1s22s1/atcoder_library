#include <vector>
#include <queue>

using namespace std;

using Graph = vector<vector<int>>;

vector<int> bfs(Graph G)
{
    queue<int> queue;
    queue.push(0);

    vector<int> visited(G.size(), -1);
    visited.at(0) = 0;

    while (!queue.empty())
    {
        int current = queue.front();
        queue.pop();

        for (int next : G.at(current))
        {
            if (visited.at(next) != -1)
            {
                continue;
            }

            queue.push(next);
            visited.at(next) = visited.at(current) + 1;
        }
    }

    return visited;
}
