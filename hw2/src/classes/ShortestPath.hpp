/*
    Header file for ShortestPath
    Author: Alec Landow
*/
#pragma once

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

        vector<int> _run_dijkstra();
        // void _calculate_paths(vector<int>& paths);
        vector<int> _run_dijkstra_iterative(int start_node);
};
