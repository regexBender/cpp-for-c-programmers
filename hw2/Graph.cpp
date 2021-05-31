/*
    The Graph class
*/
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Graph.hpp"


Graph::Graph(int number_of_nodes, double edge_density, double min_distance, double max_distance) {
    srand(time(0));

    this->number_of_nodes = number_of_nodes;
    this->number_of_edges = 0;

    // Reserve the rows
    this->adjacency_matrix.reserve(this->number_of_nodes);

    // Reserve the columns
    for (int node_x = 0; node_x < this->number_of_nodes; node_x++) {
        this->adjacency_matrix[node_x].reserve(this->number_of_nodes);
    }

    for (int node_x = 0; node_x < this->number_of_nodes; node_x++) {
        double probability = static_cast<double>(rand() % 101) / 100;
        if (probability < edge_density) { // if true, add an edge to a random node with a random distance
            int node_to_connect_to;
            do { // ensure the node does not have an edge to itself
                node_to_connect_to = rand() % this->number_of_nodes;
            } while (node_to_connect_to == node_x);

            double range_size = max_distance + 1 - min_distance;
            double new_edge_value = rand() % static_cast<int>(range_size) + min_distance;
            this->add_edge(node_x, node_to_connect_to, new_edge_value);
        }
    }
}

bool Graph::add_edge(int node_x, int node_y, double edge_value) {
    if (this->adjacency_matrix[node_x][node_y] != 0) {
        return false;
    }
    // The matrix is symmetric. For convenience, populate both elements
    this->adjacency_matrix[node_x][node_y] = edge_value;
    this->adjacency_matrix[node_y][node_x] = edge_value;
    this->number_of_edges++;
    return true;
}

void Graph::print_matrix() {
    for (int i = 0; i < this->number_of_nodes; i++) {
        cout << "[ ";
        for (int j = 0; j < this->number_of_nodes;j++) {
            cout << this->adjacency_matrix[i][j];
            if (j != this->number_of_nodes - 1) {
                cout << ", ";
            }
        }
        cout << " ]" << endl;
    }
}
#endif
