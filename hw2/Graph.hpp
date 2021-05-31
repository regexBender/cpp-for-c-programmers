/*
    The Graph class
*/

#include <vector>

using namespace std;

class Graph {
    private:
        int number_of_vertices;
        int number_of_edges;
        vector<vector<double>> adjacency_matrix;

    public:
        Graph(double edge_density, double distance_range);
        ~Graph();

        int get_number_of_vertices();
        int get_number_of_edges();

        bool are_adjacent(int node_x, int node_y);
        vector<int> get_neighbors(int node_x);
        bool add_edge(int node_x, int node_y);
        bool delete_edge(int node_x, int node_y);

        int get_node_value(int node_x);
        void set_node_value(int node_x, double node_value);
        int get_edge_value(int node_x, int node_y);
        void set_edge_value(int node_x, int node_y, double edge_value);
}
