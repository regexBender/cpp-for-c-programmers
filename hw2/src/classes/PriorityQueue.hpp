/*
    Header file for PriorityQueue
    Author: Alec Landow
*/

#include <iostream>
#include <queue>

using namespace std;

class PriorityQueue {
    public:
        class Node {
            friend class PriorityQueue;
            private:
                int index;
                int priority;

            public:
                Node(int node_index, int priority) {
                    this->index = node_index;
                    this->priority = priority;
                }

                int get_index() const;
                int get_priority() const;
                bool operator > (Node const & rightNode) const;
        };

        bool change_priority(int node_index, int new_priority);
        Node min_priority();
        bool contains(int node_index);
        bool insert(int node_index, int priority);
        const Node * top();
        int size();

    private:
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


};
