#include <vector>
#include <queue>
#include <string>

using namespace std;

template <typename T>

class LinearGraph
{

public:
    vector<long long> visited;
    vector<long long> previous;

    LinearGraph(T _graph)
    {
        graph = _graph;
    }

    void bfs(vector<long long> starts = {0})
    {
        visited.assign(graph.size(), -1);
        previous.assign(graph.size(), -1);

        queue<long long> queue;

        for (auto start : starts)
        {
            queue.push(start);
            visited.at(start) = 0;
        }

        while (!queue.empty())
        {
            long long current = queue.front();
            queue.pop();

            for (long long next : graph.at(current))
            {
                if (visited.at(next) != -1)
                {
                    continue;
                }

                queue.emplace(next);
                visited.at(next) = visited.at(current) + 1;
                previous.at(next) = current;
            }
        }
    }

private:
    T graph;
};
