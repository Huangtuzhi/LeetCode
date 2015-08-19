#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
    	int length = 0;
    	if (strs.size() == 0)
    		return "";
    	if (strs.size() == 1)
    		return strs[0];

    	for(int j=0; j<strs[0].size(); j++)
    	{
    		for(int i=1; i<strs.size(); i++)
   		{
   		    if (strs[0][j] != strs[i][j])
   			return strs[0].substr(0, length);
   		}
   		length++;
   	}
   	
   	return strs[0].substr(0, length);
    }
};

int main()
{
	Solution sol;
	vector<string> stringVec;
	stringVec.push_back("abce");
	stringVec.push_back("abcd");
	stringVec.push_back("abce");

	cout << sol.longestCommonPrefix(stringVec) << endl;
}
