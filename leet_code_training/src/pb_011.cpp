/*
给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，
使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。

输入: [1,8,6,2,5,4,8,3,7]
输出: 49

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/container-with-most-water
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include "pb_011.h"
#include <assert.h>
#include <iostream>
#include <algorithm>

void PB011::Test()
{
	cout << "Start testing pb 011..."<<endl;
	vector<int> height{1,8,6,2,5,4,8,3,7};
	
	int ret = maxArea(height);
	assert(49 == ret);

	cout << "finished test pb 011." << endl;
	return;
}

//Solution 1:
//1. loop from start and end together
//2. cal area = min(height[start],height[end]) * (start - end)
//3. if height[start] > height[end], then we move the end one index back
//4. vise visa if height[start] < height[end]
//
//the provement of this solution could be found on leetcode.com not the leetcode-cn.com
//
//time: 24ms
//memory: 16MB
//42.94%
int PB011::maxArea(vector<int>& height)
{
	int max_area = 0;

	for(size_t start = 0, end =height.size()-1; start < end; )	
	{

		int area = min(height[start], height[end]) * (end-start);
		max_area = max(area, max_area);

		if(height[start] > height[end])
		{
			--end;
		}
		else
		{
			++start;
		}

	}

	return max_area;
}
