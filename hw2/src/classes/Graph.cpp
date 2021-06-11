/*
    The Graph class
    Author: Alec Landow
*/
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Graph.hpp"

Graph::Graph(int number_of_nodes, double edge_density, double min_distance, double max_distance)
    : Graph(number_of_nodes, edge_density, min_distance, max_distance, time(0)) {}

Graph::Graph(int number_of_nodes, double edge_density, double min_distance, double max_distance, int seed) {
    srand(seed);
    this->number_of_nodes = number_of_nodes;
    this->number_of_edges = 0;

    // Reserve the rows
    this->adjacency_matrix.resize(this->number_of_nodes);

    // Reserve the columns
    for (int node_x = 0; node_x < this->number_of_nodes; node_x++) {
        this->adjacency_matrix[node_x].resize(this->number_of_nodes);
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

int Graph::get_number_of_nodes() {
    return this->number_of_nodes;
}

int Graph::get_number_of_edges() {
    return this->number_of_edges;
}

bool Graph::are_adjacent(int node_x, int node_y) {
    return this->adjacency_matrix[node_x][node_y] != 0;
}

vector<int> Graph::get_neighbors(int node_x) {
    vector<int> neighbors;
    for (int node_j = 0; node_j < this->number_of_nodes; node_j++) {
        if (node_x != node_j && this->adjacency_matrix[node_x][node_j] != 0) {
            neighbors.push_back(node_j);
        }
    }

    return neighbors;
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

bool Graph::delete_edge(int node_x, int node_y) {
    if (this->adjacency_matrix[node_x][node_y] == 0) {
        return false;
    }
    // The matrix is symmetric, so delete both elements
    this->adjacency_matrix[node_x][node_y] = 0;
    this->adjacency_matrix[node_y][node_x] = 0;
    this->number_of_edges--;
    return true;
}


double Graph::get_node_value(int node_x) {
    return this->adjacency_matrix[node_x][node_x];
}

void Graph::set_node_value(int node_x, double node_value) {
    this->adjacency_matrix[node_x][node_x] = node_value;
}

double Graph::get_edge_value(int node_x, int node_y) {
    if (node_x == node_y) {
        cout << "Invalid: input nodes must be different from each other";
        return -1;
    }

    return this->adjacency_matrix[node_x][node_x];

}

void Graph::set_edge_value(int node_x, int node_y, double edge_value) {
    if (node_x == node_y) {
        cout << "Invalid: input nodes must be different from each other";
        return;
    }

    this->adjacency_matrix[node_x][node_x] = edge_value;
}

std::ostream& operator << (std::ostream& out, const Graph graph) {
    for (int i = 0; i < graph.number_of_nodes; i++) {
        out << "[ ";
        for (int j = 0; j < graph.number_of_nodes;j++) {
            out << graph.adjacency_matrix[i][j];
            if (j != graph.number_of_nodes - 1) {
                out << ", ";
            }
        }
        out << " ]" << endl;
    }

    return out;
}
#endif
