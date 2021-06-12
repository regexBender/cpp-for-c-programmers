/*
Homework 2: Implement Dijkstra's Algorithm
Author: Alec Landow
*/
#include <iostream>
#include "../classes/Graph.hpp"
#include "../classes/PriorityQueue.hpp"

using namespace std;
template <class printable>
inline void print_vector(vector<printable> vec) {
    for (auto iterator = vec.begin(); iterator != vec.end(); iterator++) {
        cout << *iterator << ", ";
    }

}

int main() {
    int number_of_nodes = 10;
    double edge_density = 0.5;
    double min_distance = 1.0;
    double max_distance = 9.0;

    Graph graph = Graph(number_of_nodes, edge_density, min_distance, max_distance);
    cout << graph;

    for (int i = 0; i < graph.get_number_of_nodes(); i++) {
        cout << "neighbors of " << i << ": ";
        print_vector( graph.get_neighbors(i) );
        cout << endl;
    }

    for (int i = 0; i < graph.get_number_of_nodes(); i++) {
        cout << "Is 0 adjacent to " << i << "? ";
        cout << (graph.are_adjacent(0, i) ? "yes" : "no") << endl;
    }

    PriorityQueue queue = PriorityQueue();
    queue.insert(0, 10);
    cout << "Oddish" << endl;
    cout << "index: " << queue.top()->get_index() << " | ";
    cout << "priority: " << queue.top()->get_priority() << endl;

    queue.insert(1, 20);
    cout << "index: " << queue.top()->get_index() << " | ";
    cout << "priority: " << queue.top()->get_priority() << endl;

    queue.insert(2, 3);
    cout << "index: " << queue.top()->get_index() << " | ";
    cout << "priority: " << queue.top()->get_priority() << endl;

    PriorityQueue::Node minNode = queue.min_priority();
    cout << "index: " << minNode.get_index() << " | ";
    cout << "priority: " << minNode.get_priority() << endl;
}
