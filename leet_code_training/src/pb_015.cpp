/*
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

 

示例：

给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]

	来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include "pb_015.h"
#include <iostream>
#include <assert.h>
#include <algorithm>
#include <unordered_map>
#include <list>

void PB015::Test()
{
	cout<< "Start Test Pb 017..";
	vector<int> nums{-1,0,1,2,-1,-4};

	cout << "Test case : {-1,0,1,2,-1,-4}" << endl;
	vector<vector<int>> ret = threeSum2(nums);
	print(ret);

	assert(ret.size() == 2);
	assert(ret[0].size() == 3);
	assert(ret[1].size() == 3);
	assert(ret[1][0] == -1);
	assert(ret[1][1] == 0 );
	assert(ret[1][2] == 1);

	assert(ret[0][0]==-1);
	assert(ret[0][1]==-1);
	assert(ret[0][2]==2);

	cout<<"Test case : [0,0,0]" << endl;

	vector<int> nums2{0,0,0};
	ret = threeSum2(nums2);
	print(ret);
	assert(ret.size()==1);
	assert(ret[0][0]==0);
	assert(ret[0][1]==0);
	assert(ret[0][2]==0);
	
	cout << "Test case: [0,0,0,0]" << endl;
	vector<int> nums3{0,0,0,0};
	ret = threeSum2(nums3);
	print(ret);
	assert(ret.size() == 1);
	assert(ret[0][0]==0);
	assert(ret[0][1]==0);
	assert(ret[0][2]==0);

	cout << "test case: [-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6] " <<endl;
	vector<int> nums4{-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
	ret = threeSum2(nums4);
	print(ret);

	vector<int> nums5{1,-1,-1,0};
	cout<<"test case: [1,-1,-1,0]" << endl;
	ret = threeSum2(nums5);
	assert(ret.size() == 1);
	print(ret);

	vector<int> nums6{3,-2,1,0};
	cout << "test case: [3,-2,1,0]" << endl;
	ret = threeSum2(nums6);
	assert(ret.size()==0);
	print(ret);


	vector<int> nums7{-2,0,1,1,2};
	cout << "test case: [-2,0,1,1,2]" << endl;
	ret = threeSum2(nums7);
	assert(ret.size() == 2);
	print(ret);
	cout<<"Finsihed test pb 015..." << endl;
}

void PB015::print(vector<vector<int>>& ret)
{
	cout<<endl<<"result: "<<endl;
	for(size_t i=0; i<ret.size(); ++i)
	{
		for(size_t j=0; j < ret[i].size(); ++j)
		{
			cout << " val = " << ret[i][j];
		}

		cout << endl;
	}

}

//solution 1
//1. use the two sum to help
//2. loop to find the target of other two with the target = 0 - nums[i]
//3. unlike the two sum before, we need find all the pair in the pair
//4. remove tripple with same value in different order

//solution 2
//1. sort the input nums in ascending order
//2. loop from the end, other_two_sum = -nums[end]
//3. using two sum to find all the other possible
//4. then end -- to step 2
//5. loop can stop when left element is 2
//
//compare to solution 1, don't need to remove the duplicate tripple
vector<vector<int>> PB015::threeSum(vector<int>& nums)
{
	vector<vector<int>> ret;
	if(nums.size() <= 2)
		return ret;

	vector<int> sort_nums(nums);
	sort(sort_nums.begin(),sort_nums.end());

	/*
	cout << "sort_nums: ";
	for(auto begin=sort_nums.begin(); begin != sort_nums.end(); ++begin)
		cout << *begin << ",";
	cout<< endl;*/

	list<vector<int>> temp_ret;
	for(size_t end=sort_nums.size()-1; end >= 2;)
	{
		//cout << "search num: idx=" << end << " target =" << -sort_nums[end] << endl;
		int two_sum = - sort_nums[end];

		vector<vector<int>> two_list= twoSum(sort_nums, end-1, two_sum);
		if(two_list.size()>0)
		{
			for(size_t i=0; i<two_list.size();++i)
			{
				two_list[i].push_back(sort_nums[end]);
				temp_ret.push_back(two_list[i]);
			}
		}

		--end;

	}

	for(auto i = temp_ret.begin(); i!= temp_ret.end(); ++i)
	{
		bool is_duplicate = false;
		for(size_t idx=0; idx<ret.size(); ++idx)
		{
			if(compare(ret[idx], *i))
			{
				is_duplicate = true;
				break;
			}
		}

		if(!is_duplicate)
		{
			ret.push_back(*i);
		}

	}

	return ret;
}


vector<vector<int>> PB015::twoSum(vector<int> nums, int end_idx, int target)
{
	//找求和
	int start = 0;
	int end = end_idx;
	vector<vector<int>> ret;
	while (start < end)
	{
		//cout<<"start:" << nums[start] << " end:" << nums[end] << endl;
		int sum = nums[start] + nums[end];
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
			ret.push_back({nums[start],nums[end]});
			--end;
		}
	}//end while(start < end)

	return ret;
}

//solution3, just copy two sum
//1. sort to make complex to logn
//2. from first, then search from first+1 to end, where first = - (first+1 + end )
//3. rather then remove duplicate at last which cost O(n^2), we just loop to skip the same value for 1, 2,3 nums
vector<vector<int>> PB015::threeSum2(vector<int>& nums)
{
	vector<vector<int>> ret;
	if(nums.size() < 3)
		return ret;

	sort(nums.begin(), nums.end());
	
	for(size_t i=0; i<nums.size()-2;)
	{
		int target = -nums[i];
		size_t front = i+1;
		size_t end = nums.size()-1;

		while(front < end)
		{
			cout << nums[i] << ":" <<nums[front] << ":" << nums[end];
			int sum = nums[front] + nums[end];
			if(target == sum)
			{
				cout << "correct";
				ret.push_back({nums[i], nums[front++], nums[end--]});
				while(front < end && nums[end + 1] == nums[end]) end--;
				while(front < end && nums[front] == nums[front - 1 ]) front++; 
			}
			else if(target > sum)
			{
				cout << "fron ++ failed";
				front++;
			}
			else
			{
				cout << "end-- failed";
				end --;
			}


			cout << endl;
		}

		i ++ ;
		while( i<(nums.size()-2) && nums[i] == nums[i - 1 ]) ++i; 

	}//end for

	return ret; 
}
