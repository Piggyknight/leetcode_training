
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
#include <algorithm> //std::sort

void PB001::Test()
{
	cout << "开始测试Pb001..." << endl;
	//vector<int> nums{ 2, 7, 11, 15 };
	//int target = 9;
	vector<int> nums {3,2,4};
	int target = 6;

	auto result = twoSum2(nums, target);

	assert(2 == result.size());
	assert(1 == result[0]);
	assert(2 == result[1]);

	cout << "结束测试Pb001" << endl;
}

//方案:
// - 一遍hash遍历, hash的key 数值, value是idx
// - 输入是int值域, 因此负数加法应该也需要支持
// - 用minus_ret = target - 遍历值来查找是否存在, 存在则说明找到答案了
// - 如果不存在, 则把自己保存
//
// time: 12ms
// memory: 12MB
// 83.22%
vector<int> PB001::twoSum(vector<int>& nums, int target)
{
	unordered_map<int, int> search_map;
	vector<int> result;

	for (size_t i = 0; i < nums.size(); ++i)
	{
		int minus_ret = target - nums[i];
		if (search_map.end() != search_map.find(minus_ret))
		{
			result.push_back(search_map[minus_ret]);
			result.push_back(i);
			break;
		}

		search_map.insert({ nums[i], i});
	}

	return result;

}


//方案2:
//1. 先进行排序
//2. 从有序数组的一头一尾求和, 找到只有a+b = target的两个数
//3. 通过数值找到相应的序列号
//4. 边界情况: a==b下, 需要跳过第一个
//
//time: 8ms
//memory: 11.6MB
//96.52%
//
// 奇怪的是我用java相同算法, time是4ms, memory: 39.6MB, 72.87%
vector<int> PB001::twoSum2(vector<int>& nums, int target)
{
	//升序排序
	vector<int> sort_nums(nums);
	sort(sort_nums.begin(), sort_nums.end());


	//找求和
	int start = 0;
	int end = sort_nums.size() - 1;
	int a = 0 , b = 0;
	while (start < end)
	{
		int sum = sort_nums[start] + sort_nums[end];
		if (sum < target)
		{
			++start;
		}
		else if(sum > target)
		{
			--end;
		}
		else
		{
			a = sort_nums[start];
			b = sort_nums[end];
			break;
		}
	}//end while(start < end)

	//找数组索引
	vector<int> ret;
	for (size_t i = 0; i < nums.size() ; ++i)
	{
		if (a == nums[i])
		{
			ret.push_back(i);
			break;
		}
	}

	if (a != b)
	{
		for (size_t i = 0; i < nums.size() ; ++i)
		{
			if (b == nums[i])
			{
				ret.push_back(i);
				break;
			}
		}//end for
	}
	else
	{
		for (size_t i = 0; i < nums.size(); ++i)
		{
			if (b == nums[i] && i != ret[0])
			{
				ret.push_back(i);
				break;
			}
		}
	}//end if(a!=b)

	return ret;

}
