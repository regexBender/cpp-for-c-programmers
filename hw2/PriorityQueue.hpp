/*
    Header file for PriorityQueue
    Author: Alec Landow
*/

#include <iostream>
#include <queue>

using namespace std;

class PriorityQueue {
    private:
        class Node {
            public:
                int index;
                int priority;

                Node(int node_index, int priority) {
                    this->index = node_index;
                    this->priority = priority;
                }

                bool operator > (Node const & rightNode) const;
        };

        priority_queue<Node, vector<Node>, greater<Node>> queue;

        bool search_queue(
            int node_index,
            priority_queue<PriorityQueue::Node, vector<Node>, greater<Node>> queue
        );

        bool change_priority_helper(
            int node_index,
            int new_priority,
            priority_queue<Node, vector<Node>, greater<Node>> queue
        );

    public:
        bool change_priority(int node_index, int new_priority);
        const Node * min_priority();
        bool contains(int node_index);
        bool insert(int node_index, int priority);
        const Node * top();
        int size();

};
