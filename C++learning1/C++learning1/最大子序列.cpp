#include<iostream>
#include <vector>

using namespace std;

int fun1(const vector<int> & a)
{
	int maxsum = 0, thissum = 0;
	
	for (int j=0; j < a.size(); ++j)
	{
		thissum += a[j];
		if (thissum > maxsum)
			maxsum = thissum;
		else if (thissum < 0)
			thissum = 0;
	}
	return maxsum;
}

int main()
{
	int max=0;
	vector<int> a = {-8,3,-2,-6,8,7,-5};
	max = fun1(a);
	cout << max << endl;

	system("pause");
	return 0;
}