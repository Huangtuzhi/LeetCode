#include <iostream>
using namespace std;

string set_0[] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
string set_1[] = {"X", "L", "C"};
string set_2[] = {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
string set_3[] = {"M", "MM", "MMM"};

class Solution {
public:
    string intToRoman(int num) {
    	string ret = "";
		int qianwei = num / 1000;
		int baiwei = (num - qianwei*1000) / 100;
		int shiwei = (num - qianwei*1000 - baiwei*100);

		if (qianwei)
			ret += genThunsands(qianwei);
		if (baiwei)
			ret += genHundreds(baiwei);
		if (shiwei)
			ret += genTens(shiwei);
		return ret;
    }

    string genUnit(int num);
    string genTens(int num);
    string genHundreds(int num);
    string genThunsands(int num);
};

string Solution::genUnit(int num)
{
	return set_0[num-1];
}

string Solution::genTens(int num) //拼接十位 + 个位
{
	string ret = "";
	int gewei = num % 10;
	int shiwei = num / 10;

	if (num > 0 && num < 10)
		return genUnit(num);
	
	if (num >= 10 && num <= 39)
	{
		for(int i=0; i<shiwei; i++)
		{
			ret += set_1[0];
		}
		if (gewei)
		{
			ret += genUnit(gewei);
		}			
	}
	
	if (num == 40)
		ret = "XL";

	if (num > 40 && num < 50)
	{
		ret += "XL";
		ret += genUnit(gewei);
	}

	if (num >=50 && num < 90)
	{
		ret += "L";
		int repeat_X = (num - 50) / 10;
		for (int i=0; i< repeat_X; i++)
			ret += "X";
		if (gewei)
		{
			ret += genUnit(gewei);
		}
	}

	if (num >= 90 && num <=99)
	{
		ret += "XC";
		if (gewei)
		{
			ret += genUnit(gewei);
		}		
	}

	return ret;
}

string Solution::genHundreds(int num) //拼接百位
{
	return set_2[num-1];
}

string Solution::genThunsands(int num)
{
	return set_3[num-1];
}

int main()
{
	Solution sol;
	cout << sol.intToRoman(60) << endl;
	cout << sol.intToRoman(90) << endl;
	cout << sol.intToRoman(95) << endl;
	cout << sol.intToRoman(99) << endl;

	cout << sol.intToRoman(100) << endl;
	cout << sol.intToRoman(786) << endl;
	cout << sol.intToRoman(1666) << endl;
	cout << sol.intToRoman(1984) << endl;

	return 0;
}