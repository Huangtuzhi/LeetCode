#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

class Solution {
public:
	int reverse(int x) {
		if (x == 0) return 0;
		stack<int> num_stack;
		double ret = 0;
		bool sign = true;
		//注意-2^32
		if (x < 0) {
			sign = false; 
			x = -x;
		}

		while (x / 10)
		{
			num_stack.push(x % 10);
			x = x / 10;
		}
		num_stack.push(x % 10);

		int move = 0;
		while (!num_stack.empty()) {
			ret += num_stack.top()*pow(10,move++);    
			num_stack.pop();  
		}

		//注意溢出
		if (ret > 2147483647 || -ret > 2147483647) 
			return 0;
		return sign ? ret: -ret;
	}
};

int main()
{
	Solution sol;
	// cout << sol.reverse(-1234);
	cout << sol.reverse(-2147483648);
	return 0;
}


