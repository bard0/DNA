#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

uint64_t peptide_spectrum(string peptide);
uint64_t amino_acid_table(string amino_acid);

int main()
{
	string amino_acid, double_amino_acid;
	cin >> amino_acid;
	double_amino_acid = amino_acid + amino_acid;
	vector<uint64_t> cyclospectrum;

	cyclospectrum.push_back(0);
	for (size_t size = 1; size < amino_acid.size(); size++)
	{
		for (size_t i = 0; i < amino_acid.size(); i++)
		{
			cyclospectrum.push_back(peptide_spectrum(double_amino_acid.substr(i, size)));
		}
	}
	cyclospectrum.push_back(peptide_spectrum(amino_acid));

	sort(cyclospectrum.begin(), cyclospectrum.end());
	for (size_t i = 0; i < cyclospectrum.size(); i++)
	{
		cout << cyclospectrum[i] << " ";
	}
	cout << endl;
	return 0;
}

uint64_t peptide_spectrum(string peptide)
{
	uint64_t result_peptide_spectrum = 0;
	for (size_t i = 0; i < peptide.size(); i++)
	{
		string elem = "";
		elem += peptide[i];
		result_peptide_spectrum += amino_acid_table(elem);
	}
	return result_peptide_spectrum;
}

uint64_t amino_acid_table(string amino_acid)
{
	if (amino_acid == string("G")) { return  57; }
	if (amino_acid == string("A")) { return  71; }
	if (amino_acid == string("S")) { return  87; }
	if (amino_acid == string("P")) { return  97; }
	if (amino_acid == string("V")) { return  99; }
	if (amino_acid == string("T")) { return 101; }
	if (amino_acid == string("C")) { return 103; }
	if (amino_acid == string("I")) { return 113; }
	if (amino_acid == string("L")) { return 113; }
	if (amino_acid == string("N")) { return 114; }
	if (amino_acid == string("D")) { return 115; }
	if (amino_acid == string("K")) { return 128; }
	if (amino_acid == string("Q")) { return 128; }
	if (amino_acid == string("E")) { return 129; }
	if (amino_acid == string("M")) { return 131; }
	if (amino_acid == string("H")) { return 137; }
	if (amino_acid == string("F")) { return 147; }
	if (amino_acid == string("R")) { return 156; }
	if (amino_acid == string("Y")) { return 163; }
	if (amino_acid == string("W")) { return 186; }
	return 0;
}