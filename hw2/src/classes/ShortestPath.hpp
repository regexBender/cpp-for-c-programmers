/*
    Header file for ShortestPath
    Author: Alec Landow
*/
#include <vector>
#include <limits>
#include "Graph.hpp"
#include "PriorityQueue.hpp"

using namespace std;

class ShortestPath {
    public:
        ShortestPath(Graph graph);
        vector<int> vertices();
        vector<int> path(int start_node, int end_node);
        double path_size(int start_node, int end_node);

    private:
        Graph graph;
        PriorityQueue priority_queue;
        int cached_start_node;
        vector<int> paths_from_cached_start_node;

        void _run_dijkstra();
};
