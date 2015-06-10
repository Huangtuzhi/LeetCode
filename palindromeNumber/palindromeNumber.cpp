#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) return false;
		if (x/10 == 0) return true; //个位数
		queue<int> num_queue;
		stack<int> num_stack;

		while (x / 10)
		{
			num_queue.push(x % 10);
			num_stack.push(x % 10);
			x = x / 10;
		}
		num_queue.push(x % 10);
		num_stack.push(x % 10);
		int length = num_queue.size();

		if (!(length%2)) {  //运算符同级，从左到右
			while (num_queue.size() != length/2) {
				if (num_queue.front() == num_stack.top())
				{
					num_queue.pop();
					num_stack.pop();
				} else {
					return false;
				}
			}
			return true;		
		}

		else {
			while (num_queue.size() != length/2 + 1) {
				if (num_queue.front() == num_stack.top())
				{
					num_queue.pop();
					num_stack.pop();
				} else {
					return false;
				}				
			}
			return true;
		}
	}
};

int main()
{
	Solution sol;
	int x1 = 121;
	int x2 = -121;
	int x3 = 123321;
	int x4 = -123321;
	int x5 = 2;
	int x6 = -2;
	int x7 = -2147447412;
	int x8 = 2147447412;
	int x9 = 13;
	cout << sol.isPalindrome(x1) << endl;
	cout << sol.isPalindrome(x2) << endl;
	cout << sol.isPalindrome(x3) << endl;
	cout << sol.isPalindrome(x4) << endl;
	cout << sol.isPalindrome(x5) << endl;
	cout << sol.isPalindrome(x6) << endl;
	cout << sol.isPalindrome(x7) << endl;
	cout << sol.isPalindrome(x8) << endl;
	cout << sol.isPalindrome(x9) << endl;
	return 0;
}
