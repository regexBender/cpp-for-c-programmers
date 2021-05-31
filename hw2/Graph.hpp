/*
    The Graph class header
*/
#include <vector>

using namespace std;

class Graph {
    private:
        int number_of_nodes;
        int number_of_edges;
        vector<vector<double>> adjacency_matrix;

    public:
        Graph(int number_of_nodes, double edge_density, double min_distance, double max_distance);
        // ~Graph();
        //
        // int get_number_of_nodes();
        // int get_number_of_edges();
        //
        // bool are_adjacent(int node_x, int node_y);
        // vector<int> get_neighbors(int node_x);
        bool add_edge(int node_x, int node_y, double edge_value);
        // bool delete_edge(int node_x, int node_y);
        //
        // int get_node_value(int node_x);
        // void set_node_value(int node_x, double node_value);
        // int get_edge_value(int node_x, int node_y);
        // void set_edge_value(int node_x, int node_y, double edge_value);

        void print_matrix();
};