#ifndef _INCLUDE_PB_015_
#define _INCLUDE_PB_015_

#include <vector>
using namespace std;

class PB015
{
public:
	void Test();
private:
	vector<vector<int>> threeSum(vector<int>& nums);
	vector<vector<int>> twoSum(vector<int> nums, int end, int target);
	void print(vector<vector<int>>& ret);
	static bool compare(vector<int> a, vector<int> b)
	{
		if(a.size() != b.size())
			return false;

		for(size_t i=0; i<a.size(); ++i)
		{
			if(a[i] != b[i])
				return false;
		}
		return true;
	}

	vector<vector<int>> threeSum2(vector<int>& nums);
	
};
#endif
