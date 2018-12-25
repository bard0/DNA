#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
using namespace std;

unsigned hamDis(string & first, string & second)
{
	unsigned result = 0;;
	for (int i = 0; i < first.size(); i++)
	{
		if (first[i] != second[i]) { result++; }
	}
	return result;
}

unsigned distance(string pattern, vector< vector<string> > MotifsK)
{
	unsigned result = 0;
	for (int i = 0; i < MotifsK.size(); i++)
	{
		vector<unsigned> listHumm;
		for (int j = 0; j < MotifsK[i].size(); j++)
		{
			listHumm.push_back(hamDis(MotifsK[i][j], pattern));
		}
		result += *min_element(listHumm.begin(), listHumm.end());
	}
	return result;
}
vector<string> brutforseW(unsigned length)
{
	vector< string > lPat;
	string symbols = "ACTG";
	const unsigned total_words_count = pow(symbols.size(), length);
	string word = "";
	for (unsigned i = 0; i < length; i++) { word += "A"; }
	for (unsigned i = 0; i < total_words_count; i++)
	{
		unsigned accum = i;
		for (int j = word.size() - 1; j >= 0; j--)
		{
			word[j] = symbols[accum % symbols.size()];
			accum /= symbols.size();
		}
		lPat.push_back(word);
	}
	return lPat;
}
vector< vector<string> >matrixMotif(vector<string> dna, unsigned length)
{
	vector< vector<string> > MotifsK;
	for (int i = 0; i < dna.size(); i++)
	{
		vector<string> tmpKMof;
		for (int j = 0; j < dna[i].size() - length + 1; j++)
		{
			string kMot = dna[i].substr(j, length);
			tmpKMof.push_back(kMot);
		}
		MotifsK.push_back(tmpKMof);
	}
	return MotifsK;
}

int main()
{
	unsigned k;
	vector<string> dna;
	cin >> k;
	string tmpE;
	while (cin >> tmpE) {
		dna.push_back(tmpE);
	}
	vector< vector<string> > MotifsK = matrixMotif(dna, k);
	vector<string> lPat = brutforseW(k);
	unsigned minDis = numeric_limits<unsigned>::max();
	string minPat;
	for (int i = 0; i < lPat.size(); i++)
	{
		unsigned currDis = distance(lPat[i], MotifsK);
		if (minDis > currDis)
		{
			minDis = currDis;
			minPat = lPat[i];
		}
	}
	cout << minPat;
	return 0;
}