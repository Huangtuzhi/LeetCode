#include <iostream>
#include <set>
#include <string>
#include <map>
using namespace std;

//暴力破解法
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//     	int longest = 0;
//     	if(s.size() == 0)
//     		return 0;
//     	else{
//     		auto start = s.begin();
//     		auto end = s.begin();
//     		for(start; start!=s.end(); start++)
//     		{
//     			int cnt = 0;
//     			set<char> norepeat;
//     			for(end=start; end!=s.end(); end++)
//     			{
//     				if(norepeat.insert(*end).second)
//     				{
//     					cnt++;
//     					if(end == s.end()-1 && cnt > longest)
//     					{
//     						longest = cnt;
//     						break;
//     				    }

//     				}
//     				else
//     				{
//     					if(cnt > longest)
//     						longest = cnt;
//     					break;
//     				}
//     			}
//     		}
//     	}
//     	return longest;        
//     }
// };


//HashMap法
class Solution
{
public:
	int lengthOfLongestSubstring(string s) {
		map<char, int> record;
		int longest = -1;
		int start = -1;

		if (s.size() == 0) return 0;
		for(int i=0; i<s.size(); i++)
		{
			if (record.find(s[i]) != record.end() && start < record[s[i]])
			{
				//start应该在record[s[i]]之前
				start = record[s[i]];
			}

			if (i - start > longest)
				longest = i - start;

			record[s[i]] = i;
			cout << longest << endl;
		}
		return longest;
	}
};

int main()
{
	Solution sol;
	string s("ggububgvfk");
	cout << sol.lengthOfLongestSubstring(s) << endl;
	return 0;
}
