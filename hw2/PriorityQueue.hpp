/*
    Header file for PriorityQueue
    Author: Alec Landow
*/

#include <iostream>
#include <queue>

using namespace std;

class PriorityQueue {
    private:
        priority_queue<int, vector<int>, greater<int>> queue;

    public:
        bool change_priority(int node, int new_priority);
        int min_priority();
        bool contains(int node);
        bool insert(int node, int priority);
        int top();
        int size();

}
