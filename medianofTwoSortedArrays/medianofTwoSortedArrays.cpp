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
	int findIndexPrevHelper(int num, vector<int>& nums2);
	int pickInNums1(vector<int>& nums1, vector<int>& nums2);
	int pickInNums1Unique(vector<int>& nums1, vector<int>& nums2);
	vector<int> pickInNums1WhenEven(vector<int>& nums1, vector<int>& nums2);
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	vector<int> ret1;
    	vector<int> ret2;
    	int left_mid = (nums1.size() + nums2.size()) / 2 - 1;
    	int right_mid = (nums1.size() + nums2.size()) / 2;
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
			if(pickInNums1(nums1, nums2)==-1 && pickInNums1(nums2, nums1)!=-1)
    			return pickInNums1(nums2, nums1);
    		else if(pickInNums1(nums2, nums1)==-1 && pickInNums1(nums1, nums2)!=-1)
    			return pickInNums1(nums1, nums2);
    		else 
    			return pickInNums1Unique(nums1, nums2);	 	
    	}
    	else {
    		ret1 = pickInNums1WhenEven(nums1, nums2);
    		ret2 = pickInNums1WhenEven(nums2, nums1);
    		cout << "here1: " << ret1[0] << endl;
    		cout << "here2: " << ret2[0] << endl;
    		cout << "here3: " << (findIndexPrevHelper(nums1[ret1[1]+1], nums2) + ret1[1]+1) << endl;
    		cout << "ret1[0]: " << ret1[0] << endl;
    		if (ret1[0]==left_mid && (findIndexPrevHelper(nums1[ret1[1]+1], nums2) + ret1[1]+1)==right_mid)
    		{
    			cout << nums1[ret1[1]] << " " << nums1[ret1[1]+1] << endl;
    			return (nums1[ret1[1]] + nums1[ret1[1]+1]) / 2.0;
    		}
    		if (ret1[0]==right_mid && (findIndexHelper(nums1[ret1[1]-1], nums2) + ret1[1]-1)==left_mid)
    			return (nums1[ret1[1]] + nums1[ret1[1]-1]) / 2.0;
    		if (ret2[0]==left_mid && (findIndexHelper(nums2[ret2[1]+1], nums1) + ret2[1]+1)==right_mid)
    			return (nums2[ret2[1]] + nums2[ret2[1]+1]) / 2.0;
    		if (ret2[0]==right_mid && (findIndexHelper(nums2[ret2[1]-1], nums1) + ret2[1]-1)==left_mid)
    			return (nums2[ret2[1]] + nums2[ret2[1]-1]) / 2.0;
    		if (ret1[0]==left_mid && ret2[0]==left_mid)
    			return (nums1[ret1[1]] + nums1[ret1[1]+1]) / 2.0;
    		else
    			return (ret1[2] + ret2[2]) / 2.0;
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

//找出相同数字最前的位置
int Solution::findIndexPrevHelper(int num, vector<int>& nums2)
{
	int find = 	findIndexInNums2(num, nums2);
	while (num == nums2[find]) {
		find--;
	}
	return find + 1;
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
		// cout << "loop:" << index++ << " " << "low: " << low << " | " << "mid: " << mid << " | " << "high: " << high << endl;
		//两个数合并后的总位置
		int count = findIndexHelper(nums1[mid], nums2) + mid;
		// cout << "count: " << count << endl;
		if (median_index == count) return mid;
		if (median_index > count) {
			low = mid + 1;
		}
		else {
			high = mid - 1;	
		}
	}
	return -1;
}

//当用最后策略不能时
int Solution::pickInNums1Unique(vector<int>& nums1, vector<int>& nums2)
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
		// cout << "loop:" << index++ << " " << "low: " << low << " | " << "mid: " << mid << " | " << "high: " << high << endl;
		//两个数合并后的总位置
		int count = findIndexPrevHelper(nums1[mid], nums2) + mid;
		// cout << "count: " << count << endl;
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

vector<int> Solution::pickInNums1WhenEven(vector<int>& nums1, vector<int>& nums2)
{
	//偶数的情况
	vector<int> ret;
	int total = nums1.size() + nums2.size();
	int median_index_1 = total / 2 - 1; //第一个index
	int median_index_2 = total / 2;  //第二个index
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

		if (count == median_index_1){
			ret.push_back(count);
			ret.push_back(mid);
			ret.push_back(nums1[mid]);
			return ret;
		} 
	    if (count == median_index_2){ 
			ret.push_back(count);
			ret.push_back(mid);
			ret.push_back(nums1[mid]);
			return ret;
		}
		if (median_index_1 > count) {
			low = mid + 1;
		}
		else{
			high = mid - 1;	
		}
	}
	ret.push_back(-1);
    return ret;
}



int main()
{
	Solution sol;
	// vector<int> vec1{1, 2, 3, 3, 3, 3, 3, 7, 8};
	// vector<int> vec2{4, 6, 6, 6, 10, 12, 16, 19};
	vector<int> vec1{1, 2, 2};
	vector<int> vec2{1, 2, 3};
	// if(pickInNums1(vec1, vec2) == -1)
	// 	cout << pickInNums1(vec2, vec1) << endl;
	// else 
	// 	cout << pickInNums1(vec1, vec2) << endl;
	cout << sol.findMedianSortedArrays(vec1, vec2) << endl;
}