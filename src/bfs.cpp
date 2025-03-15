#include "../include/bfs.h"
#include <queue>

struct TVertInfo
{
    unsigned vertIndex;
    unsigned distance;
};

std::vector<unsigned> BFS(const std::vector<std::vector<unsigned> >& adjList, 
    unsigned startVertex)
{
    std::vector<unsigned> result(adjList.size(), 0);

    std::vector<bool> used(adjList.size(), false);
    used[startVertex] = true;

    std::queue<TVertInfo> que;
    que.push({startVertex, 0});
    
    while (!(que.empty()))
    {
        TVertInfo vi = que.front();
        que.pop();

        for (unsigned adjacent : adjList[vi.vertIndex]) 
        {
            if (!used[adjacent]) 
            {
                que.push({adjacent, vi.distance+1});
                used[adjacent] = true;
                result[adjacent] = vi.distance+1;
            }
        }
    }

    return result;
}
