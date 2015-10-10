#include <iostream>
#include <vector>
#include <math.h>
#include <initializer_list>
#include <algorithm>

using namespace std;

class Solution
{
public:
	int twoSumClosest(vector<int>& nums, int start, int target)
	{
		int sum_min = 100000;
		int closest_length = 10000;
		for(int i=start+1, j=nums.size()-1; i<j;)
		{
			if(abs(nums[i] + nums[j] - target) < closest_length)
			{
				closest_length = abs(nums[i] + nums[j] - target);
				sum_min = nums[i] + nums[j];
			}

			if(nums[i] + nums[j] < target)
				i++;
			else if(nums[i] + nums[j] > target)
				j--;
			else
				return sum_min;
		}

		return sum_min; 
	}

	int threeSumClosest(vector<int>& nums, int sum_target)
	{
		sort(nums.begin(), nums.end());

		int sum_min = 10000;
		int start_pos = 0;
		int closest_num = 10000;
		for(int start=0; start<nums.size()-2; start++)
		{
			int two_sum = twoSumClosest(nums, start, sum_target-nums[start]);
			if ( abs(two_sum - (sum_target-nums[start])) <= closest_num)
			{	
				closest_num = abs(two_sum - (sum_target-nums[start]));
				sum_min = two_sum;
				start_pos = start;				
			}
		} 

		return sum_min + nums[start_pos];
	}
};

int main()
{
	Solution sol;
	vector<int> arr = {13,2,0,-14,-20,19,8,-5,-13,-3,20,15,20,5,13,14,-17,-7,12,-6,0,20,-19,-1,-15,-2,8,-2,-9,13,0,-3,-18,-9,-9,-19,17,-14,-19,-4,-16,2,0,9,5,-7,-4,20,18,9,0,12,-1,10,-17,-11,16,-13,-14,-3,0,2,-18,2,8,20,-15,3,-13,-12,-2,-19,11,11,-10,1,1,-10,-2,12,0,17,-19,-7,8,-19,-17,5,-5,-10,8,0,-12,4,19,2,0,12,14,-9,15,7,0,-16,-5,16,-12,0,2,-16,14,18,12,13,5,0,5,6};
	cout << sol.threeSumClosest(arr, -59) << endl;
}
