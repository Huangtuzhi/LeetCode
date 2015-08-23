/* version1 ： 时间复杂度高，leetcode超时，后续优化算法 */
#include <iostream>
#include <vector>
#include <initializer_list>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) 
    {
    	vector<vector<int> > tripletVec;
		if (nums.size() < 3)
		{
			return tripletVec; 	
		}

		if (nums.size() == 3)
		{
			vector<int> triplet;
			triplet.push_back(nums[0]);
			triplet.push_back(nums[1]);
			triplet.push_back(nums[2]);
			sort(triplet.begin(), triplet.end());
			tripletVec.push_back(triplet);
			return tripletVec;
		}

		int m = nums.size();
		vector<int> slot;
		vector<vector<int> > slotVec;

		//slotVec的第一个元素为1 1 1 0 0 0 0 0 0 ....
		for (int i=0; i<3; i++)
			slot.push_back(1);
		for (int i=0; i<nums.size()-3; i++)
			slot.push_back(0);
		slotVec.push_back(slot);

		int len = nums.size();

		while (1)
		{
			int beforeCount = 0;//在i之前的1的个数，用来输出
			int i, j;

			for (i=0; i< len; i++)
			{
				if (slot[i] == 1 && slot[i+1] == 0)
				{
			    	slot[i] = 0;
					slot[i+1] = 1;
					break;
				}

				if (slot[i])
					beforeCount++;
			}

			for (j=0; j<i; j++)
			{
				if (j < beforeCount)
					slot[j] = 1; //相当于恢复之前的slot
				else
					slot[j] = 0;
			}

			slotVec.push_back(slot);			

			if (slot[len-1]==1 && slot[len-2]==1 && slot[len-3]==1)
				break; 
		}

		//开始找slotVec中对应的为1的triplet
		for( auto vec : slotVec)
		{
			vector<int> triplet;
			int sum = 0;
			for(int index=0; index<len; index++)
			{	
				if (vec[index] == 1)
				{
					triplet.push_back(nums[index]);
					sum += nums[index];
				}
			}	

			if (sum == 0)
			{
				//对vector排序
				sort(triplet.begin(), triplet.end());
				tripletVec.push_back(triplet);
			}
		}

		// vector去重
		vector<vector<int> >::iterator iter = unique(tripletVec.begin(), tripletVec.end());
		tripletVec.erase(iter,tripletVec.end());

		return tripletVec;
	}
};

int main()
{
	Solution sol;
	vector<int> nums = {-13,5,13,12,-2,-11,-1,12,-3,0,-3,-7,-7,-5,-3,-15,-2,14,14,13,6,-11,-11,5,-15,-14,5,-5,-2,0,3,-8,-10,-7,11,-5,-10,-5,-7,-6,2,5,3,2,7,7,3,-10,-2,2,-12,-11,-1,14,10,-9,-15,-8,-7,-9,7,3,-2,5,11,-13,-15,8,-3,-7,-12,7,5,-2,-6,-3,-10,4,2,-5,14,-3,-1,-10,-3,-14,-4,-3,-7,-4,3,8,14,9,-2,10,11,-10,-4,-15,-9,-1,-1,3,4,1,8,1};
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
