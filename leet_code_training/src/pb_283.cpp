/*
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

示例:

输入: [0,1,0,3,12]
输出: [1,3,12,0,0]
说明:

必须在原数组上操作，不能拷贝额外的数组。
尽量减少操作次数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/move-zeroes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include "pb_283.h"
#include <iostream>

void PB283::Test()
{
	vector<int> nums{0,1,0,3,12};
	print("input:", nums);
	moveZeroes(nums);
	print("output:", nums);


}

void PB283::moveZeroes(vector<int>& nums) 
{
	size_t cur_zero_idx = 0;

	for (size_t i = 0; i < nums.size(); ++i)
	{
		if (nums[i] != 0)
		{
			auto temp = nums[cur_zero_idx];
			nums[cur_zero_idx] = nums[i];
			nums[i] = temp;
			++cur_zero_idx;
		}

	}

}

void PB283::print(string prefix, vector<int>& nums)
{
	cout << prefix << "{";
	for (auto begin = nums.begin(); begin != nums.end(); begin++)
	{
		cout << *begin;
	}
	cout << "}" << endl;
}
