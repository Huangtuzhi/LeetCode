#include <iostream>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		if (s.size() == 0)
			return "";
		if (s.size() == 1)
			return s;

		//基数回文串
		int longest = 1;
	 	int index; //基点位置
		for(int pos=0; pos<s.size(); pos++) {
			int half = 1;//基点左边的数目

			while(pos >= half) {
				if (s[pos+half] == s[pos-half]) {
					if (2*half + 1 > longest) {
						longest = 2*half + 1;
						index = pos;
					}
					half++;
				}
				else
					break;
			}
		}

		int start = index - (longest - 1) / 2;

		//偶数回文串
		int longest_odd = 1;
		int index_odd;
		for(int pos=0; pos<s.size(); pos++) {
			int half = 1;//基点左边的数目

			while(pos >= half) {
				if (s[pos+half-1] == s[pos-half]) {
					if (2*half > longest_odd) {
						longest_odd = 2*half;
						index_odd = pos;
					}
					half++;
				}
				else
					break;
			}
		}
	    int start_odd = index_odd - longest_odd / 2;

		if (longest >= longest_odd)
			return s.substr(start, longest);
		else
			return s.substr(start_odd, longest_odd);
	}
};

int main()
{
	Solution sol;
	string s("aefghgfebpoij");
	string s1("aea");
	string s2("aef");
	string s3("");
	string s4("abba");
	string s5("a");
	cout << sol.longestPalindrome(s2) << endl;
	return 0;
}


