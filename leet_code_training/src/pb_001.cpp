
/*
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

#include "pb_001.h"
#include <iostream>
#include <assert.h>
#include <unordered_map>

void PB001::Test()
{
	cout << "开始测试Pb001..." << endl;
	vector<int> nums{ 2, 7, 11, 15 };
	int target = 9;

	auto result = twoSum(nums, target);

	assert(2 == result.size());
	assert(0 == result[0]);
	assert(1 == result[1]);

	cout << "结束测试Pb001" << endl;
}

//方案:
// - 一遍hash遍历, hash的key 数值, value是idx
// - 输入是int值域, 因此负数加法应该也需要支持
// - 用minus_ret = target - 遍历值来查找是否存在, 存在则说明找到答案了
// - 如果不存在, 则把自己保存
//
vector<int> PB001::twoSum(vector<int>& nums, int target)
{
	unordered_map<int, int> search_map;
	vector<int>* result = new vector<int>();

	for (int i = 0; i < nums.size(); ++i)
	{
		int minus_ret = target - nums[i];
		if (search_map.end() != search_map.find(minus_ret))
		{
			result->push_back(search_map[minus_ret]);
			result->push_back(i);
			break;
		}

		search_map.insert({ nums[i], i});
	}

	return *result;

}

