#include <iostream>
#include <vector>
using namespace std;

//复杂度高n^2
// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//     	if (height.size() == 1 || height.size() == 0)
//     		return 0;
//     	int max_area = 0;
//     	int mark_p, mark_b;
//     	for(int point_p=0; point_p<height.size()-1;) {
//     		int add_p = 1;
//     		int add_init = 1;
//     		int init_b = point_p + 1;

//  			while(init_b < height.size() && height[init_b+1] < height[init_b+add_init+1] && 
//  				height[init_b+add_init] < height[init_b+add_init+1]) {
//  				add_init++;
//  			}
//  			init_b= init_b + add_init;

//     		for(int point_b = init_b; point_b<height.size();) {    			
//     			int add_b = 1;
//     			int area = getMin(height[point_p], height[point_b]) * (point_b - point_p);
//     			if (area > max_area) {
//      				max_area = area;
//      				mark_p = point_p;	
//      				mark_b = point_b;	
//      				cout << "mark_p : " << mark_p << endl;
//      				cout << "mark_b : " << mark_b << endl;		
//      			}
//      			while(point_b < height.size() && height[point_b+1] < height[point_b+add_b+1] && 
//      				height[point_b+add_b] < height[point_b+add_b+1]) {
//      				add_b++;
//      			}
//      			point_b = point_b + add_b;
//     		}

//     		while(point_p < mark_b && height[point_p] > height[point_p+add_p]) {
//     			add_p++;
//     		}
//     		point_p = point_p + add_p;
//     	}
//     	return max_area;         
//     }

//     int getMin(int a, int b) {
//     	return a < b ? a : b;
//     }
// };


class Solution {
public:
    int maxArea(vector<int>& height) {
    	if (height.size() == 1 || height.size() == 0)
    		return 0;
    	int max_area = 0;
    	int begin = 0; 
    	int end = height.size() - 1;
    	while (begin < end)
    	{
    		int area = getArea(height, begin, end);
    		max_area = area > max_area ? area : max_area;
    		if (height[begin] < height[end])
    			begin++;
    		else
    			end--;
    	}
    	return max_area;

    }

    int getArea(vector<int>& height, int posA, int posB) {
    	int h = height[posA] < height[posB] ?  height[posA] : height[posB];
    	return h * (posB - posA);
    }
};

int main()
{
	Solution sol;
	vector<int> h{1,2,3,3};
	cout << sol.maxArea(h) << endl;
	return 0;
}