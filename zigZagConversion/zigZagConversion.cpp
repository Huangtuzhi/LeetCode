#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		if (s.size() == 0)
			return "";
		if (s.size() == 1 || numRows == 1)
			return s;

		int zag_num = 2 * (numRows - 1);
		int bags = s.size() / (2 * (numRows - 1));
		int other = s.size() % (2 * (numRows - 1));
		vector<vector<char> > mem;

		for(int i=0; i<bags; i++) { //i  bag
			vector<char> row;
			for(int j=zag_num*i; j<numRows+zag_num*i; j++) {
				row.push_back(s[j]);
			}
			mem.push_back(row);
			
			int diff;
			for(int j=numRows+zag_num*i, diff = 0; j<zag_num+zag_num*i; j++) {
				vector<char> row1;				
				for(int k=0; k<numRows-2-diff; k++) {
					row1.push_back('#');
				}	
				row1.push_back(s[j]);
				for(int k=0; k<1+diff; k++) {
					row1.push_back('#');
				}
				diff++;
				mem.push_back(row1);					
			}
		}

		if(other <= numRows) {
			vector<char> row;
			for(int i=0; i<other; i++) {
				row.push_back(s[bags*zag_num+i]);
			}
			for(int i=0; i<numRows-other; i++)
				row.push_back('#');
			mem.push_back(row);
		} 
		else {
		    vector<char> row;
			for(int i=0; i<numRows; i++) {
				row.push_back(s[bags*zag_num+i]);
			}
			mem.push_back(row);

			int diff;
			for(int j=zag_num*bags+numRows, diff = 0; j<s.size(); j++) {
				vector<char> row1;				
				for(int k=0; k<numRows-2-diff; k++) {
					row1.push_back('#');
				}	
				row1.push_back(s[j]);
				for(int k=0; k<1+diff; k++) {
					row1.push_back('#');
				}
				diff++;
				mem.push_back(row1);					
			}
		}

		int column = other > numRows ? bags*(numRows-1)+1+other%numRows: bags*(numRows-1)+1;
		return vector2String(mem, column, numRows);
	}

	string vector2String(vector<vector<char> > arr, int column, int row) {
		string ret;
		for(int j=0; j<row;j++) {
			for(int i=0; i<column; i++) {
				//注意char 转 string的问题
				if (arr[i][j] != '#') {
				    string str;
					stringstream stream;
					stream << arr[i][j];
					str = stream.str();
					ret += str;
				}
			}
		}
		return ret;
	}
};

int main()
{
	Solution sol;
	string s("abcdefghijklmnopQRSTUVWX");
	string s1("abcdefghijklmnopQRSTUVWXPXCABCDEF");
	string s2("PAYPALISHIRING");
	string s3("A");
	cout << sol.convert(s3, 1);
	return 0;
}