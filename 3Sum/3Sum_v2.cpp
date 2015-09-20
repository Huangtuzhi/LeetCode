#include <iostream>
#include <vector>
#include <initializer_list>
#include <algorithm>
#include <map>
using namespace std;

class Solution
{
public:
	void twoSum(vector<int> &nums, int start, int target, vector<vector<int> > &treeNumPair)
	{
		int head = start;
		int tail = nums.size() - 1;

		while(head < tail)
		{
			int sum = nums[head] + nums[tail];
			if (sum == target)
			{
				treeNumPair.push_back(vector<int>{nums[start-1], nums[head], nums[tail]});

				int nextMayDul = head + 1;
				while(nums[nextMayDul] == nums[head])
					nextMayDul++;
				head = nextMayDul;

				int preMayDul = tail - 1;
				while(nums[preMayDul] == nums[tail])
					preMayDul--;
				tail = preMayDul;
			}
			if (sum < target) head++;
			if (sum > target) tail--;
			// cout << start-1 << " -> " << head << " -> " << tail << endl; 
		}
	}

	vector<vector<int> > threeSum(vector<int> & nums)
	{
		sort(nums.begin(), nums.end());
		vector<vector<int> > treeNumPair;
		
		if (nums.size() < 3)
		{
			return treeNumPair; 	
		}

		for(int i=0; i<nums.size()-2; i++)
		{
			int target = 0 - nums[i];
			if (i > 0 && nums[i] == nums[i-1]) continue;
			twoSum(nums, i+1, target, treeNumPair);
		}
		return treeNumPair;
	}
};

int main()
{
	Solution sol;
	vector<int> nums = {-1, 0, 1, 2, -1, -4};
	sort(nums.begin(), nums.end());
	vector<vector<int> > vecVec = sol.threeSum(nums);

	for( auto vec : vecVec)
	{
		for(int x=0; x< 3; x++)
		{
			cout << " : " << vec[x];
		}	
		cout << endl;
	}

	return 0;
}

