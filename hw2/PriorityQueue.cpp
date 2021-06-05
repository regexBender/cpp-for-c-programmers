/*
    Implementation of PriorityQueue
    Author: Alec Landow
*/
#ifndef PQ_H
#define PQ_H

#include "PriorityQueue.hpp"

const int EMPTY_NODE_INDICATOR = -1;

bool PriorityQueue::change_priority(int node, int new_priority) {
    return this->change_priority_helper(node, new_priority, this->queue);
}

int PriorityQueue::min_priority() {
    if (this->queue.empty()) {
        return EMPTY_NODE_INDICATOR;
    }

    return return this->queue.pop();
}

bool PriorityQueue::contains(int node_index) {
    // Pass by value so node elements will not be removed from the actual queue
    return this->search_queue(node_index, this->queue);
}

bool PriorityQueue::insert(int node_index, int priority) {
    if (this->contains(node_index)) {
        return false;
    }

    this->queue->emplace(node_index, priority);

    return true;
}

int PriorityQueue::top() {
    return this->queue.top();
}

int PriorityQueue::size() {
    return this->queue.size();
}

bool search_queue(
    int node_index,
    priority_queue<PriorityQueue::Node, vector<PriorityQueue::Node>, greater<PriorityQueue::Node::priority>> queue
) {
    while (!queue.empty()) {
        if (queue.top().index == node_index) {
            return true;
        }
        queue.pop();
    }
    return false;
}

bool change_priority_helper(
    int node_index,
    int new_priority,
    priority_queue<PriorityQueue::Node, vector<PriorityQueue::Node>, greater<PriorityQueue::Node::priority>> queue
) {
    priority_queue<PriorityQueue::Node, vector<PriorityQueue::Node>, greater<PriorityQueue::Node::priority>> updated_queue;
    bool node_was_present_and_priority_changed = false;
    while (!queue.empty()) {
        if (queue.top().index == node_index) {
            updated_queue.emplace(node_index, new_priority);
            node_was_present_and_priority_changed = true;
        } else {
            updated_queue.emplace(queue.top().index, queue.top().priority);
        }
        queue.pop();
    }

    if (node_was_present_and_priority_changed) {
        this->queue = updated_queue;
    }
    return node_was_present_and_priority_changed;
}
#endif
