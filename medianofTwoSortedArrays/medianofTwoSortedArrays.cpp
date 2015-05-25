#include <vector>
#include <algorithm>
#include <memory>
#include <iostream>
#include <initializer_list>

using namespace std;

class Solution {
public:
	int findIndexInNums2(int num, vector<int>& nums2);
	int findIndexHelper(int num, vector<int>& nums2);
	int pickInNums1(vector<int>& nums1, vector<int>& nums2);
	double pickInNums1WhenEven(vector<int>& nums1, vector<int>& nums2);
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	bool isOdd = (nums1.size() + nums2.size()) % 2;
    	if(!nums1.size() && nums2.size()%2==1)
			return nums2[nums2.size()/2];
		if(!nums1.size() && nums2.size()%2==0)
			return (nums2[nums2.size()/2] + nums2[nums2.size()/2-1])/2.0;
		if(!nums2.size() && nums1.size()%2==1)
			return nums1[nums1.size()/2];
		if(!nums2.size() && nums1.size()%2==0)
			return (nums1[nums1.size()/2] + nums1[nums1.size()/2-1])/2.0;


		if(!nums1.size() && !nums2.size())
			return 0;

		if (isOdd){
			if(pickInNums1(nums1, nums2) == -1)
    			return pickInNums1(nums2, nums1);
    		else 
    			return pickInNums1(nums1, nums2);  		
    	}
    	else {
    		if(pickInNums1(nums1, nums2) == -1)
    			return pickInNums1(nums2, nums1);
    		else 
    			return pickInNums1(nums1, nums2); 
    	}
    }
};

int Solution::findIndexInNums2(int num, vector<int>& nums2)
{
	int low = 0;
	int high = nums2.size() - 1;

	while (low <= high)
	{
		int mid = low + (high - low)/2;
		if (num == nums2[mid]) return mid;
		if (num > nums2[mid]) {
			low = mid + 1;
		}
		else {
			high = mid - 1;	
		}	
	}
	return low;	
}

//找出相同数字最后的位置
int Solution::findIndexHelper(int num, vector<int>& nums2)
{
	int find = 	findIndexInNums2(num, nums2);
	while (num == nums2[find]) {
		find++;
	}
	return find;
}

int Solution::pickInNums1(vector<int>& nums1, vector<int>& nums2)
{
	int total = nums1.size() + nums2.size();
	int median_index = total / 2;  // 奇数的情况
	// cout << "median_index: " << median_index << endl;
	int index = 1;
	int low = 0;
	int high = nums1.size() - 1;

	while(low <= high)
	{
		int mid = low + (high - low)/2;
		cout << "loop:" << index++ << " " << "low: " << low << " | " << "mid: " << mid << " | " << "high: " << high << endl;
		//两个数合并后的总位置
		int count = findIndexHelper(nums1[mid], nums2) + mid;
		cout << "count: " << count << endl;
		if (median_index == count) return nums1[mid];
		if (median_index > count) {
			low = mid + 1;
		}
		else {
			high = mid - 1;	
		}
	}
	return -1;
}

double Solution::pickInNums1WhenEven(vector<int>& nums1, vector<int>& nums2)
{
	int total = nums1.size() + nums2.size();
	int median_index = total / 2;  // 偶数的情况
	// cout << "median_index: " << median_index << endl;
	int low = 0;
	int high = nums1.size() - 1;

	while(low <= high)
	{
		int mid = low + (high - low)/2;
		cout << "low: " << low << " | " << "mid: " << mid << " | " << "high: " << high << endl;
		//两个数合并后的总位置
		int count = findIndexHelper(nums1[mid], nums2) + mid;
		cout << "count: " << count << endl;
		if (median_index == count) return (nums1[mid]+nums1[mid+1])/2.0;
		if (median_index > count) {
			low = mid + 1;
		}
		else {
			high = mid - 1;	
		}
	}
    return (nums1[low]+nums1[low+1])/2.0;
}



int main()
{
	Solution sol;
	// vector<int> vec1{1, 2, 3, 3, 3, 3, 3, 7, 8};
	// vector<int> vec2{4, 6, 6, 6, 10, 12, 16, 19};
	vector<int> vec1{1, 2, 3};
	vector<int> vec2{1, 4, 5};
	// if(pickInNums1(vec1, vec2) == -1)
	// 	cout << pickInNums1(vec2, vec1) << endl;
	// else 
	// 	cout << pickInNums1(vec1, vec2) << endl;
	cout << sol.findMedianSortedArrays(vec1, vec2) << endl;
}