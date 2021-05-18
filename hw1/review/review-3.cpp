//Convert this program to C++
//change to C++ io
//change to one line comments
//change defines of constants to const
//change array to vector<>
//inline any short function

#include <iostream>
#include <vector>
using namespace std;
const int N = 40;

inline void sum(int& p, int n, vector<int> d) // pass vector as reference
// Do not need to pass n. Can use d.size() instead
// Could have used generics
{
	for (int i=0; i<n; ++i)
		p += d[i];
}

int main(void)
{
	int i;
	int accum = 0;
	vector<int> data;

	for (int i=0; i<N; ++i)
		data.push_back(i);

	sum(accum, N, data);
	cout << "sum is " << accum << endl;

}
