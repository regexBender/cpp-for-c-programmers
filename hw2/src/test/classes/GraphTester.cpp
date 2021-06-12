#include "../catch_amalgamated.hpp"
#include "../../classes/Graph.hpp"

SCENARIO("A New Graph is Constructed", "[graph]") {
    int number_of_nodes = 10;
    int number_of_edges = 6;
    double edge_density = 0.5;
    double min_distance = 1.0;
    double max_distance = 9.0;
    int test_seed = 1;

    GIVEN("A Graph with a pre-defined seed of " + std::to_string(test_seed)) {
        Graph graph = Graph(number_of_nodes, edge_density, min_distance, max_distance, test_seed);
        /* The Graph prints as this matrix
            [ 0, 9, 0, 0, 0, 0, 0, 0, 0, 6 ]
            [ 9, 0, 0, 0, 0, 0, 0, 0, 0, 0 ]
            [ 0, 0, 0, 0, 9, 0, 0, 0, 0, 0 ]
            [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 ]
            [ 0, 0, 9, 0, 0, 0, 0, 0, 0, 0 ]
            [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ]
            [ 0, 0, 0, 0, 0, 0, 0, 8, 0, 0 ]
            [ 0, 0, 0, 0, 0, 0, 8, 0, 0, 5 ]
            [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ]
            [ 6, 0, 0, 1, 0, 0, 0, 5, 0, 0 ]
        */
        std::vector<int> expected_neighbors_of_9{0, 3, 7};

        WHEN("After the Graph is constructed") {
            THEN("The Graph initializes with the expected parameters") {
                REQUIRE( number_of_nodes == graph.get_number_of_nodes() );
                REQUIRE( number_of_edges == graph.get_number_of_edges() );
                REQUIRE( graph.are_adjacent(0, 1) );

                std::vector<int> actual_neighbors_of_9 = graph.get_neighbors(9);
                REQUIRE_THAT( expected_neighbors_of_9, Catch::Matchers::UnorderedEquals(actual_neighbors_of_9) );
            }
        }

        WHEN("A neighbor is added to node 9") {
            THEN("The correct neighbors of node 9 are returned") {
                int new_neighbor_of_9 = 1;
                double new_edge_value = 2.0;
                graph.add_edge(new_neighbor_of_9, 9, new_edge_value);
                expected_neighbors_of_9.push_back(new_neighbor_of_9);
                std::vector<int> actual_neighbors_of_9 = graph.get_neighbors(9);
                REQUIRE_THAT( expected_neighbors_of_9, Catch::Matchers::UnorderedEquals(actual_neighbors_of_9) );
            }
        }

        WHEN("An edge from node 9 is severed") {
            THEN("The correct neighbors of node 9 are returned") {
                int neighbor_to_cut_ties_with = 7;
                graph.delete_edge(neighbor_to_cut_ties_with, 9);
                expected_neighbors_of_9.pop_back();
                std::vector<int> actual_neighbors_of_9 = graph.get_neighbors(9);
                REQUIRE_THAT( expected_neighbors_of_9, Catch::Matchers::UnorderedEquals(actual_neighbors_of_9) );
            }
        }

        WHEN("A node value is set") {
            THEN("The correct node value is returned") {
                double node_9_value = 18.0;
                graph.set_node_value(9, node_9_value);
                REQUIRE( node_9_value == graph.get_node_value(9) );
            }
        }

        WHEN("An edge value is set") {
            THEN("The correct edge value is returned") {
                double edge_0_9_value = 42.0;
                graph.set_edge_value(0, 9, edge_0_9_value);
                REQUIRE( edge_0_9_value == graph.get_edge_value(0, 9) );
            }
        }
    }

}
