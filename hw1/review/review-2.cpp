#include <iostream>
#include <vector>

using namespace std;

const int N = 40;

template <typename T> // Consider using something like `template <class summable>` to clarify that the generic type must be summable
int sum(T val) // Did not inline
{
	int s = 0;
	for(int i = 0; i < val.size(); ++i)
		s += val[i]; // Another option is to use vector::at() (see https://thispointer.com/c-how-to-get-element-by-index-in-vector-at-vs-operator/)
	return s;
}

int main()
{
	vector<int> vec;

	for(int i = 0; i < N; ++i)
		vec.push_back(i);

	cout<<" sum is "<< sum(vec) << '\n'; // Did not use `endl`, inconsistent spacing around operators
	return 0;
}

// Did not convert to one line comments
