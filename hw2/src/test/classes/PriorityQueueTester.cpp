#include "../catch_amalgamated.hpp"
#include "../../classes/PriorityQueue.hpp"

SCENARIO("New PriorityQueue", "[priority_queue]") {
    int node_A_index = 0;
    int node_A_priority = 10;

    int node_B_index = 1;
    int node_B_priority = 20;

    int node_C_index = 2;
    int node_C_priority = 3;

    PriorityQueue queue = PriorityQueue();
    PriorityQueue full_queue = PriorityQueue();
    full_queue.insert(node_A_index, node_A_priority);
    full_queue.insert(node_B_index, node_B_priority);
    full_queue.insert(node_C_index, node_C_priority);

    SECTION("As Nodes are added, the queue is adjusted properly and returns the minimum priority node") {
        queue.insert(node_A_index, node_A_priority);
        REQUIRE( 1 == queue.size() );
        REQUIRE( node_A_index == queue.top()->get_index() );
        REQUIRE( node_A_priority == queue.top()->get_priority() );

        queue.insert(node_B_index, node_B_priority);
        REQUIRE( 2 == queue.size() );
        REQUIRE( node_A_index == queue.top()->get_index() );
        REQUIRE( node_A_priority == queue.top()->get_priority() );

        queue.insert(node_C_index, node_C_priority);
        REQUIRE( 3 == queue.size() );
        REQUIRE( node_C_index == queue.top()->get_index() );
        REQUIRE( node_C_priority == queue.top()->get_priority() );

        PriorityQueue::Node minNode = queue.min_priority();
        REQUIRE( 2 == queue.size() );
        REQUIRE( node_C_index == minNode.get_index() );
        REQUIRE( node_C_priority == minNode.get_priority() );
    }

    SECTION("Test contains()") {
        REQUIRE( full_queue.contains(node_A_index) );
        REQUIRE( full_queue.contains(node_B_index) );
        REQUIRE( full_queue.contains(node_C_index) );
        REQUIRE( !full_queue.contains(4) );
    }

    SECTION("Test change_priority()") {
        int new_node_A_priority = 1;
        REQUIRE( new_node_A_priority < node_C_priority);
        full_queue.change_priority(node_A_index, new_node_A_priority);

        PriorityQueue::Node minNode = full_queue.min_priority();
        REQUIRE( 2 == full_queue.size() );
        REQUIRE( node_A_index == minNode.get_index() );
        REQUIRE( new_node_A_priority == minNode.get_priority() );
    }

    SECTION("Empty queue") {
        PriorityQueue::Node minNode = queue.min_priority();
        REQUIRE( -1 == minNode.get_index() );
        REQUIRE( -1 == minNode.get_priority() );
    }

}
