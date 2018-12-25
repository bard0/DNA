#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>
using namespace std;

int aminoT(string amino)
{
	if (amino == string("G")) 
	{ return  57; } 
	if (amino == string("A")) 
	{ return  71; }
	if (amino == string("S")) 
	{ return  87; } 
	if (amino == string("P")) 
	{ return  97; }
	if (amino == string("V")) 
	{ return  99; } 
	if (amino == string("T")) 
	{ return 101; }
	if (amino == string("C"))
	{ return 103; } 
	if (amino == string("L")) 
	{ return 113; }
	if (amino == string("N")) 
	{ return 114; } 
	if (amino == string("D"))
	{ return 115; }
	if (amino == string("Q")) 
	{ return 128; } 
	if (amino == string("E")) 
	{ return 129; }
	if (amino == string("M")) 
	{ return 131; } if (amino == string("H"))
	{ return 137; }
	if (amino == string("F")) 
	{ return 147; } 
	if (amino == string("R"))
	{ return 156; }
	if (amino == string("Y"))
	{ return 163; } 
	if (amino == string("W")) 
	{ return 186; }

}
string revAminoT(int amino)
{
	if (amino == 57) 
	{ return string("G"); } 
	if (amino == 71) 
	{ return string("A"); }
	if (amino == 87) 
	{ return string("S"); } 
	if (amino == 97) 
	{ return string("P"); }
	if (amino == 99) 
	{ return string("V"); } 
	if (amino == 101) 
	{ return string("T"); }
	if (amino == 103) 
	{ return string("C"); }
	if (amino == 113) 
	{ return string("L"); }
	if (amino == 114) 
	{ return string("N"); } 
	if (amino == 115) 
	{ return string("D"); }
	if (amino == 128) 
	{ return string("Q"); } 
	if (amino == 129) 
	{ return string("E"); }
	if (amino == 131) 
	{ return string("M"); } 
	if (amino == 137) 
	{ return string("H"); }
	if (amino == 147) 
	{ return string("F"); } 
	if (amino == 156) 
	{ return string("R"); }
	if (amino == 163) 
	{ return string("Y"); } 
	if (amino == 186) 
	{ return string("W"); }
}
vector<string> expand(vector<string> peps);

vector<string> clean(vector<string> peps)
{
	vector<string> nPeps;
	for (int i = 0; i < peps.size(); i++)
	{
		if (peps[i] == "0") { continue; }
		for (int j = i + 1; j < peps.size(); j++)
		{
			string testPattern = peps[i] + peps[i];
			if (testPattern.find(peps[j]) != string::npos)
			{
				peps[j] = "0";
			}
		}
	}
	for (int i = 0; i < peps.size(); i++)
	{
		if (peps[i] != "0") { nPeps.push_back(peps[i]); }
	}
	return nPeps;
}


int mass(string pep)
{
	int result = 0;
	for (int i = 0; i < pep.size(); i++) { result += aminoT(pep.substr(i, 1)); }
	return result;
}


bool consistent(string pep, vector<int> spectrum)
{
	bool flag_result = true;
	vector<int> local_spectrum(spectrum);
	for (int i = 0; i < pep.size(); i++)
	{
		auto iter = find(local_spectrum.begin(), local_spectrum.end(), aminoT(pep.substr(i, 1)));
		if (iter != local_spectrum.end()) { local_spectrum.erase(iter); }
		else { flag_result = false; break; }
	}
	return flag_result;
}



bool cyclospectrum(string pep, vector<int> spectrum)
{

	string accum_peptide = "";
	for (int i = 0; i < pep.size(); i++)
	{
		accum_peptide += pep[i];
		auto iter = find(spectrum.begin(), spectrum.end(), mass(accum_peptide));
		if (iter == spectrum.end()) { return false; }
	}
	return true;
}





vector<int> amino = { 57,  71,  87,  97,  99, 101, 103,
									 113, 114, 115, 128, 129, 131, 137,
									 147, 156, 163, 186 };
int main()
{
	vector<int> spectrum;
	int tmpEl;
	while (cin >> tmpEl) { spectrum.push_back(tmpEl); }
	int psrMas = *max_element(spectrum.begin(), spectrum.end());

	vector<int> uniqSpec = spectrum;
	sort(uniqSpec.begin(), uniqSpec.end());
	uniqSpec.erase(unique(uniqSpec.begin(), uniqSpec.end()), uniqSpec.end());

	vector<string> peps;
	for (int i = 0; i < uniqSpec.size(); i++)
	{
		if (find(amino.begin(), amino.end(), uniqSpec[i]) != amino.end())
		{
			peps.push_back(revAminoT(uniqSpec[i]));
		}
	}

	vector<string> result;
	while (peps.size() != 0)
	{
		peps = expand(peps);
		vector<string> currPeps;
		for (int i = 0; i < peps.size(); i++)
		{
			if (consistent(peps[i], spectrum) && cyclospectrum(peps[i], spectrum))
			{
				if (mass(peps[i]) == psrMas) { result.push_back(peps[i]); }
				else
					if (mass(peps[i]) < psrMas) { currPeps.push_back(peps[i]); }
			}
		}
		peps = currPeps;
	}

	/*for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << '\n';
	}*/

	for (int i = 0; i < result.size(); i++)
	{
		cout << aminoT(result[i].substr(0, 1));
		for (int j = 1; j < result[i].size(); j++)
		{
			cout << "-" << aminoT(result[i].substr(j, 1));
		}
		cout << " ";
	}
	cout << '\n';

	//cout << "count = " << result.size() << '\n';
	return 0;
}

vector<string> expand(vector<string> peps)
{
	vector<string> nPeps;
	for (int i = 0; i < peps.size(); i++)
	{
		for (int j = 0; j < amino.size(); j++)
		{
			nPeps.push_back(peps[i] + revAminoT(amino[j]));
		}
	}
	return nPeps;
}
