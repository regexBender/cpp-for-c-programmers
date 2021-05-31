/*
Homework 2: Implement Dijkstra's Algorithm
Author: Alec Landow
*/
#include <iostream>
#include "Graph.hpp"

using namespace std;

int main() {
    int number_of_nodes = 25;
    double edge_density = 0.5;
    double min_distance = 1.0;
    double max_distance = 9.0;

    Graph graph = Graph(number_of_nodes, edge_density, min_distance, max_distance);
    cout << graph;
}
