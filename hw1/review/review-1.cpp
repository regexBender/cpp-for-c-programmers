#include<iostream> // Did not compile: `fatal error: 'iostream.h' file not found`
#include<vector>

using namespace std;
const int N = -40; // -40 differs from the input C program's 40
template<typename T> // Consider using something like `template <class summable>` to clarify that the generic type must be summable
int sum(T val) // Did not inline the function
{
 		 int s = 0;
		 for (int i=0; i<val.size();++i)
 		s += val[i];
		return s;
}
int main()
{
vector<int>vec;
for(int i =0; i<N; ++i) // Inconsistent spacing between vars and nums
vec.push_back(i); // Did not indent

cout<<"sum is"<<sum(vec)<<'\n'; // No semicolon, no space after "is", did not use `endl`
return 0;
}

// Did not convert comments to one line comments
