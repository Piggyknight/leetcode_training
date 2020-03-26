/*
����һ������ nums����дһ������������ 0 �ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��

ʾ��:

����: [0,1,0,3,12]
���: [1,3,12,0,0]
˵��:

������ԭ�����ϲ��������ܿ�����������顣
�������ٲ���������

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/move-zeroes
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
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
