#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
unsigned countDif(string & first, string & second)
{
	unsigned res = 0;;
	for (int i = 0; i < first.size(); i++)
	{
		if (first[i] != second[i]) { res++; }
	}
	return res;
}

int main()
{
	unsigned k, d;
	vector<string> dna;
	cin >> k;
	cin >> d;
	string tmpE;
	while (cin >> tmpE) { dna.push_back(tmpE); }

	vector< vector<string> > kMotif;
	for (int i = 0; i < dna.size(); i++)
	{
		vector<string> tmpKMotifs;
		for (int j = 0; j < dna[i].size() - k + 1; j++)
		{
			string k_motif = dna[i].substr(j, k);
			tmpKMotifs.push_back(k_motif);
		}
		kMotif.push_back(tmpKMotifs);
	}

	vector< string > KMotifs;
	string symbols = "ACTG";
	const unsigned countW = pow(symbols.size(), k);
	string word = "";
	for (unsigned i = 0; i < k; i++) { word += "A"; }

	for (unsigned i = 0; i < countW; i++)
	{
		unsigned accum = i;
		for (int j = word.size() - 1; j >= 0; j--)
		{
			word[j] = symbols[accum % symbols.size()];
			accum /= symbols.size();
		}
		KMotifs.push_back(word);
	}

	vector<string> res;
	for (int index = 0; index < KMotifs.size(); index++)
	{
		unsigned count_d_diff = 0;
		for (int i = 0; i < kMotif.size(); i++)
		{
			bool f = false;
			for (int j = 0; j < kMotif[i].size(); j++)
			{
				if (countDif(KMotifs[index], kMotif[i][j]) <= d)
				{
					f = true;
					break;
				}
			}
			if (f) { count_d_diff++; }
			else { break; }
		}
		if (count_d_diff == kMotif.size()) { res.push_back(KMotifs[index]); }
	}

	sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end());

	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << ' ';
	}
	return 0;
}