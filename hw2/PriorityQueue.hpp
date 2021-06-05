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
            private:
                int index;
                int priority;
            public:
                Node(int node_index, int priority) {
                    this->index = node_index;
                    this->priority = priority;
                }
        }
        priority_queue<PriorityQueue::Node, vector<PriorityQueue::Node>, greater<PriorityQueue::Node::priority>> queue;

        bool search_queue(
            int node_index,
            priority_queue<PriorityQueue::Node, vector<PriorityQueue::Node>, greater<PriorityQueue::Node::priority>> queue
        );

        bool change_priority_helper(
            int node_index,
            int new_priority,
            priority_queue<PriorityQueue::Node, vector<PriorityQueue::Node>, greater<PriorityQueue::Node::priority>> queue
        );

    public:
        bool change_priority(int node_index, int new_priority);
        int min_priority();
        bool contains(int node_index);
        bool insert(int node_index, int priority);
        int top();
        int size();

}
