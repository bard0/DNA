#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

const int MASS[] = { 57, 71, 87, 97, 99, 101, 103, 113, 114, 115, 128, 129, 131, 137, 147, 156, 163, 186 };
const string TS = "G 057 A 071 S 087 P 097 V 099 T 101 C 103 I 113 L 113 N 114 D 115 K 128 Q 128 E 129 M 131 H 137 F 147 R 156 Y 163 W 186";
int PepScoring(string str, string spec);
vector<int> GenTheorSpec(vector<int> ppt);


int main() {
	string str = "", spec = "";
	getline(cin, str);
	getline(cin, spec);
	cout << PepScoring(str, spec) << endl;


	return 0;
}
vector<int> GenTheorlSpec(vector<int> ppt)
{
	int sizeres = ppt.size()*(ppt.size() - 1) + 2;
	vector<int> res;
	res.resize(sizeres);
	vector<int> pt = ppt;
	pt.resize(2 * pt.size());
	bool isgreater;

	for (int i = ppt.size(); i < pt.size(); i++)
		pt[i] = pt[i - ppt.size()];

	for (int i = 0; i < sizeres; i++)
		res[i] = 0;

	for (int i = 0; i < ppt.size(); i++)
		res[1] += pt[i];

	int j = 2, m;

	for (int i = 0; i < ppt.size(); i++)
		for (int k = 1; k < ppt.size(); k++)
		{
			m = k;
			while (m > 0)
			{
				res[j] += pt[i + m - 1];
				m--;
			}
			j++;
		}
	sort(res.rbegin(), res.rend());

	return res;
}
int PepScoring(string str, string spec)
{
	int sizeres = str.length()*(str.length() - 1) + 2;
	int *res = new int[sizeres];
	string str2 = str + str;

	for (int i = 0; i < sizeres; i++)
		res[i] = 0;

	for (int i = 0; i < str.length(); i++)
		res[1] += stoi(TS.substr(TS.find(str[i]) + 2, 3));

	int j = 2, m;

	for (int i = 0; i < str.length(); i++)
		for (int k = 1; k < str.length(); k++)
		{
			m = k;
			while (m > 0)
			{
				res[j] += stoi(TS.substr(TS.find(str2[i + m - 1]) + 2, 3));
				m--;
			}
			j++;
		}
	sort(res, res + sizeres);

	spec += ' ';
	int n = count(spec.begin(), spec.end(), ' ');
	int * a = new int[n];

	for (int i = 0; i < n; i++) {
		a[i] = stoi(spec.substr(0, spec.find(' ')));
		spec.erase(0, spec.find(' ') + 1);
	}

	int score = 0;
	j = 0;

	for (int i = 0; i < sizeres; i++) {
		while ((j < n) && (res[i] > a[j]))
			j++;
		if ((j < n) && (res[i] == a[j]))
		{
			score++;
			j++;
		}
	}

	return score;
}
