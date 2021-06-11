#include "../catch_amalgamated.hpp"
#include "../../classes/Graph.hpp"

TEST_CASE("Graph Parameters are Correct", "[graph]") {
    int number_of_nodes = 10;
    int number_of_edges = 6;
    double edge_density = 0.5;
    double min_distance = 1.0;
    double max_distance = 9.0;
    int test_seed = 1;

    Graph graph = Graph(number_of_nodes, edge_density, min_distance, max_distance, test_seed);
    cout << graph;

    REQUIRE( number_of_nodes == graph.get_number_of_nodes() );
    REQUIRE( number_of_edges == graph.get_number_of_edges() );
    REQUIRE( graph.are_adjacent(0, 1) );
}
