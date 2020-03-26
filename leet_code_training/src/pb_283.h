#ifndef _INCLUDE_PB_283_
#define _INCLUDE_PB_283_

#include <vector>
#include <string>

using namespace std;

class PB283
{
public :
	void Test();
private:
	void moveZeroes(vector<int>& nums);
	void print(string prefix, vector<int>& nums);
};

#endif