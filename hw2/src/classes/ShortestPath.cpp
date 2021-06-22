/*
    Implementation of ShortestPath
    Author: Alec Landow
*/

#include "ShortestPath.hpp"

ShortestPath::ShortestPath(Graph graph) : graph(graph), cached_start_node(-1) {}

vector<int> ShortestPath::vertices() {
    int number_of_nodes = this->graph.get_number_of_nodes();
    vector<int> vertices;
    for (int i = 0; i < number_of_nodes; i++) {
        vertices.push_back(i);
    }
    return vertices;
}

vector<int> ShortestPath::path(int start_node, int end_node) {
    vector<int> path_list = this->_run_dijkstra_iterative(start_node);
    // this->_calculate_paths(path_list);

    return path_list;
}

vector<int> ShortestPath::_run_dijkstra_iterative(int start_node) {
    vector<bool> known(this->graph.get_number_of_nodes(), false);
    vector<double> cost(this->graph.get_number_of_nodes(), numeric_limits<double>::max());
    vector<int> path_list(this->graph.get_number_of_nodes(), -1);

    cost.at(start_node) = 0.0;
    known.at(start_node) = true;
    int previous_node = start_node;

    do {
        vector<int> neighbor_nodes = this->graph.get_neighbors(previous_node);

        for (int neighbor_node : neighbor_nodes) {
            double edge_value = this->graph.get_edge_value(previous_node, neighbor_node);
            double cost_from_start_to_neighbor = cost.at(previous_node) + edge_value;

            if (!known.at(neighbor_node)) {
                if (cost_from_start_to_neighbor < cost.at(neighbor_node)) {
                    cost.at(neighbor_node) = cost_from_start_to_neighbor;
                    path_list.at(neighbor_node) = previous_node;

                    if (this->priority_queue.contains(neighbor_node)) {
                        this->priority_queue.change_priority(neighbor_node, cost.at(neighbor_node));
                    } else {
                        this->priority_queue.insert(neighbor_node, cost.at(neighbor_node));
                    }

                }

            }
        }

        PriorityQueue::Node lowest_cost_node = this->priority_queue.min_priority();
        previous_node = lowest_cost_node.get_index();
        cost.at(previous_node) = lowest_cost_node.get_priority();
        known.at(previous_node) = true;

    } while (priority_queue.size() > 0);

    return path_list;

}

// ShortestPath::_calculate_paths(vector<int>& paths) {
//
// }
