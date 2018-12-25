#include <string>
#include <vector>
#include <iterator>
#include <iostream>

using namespace std;

int mass[18] = { 57, 71, 87, 97, 99, 101, 103, 113, 114, 115, 128, 129, 131, 137, 147, 156, 163, 186 };

bool ismass(int a)
{
	bool f = false;
	for (int i = 0; i < 18; i++)
		if (a == mass[i])
		{
			f = true;
			break;
		}
	return f;
}

string sum(string s)
{
	string tmp, res = "";
	int a, sum = 0;
	for (int i = 0; i < s.length(); i++)
	{
		while (s[i] != '-' && i < s.length())
		{
			tmp += s[i];
			i++;
		}
		a = atoi(tmp.c_str());
		sum += a;
		tmp = "";
	}
	res += to_string(sum);
	return res;
}

bool isin(vector<string> v, string s)
{
	bool f = false;
	for (int i = 0; i < v.size(); i++)
	{
		if (s == v[i])
			f = true;
	}
	return f;
}

string drop(string pep)
{
	int size = pep.length();
	string tmp, res = "";
	vector<int> v;
	v.push_back(0);
	for (int i = 0; i < size; i++)
	{
		while ((pep[i] != '-') && (i < size))
		{
			tmp += pep[i];
			i++;
		}
		v.push_back(atoi(tmp.c_str()));
		tmp = "";
	}
	int j = 2, s1 = v.size(); int i; int cnt;
	int sum = 0; int n = 1;
	while (j < s1)
	{
		i = n;
		cnt = 0;
		while (cnt != j)
		{
			sum += v[i];
			i++;
			cnt++;
		}
		v.push_back(sum);
		sum = 0;
		if (n < s1 - j)
			n++;
		else
		{
			n = 1;
			j++;
		}
	}
	for (int k = 0; k < v.size(); k++)
		res += to_string(v[k]) + "-";
	res.pop_back();
	return res;
}

bool iscons(string spectrum, string s)
{
	bool f = false;
	string tmp;
	int count_a = 0, count_a1 = 0;
	vector<int> a, a1;
	string ss = "";
	ss = drop(s);
	for (int i = 0; i < spectrum.length(); i++)
	{
		while ((spectrum[i] != ' ') && (i < spectrum.length()))
		{
			tmp += spectrum[i];
			i++;
		}
		a.push_back(atoi(tmp.c_str()));
		tmp = "";
	}
	for (int i = 0; i < ss.length(); i++)
	{
		while ((ss[i] != '-') && (i < ss.length()))
		{
			tmp += ss[i];
			i++;
		}
		a1.push_back(atoi(tmp.c_str()));
		tmp = "";
	}
	for (int i = 0; i < a1.size(); i++)
	{
		f = false;
		vector<int> ::iterator iter = a.begin();
		for (int j = 0; j < a.size(); j++)
		{
			if (a[j] == a1[i])
			{
				f = true;
				a.erase(iter += j);
				break;
			}
		}
		if (!f)
			break;
		if (i == a1.size())
			return true;
	}
	return f;
}

vector<string> expand(vector<string> v, vector<string> v1, string s)
{
	vector<string> res;
	int size = v.size();
	int max = size * size;
	int t = size;
	for (int i = 0; t < max; i++)
	{
		if (i == size)
		{
			i = 0;
		}
		v.push_back(v[i]);
		t++;
	}
	int k = 0;
	int gran = v1.size();
	for (int i = 0; k < v.size(); i++)
	{
		if (i == v1.size())
			i = 0;
		while ((k < gran) && (k < v.size()))
		{
			v[k] += "-" + v1[i];
			if ((s.find(sum(v[k])) != -1) && (iscons(s, v[k])) && (!isin(res, v[k])) && (s.find(sum(v[k])) != -1))
			{
				res.push_back(v[k]);
			}
			k++;
		}
		gran += size;
	}
	return res;
}

vector<string> seq(string spectrum)
{
	int size = spectrum.length();
	string tmp;
	int a = 0, t;
	vector <string> v;
	for (int i = 0; i < size; i++)
	{
		t = i;
		while (spectrum[i] != ' ' && i < size)
		{
			tmp += spectrum[i];
			i++;
		}
		a = atoi(tmp.c_str());
		if (ismass(a))
		{
			v.push_back(tmp);
			t = i;
		}
		else
			t = i;
		tmp = "";
		i = t;
	}
	vector<string> v1;
	for (int l = 0; l < v.size(); l++)
		v1.push_back(v[l]);
	while (sum(v[0]) != to_string(a) && v.size() != 0)
	{
		v = expand(v, v1, spectrum);
		if (v.size() == 0)
			break;
	}
	return v;
}
int main()
{
	string spectrum;
	vector<string> v;
	getline(cin, spectrum);
	v = seq(spectrum);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	return 0;
}
