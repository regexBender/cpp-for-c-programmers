#include "../catch_amalgamated.hpp"
#include "../../classes/Graph.hpp"

TEST_CASE("Testing123", "[graph]") {
    int number_of_nodes = 10;
    double edge_density = 0.5;
    double min_distance = 1.0;
    double max_distance = 9.0;
    int test_seed = 1;

    Graph graph = Graph(number_of_nodes, edge_density, min_distance, max_distance, test_seed);
    cout << graph;

    REQUIRE( number_of_nodes == graph.get_number_of_nodes() );
}
