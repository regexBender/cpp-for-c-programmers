/*
    Implementation of PriorityQueue
    Author: Alec Landow
*/
#include "PriorityQueue.hpp"


bool PriorityQueue::change_priority(int node, int new_priority) {
    return this->change_priority_helper(node, new_priority, this->queue);
}

PriorityQueue::Node PriorityQueue::min_priority() {
    if (this->queue.empty()) {
        return Node(-1, -1);
    }

    Node top = Node(this->top()->index, this->top()->priority);
    this->queue.pop();
    return top;
}

bool PriorityQueue::contains(int node_index) {
    // Pass by value so node elements will not be removed from the actual queue
    return this->search_queue(node_index, this->queue);
}

bool PriorityQueue::insert(int node_index, int priority) {
    if (this->contains(node_index)) {
        return false;
    }

    this->queue.emplace(node_index, priority);

    return true;
}

const PriorityQueue::Node * PriorityQueue::top() {
    return &( this->queue.top() );
}

int PriorityQueue::size() {
    return this->queue.size();
}

bool PriorityQueue::search_queue(
    int node_index,
    priority_queue<PriorityQueue::Node, vector<PriorityQueue::Node>, greater<PriorityQueue::Node>> queue
) {
    while (!queue.empty()) {
        if (queue.top().index == node_index) {
            return true;
        }
        queue.pop();
    }
    return false;
}

bool PriorityQueue::change_priority_helper(
    int node_index,
    int new_priority,
    priority_queue<PriorityQueue::Node, vector<PriorityQueue::Node>, greater<PriorityQueue::Node>> queue
) {
    priority_queue<PriorityQueue::Node, vector<PriorityQueue::Node>, greater<PriorityQueue::Node>> updated_queue;
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

int PriorityQueue::Node::get_index() const {
    return this->index;
}

int PriorityQueue::Node::get_priority() const {
    return this->priority;
}

bool PriorityQueue::Node::operator > (const PriorityQueue::Node & rightNode) const {
    return this->priority > rightNode.priority;
}
