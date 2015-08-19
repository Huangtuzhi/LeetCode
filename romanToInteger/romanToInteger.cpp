#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
    	if (s.length() == 0)
    		return 0;

    	map<char, int> convertMap;
    	convertMap['I'] = 1;
    	convertMap['V'] = 5;
    	convertMap['X'] = 10;
    	convertMap['L'] = 50;
    	convertMap['C'] = 100;
    	convertMap['D'] = 500;
    	convertMap['M'] = 1000;

    	int len = s.length();
    	int result = convertMap[s[len-1]];
    	for (int i=len-2; i>=0; i--)
    	{
    		if (convertMap[s[i+1]] <= convertMap[s[i]])
    			result += convertMap[s[i]];
    		else 
    			result -= convertMap[s[i]];
    	}

    	return result;
    }
};

int main()
{
	Solution sol;
	string case1 = "MCMLXXXIV";
	cout << sol.romanToInt(case1) << endl;
	return 0;
}
