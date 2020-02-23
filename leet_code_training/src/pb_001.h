#ifndef _INCLUDE_PB_001_
#define _INCLUDE_PB_001_

#include <vector>
using namespace std;

class PB001
{
public :
	void Test();
private:
	vector<int> twoSum(vector<int>& nums, int target);
	vector<int> twoSum2(vector<int>& nums, int target);
};

#endif // _INCLUDE_PB_001_

