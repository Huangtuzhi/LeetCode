#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>

using namespace std;

//穷举法
// //默认nums是sorted,
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//     vector<int>::iterator iter1 = nums.begin();
//     vector<int>::iterator iter2;
//     int index1 = 1;
//     int index2 = 2;
//     vector<int> ret;

//     for(iter1; iter1 != nums.end(); iter1++, index1++)
//     {
//     	for(iter2=iter1+1, index2=index1+1; iter2 != nums.end(); iter2++, index2++)
//     	{
//     		if( *iter1 + *iter2 == target)
//     		{
//     			ret.push_back(index1);
//     			ret.push_back(index2);
//     			return ret;
//     		}
//     	}
//     } 
//     }
// };

//二分法
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//     vector<int> ret;
//     int cnt = 1;

//     sort(nums.begin(), nums.end());
//     for(auto i: nums) 
//     	cout << cnt++ << " : " << i << endl;

//     int vecSize = nums.size();
//     int low = 0;
//     int high = vecSize - 1;
//     int mid;
//     bool leftFlag = false;
//     bool rightFlag = false;


//     while(low<= high)
//     {
//     	mid = (low + high) / 2;
//     	if (nums[low] + nums[high] < target)
//     	{    	
//     	    leftFlag = true;	
//     		low = mid;
//     		if (rightFlag) //先右折半了
//     		{   
//     			mid = high;
//     			high = 2*mid + low;
//     			break;
//     		}
//     	}
//     	else if (nums[low] + nums[high] > target)
//     	{	
//     		rightFlag = true;
//     		high = mid;
//     		if (leftFlag) //先左折半了
//     		{
//     			mid = low;
//     			low = 2*mid - high;
//     			break;
//     		}
//     	}
//     	else
//     	{
//     		ret.push_back(low+1);
//     		ret.push_back(high+1);
//     		return ret;
//     	}
//     }

//     vector<int>::iterator iter1 = nums.begin() + low;
//     vector<int>::iterator iter2;
//     vector<int>::iterator end = nums.begin() + high;
//     int index1 = low + 1;
//     int index2 = low + 2;
//     for(iter1; iter1 != end; iter1++, index1++)
//     {
//     	for(iter2=iter1+1, index2=index1+1; iter2 != nums.end(); iter2++, index2++)
//     	{
//     		if( *iter1 + *iter2 == target)
//     		{
//     			ret.push_back(index1);
//     			ret.push_back(index2);
//     			return ret;
//     		}
//     	}
//     }

//     }
// };

// int main()
// {
// 	Solution Sol;
// 	vector<int> numbers{230,863,916,585,981,404,316,785,88,12,70,435,384,778,887,755,740,337,86,92,325,422,815,650,920,125,277,336,221,847,168,23,677,61,400,136,874,363,394,199,863,997,794,587,124,321,212,957,764,173,314,422,927,783,930,282,306,506,44,926,691,568,68,730,933,737,531,180,414,751,28,546,60,371};
// 	auto ret = Sol.twoSum(numbers, 720);
// 	for(auto r: ret)
// 		cout << r << endl;
// }

//Hash法

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> vec;
    map<int, int> dic;

    for (int i=0; i<nums.size(); i++)
    {
    	if (dic.find(nums[i]) == dic.end())
    		dic[target - nums[i]] = i;
    	else
    	{
    		vec.push_back(dic[nums[i]] + 1);
    		vec.push_back(i + 1);
    		return vec;;
    	}    	
    }    
    }
};

int main()
{
	Solution Sol;
	vector<int> numbers{230,863,916,585,981,404,316,785,88,12};
	auto ret = Sol.twoSum(numbers, 100);
	for(auto r: ret)
		cout << r << endl;
}
