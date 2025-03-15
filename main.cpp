#include <iostream>
#include <fstream>
#include <vector>
#include "include/bfs.h"

int main(int argc, char *argv[])
{
    std::ifstream inputFile("graph.txt");

    unsigned vertexCount;
    unsigned edgesCount;
    std::vector<std::vector<unsigned> > adjacencyList;
    unsigned startVertex;
    if (inputFile.is_open())
    {
        inputFile >> vertexCount;
        adjacencyList.assign(vertexCount, std::vector<unsigned>());
        inputFile >> edgesCount;
        for (unsigned i = 0; i < edgesCount; ++i)
        {
            unsigned f, s;
            inputFile >> f >> s;
            adjacencyList[f].push_back(s);
            adjacencyList[s].push_back(f);
        }
        inputFile >> startVertex;

        inputFile.close();
    }
    else {
        return EXIT_FAILURE;
    }

    std::vector<unsigned> distances = BFS(adjacencyList, startVertex);

    for (size_t i = 0; i < distances.size(); ++i) {
        std::cout << distances[i] << std::endl;
    }

    return EXIT_SUCCESS;
}
