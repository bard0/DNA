#include <iostream>
#include <string >
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>
using namespace std;

int table(char s) {
	if (s == 'G')
	{
		return  57;
	}
	if (s == 'A')
	{
		return  71;
	}
	if (s == 'S')
	{
		return  87;
	}
	if (s == 'P')
	{
		return  97;
	}
	if (s == 'V')
	{
		return  99;
	}
	if (s == 'T')
	{
		return 101;
	}
	if (s == 'C')
	{
		return 103;
	}
	if (s == 'I')
	{
		return 113;
	}
	if (s == 'L')
	{
		return 113;
	}
	if (s == 'N')
	{
		return 114;
	}
	if (s == 'D')
	{
		return 115;
	}
	if (s == 'Q')
	{
		return 128;
	}
	if (s == 'K')
	{
		return 128;
	}
	if (s == 'E')
	{
		return 129;
	}
	if (s == 'M')
	{
		return 131;
	} if (s == 'H')
	{
		return 137;
	}
	if (s == 'F')
	{
		return 147;
	}
	if (s == 'R')
	{
		return 156;
	}
	if (s == 'Y')
	{
		return 163;
	}
	if (s == 'W')
	{
		return 186;
	}
}

int main() {
	string s, s1;
	vector <char> v;
	vector <int> res;
	cin >> s;
	s1 = s + s;
	//for (int i = 0; i < s.length(); i++) {
	//	v.push_back(s[i]);
	//}
	res.push_back(0);
	//for (int i = 0; i < s.length(); i++) {
	//	res.push_back(table(s[i]));
	//}

	for (int i = 0; i < s.length(); i++)
	{
		int tmp = 0;
		for (int j = 0; j < s.length()-1 ; j++) {
			int n = i + j;
			tmp += table(s1[n]);
			res.push_back(tmp);
		}
	}
	int tmp = 0;
	for (int i = 0; i < s.length(); i++) {
		tmp += table(s[i]);
	}
	res.push_back(tmp);
	sort(res.begin(), res.end());
	for (int i = 0; i < res.size(); i++) {
		cout << res[i]<< " ";
	}
	return 0;

}

