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

}

void ShortestPath:_run_dijkstra_iterative(int start_node) {
    vector<bool> known(graph->get_number_of_nodes(), false);
    vector<double> cost(graph->get_number_of_nodes(), numeric_limits<double>::max());
    vector<int> path(graph->get_number_of_nodes(), -1);

    cost.at(start_node) = 0.0;
    known.at(start_node) = true;
    int previous_node = start_node;

    do {
        vector<int> neighbor_nodes = graph->get_neighbors(previous_node);

        for (int neighbor_node : neighbor_nodes) {
            double edge_value = graph->get_edge_value(previous_node, neighbor_node);
            double cost_from_start_to_neighbor = cost.at(previous_node) + edge_value;

            if (!known.at(neighbor_node)) {
                if (cost_from_start_to_neighbor < cost.at(neighbor_node)) {
                    cost.at(neighbor_node) = cost_from_start_to_neighbor;
                    path.at(neighbor_node) = previous_node;

                    if (self->priority_queue.contains(neighbor_node)) {
                        self->priority_queue.change_priority(neighbor_node, cost.at(neighbor_node));
                    } else {
                        self->priority_queue.insert(neighbor_node, cost.at(neighbor_node));
                    }

                }

            }

            PriorityQueue::Node lowest_cost_node = this->priority_queue.min_priority();
            previous_node = lowest_cost_node.get_index();
            cost.at(previous_node) = lowest_cost_node.get_priority();
            known.at(previous_node) = true;
        }

    } while (priority_queue.size() > 0);


}
