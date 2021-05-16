// HW1
// Author: Alec Landow
//
// Problem Statement:
//    Convert this program to C++
//    change to C++ io
//    change to one line comments
//    change defines of constants to const
//    change array to vector<>
//    inline any short function


#include <iostream>
#include <vector>

using namespace std;

const int N = 40;

template <class summable> // summable must be a type that has a meaningful + operator
inline void sum(summable& accumulator, const vector<summable>& data) {
    accumulator = 0;

    summable n = data.size();
    for(int i = 0; i < n; ++i)
        accumulator += data.at(i);
}

int main() {
    int accum = 0;
    vector<int> data;

    for(int i = 0; i < N; ++i)
        data.push_back(i);

    sum(accum, data);

    cout << "sum is " << accum << endl;

    return 0;
}
