#include <iostream>
#include <string>
#include <stack>
using namespace std;
#include <vector>

/*int main() {
	string s1, s2, s3, s4, s5, buff;
	cin >> s1 >> s2;
	vector<string> mas = { "AAA", "K", "AAC", "N", "AAG", "K", "AAU", "N", "ACA", "T", "ACC", "T", "ACG", "T", "ACU", "T", "AGA", "R", "AGC", "S", "AGG", "R","AGU", "S","AUA", "I","AUC", "I","AUG", "M","AUU", "I","CAA", "Q",
"CAC", "H","CAG", "Q","CAU", "H","CCA", "P","CCC", "P","CCG", "P","CCU", "P","CGA", "R","CGC", "R","CGG", "R","CGU", "R","CUA", "L","CUC", "L","CUG", "L","CUU", "L","GAA", "E","GAC", "D","GAG", "E",
"GAU", "D","GCA", "A","GCC", "A","GCG", "A","GCU", "A","GGA", "G","GGC", "G","GGG", "G","GGU", "G","GUA", "V","GUC", "V","GUG","V","GUU", "V","UAA", "*","UAC", "Y","UAG", "*","UAU", "Y","UCA", "S",
"UCC", "S","UCG", "S","UCU", "S","UGA", "*","UGC","C","UGG", "W","UGU","C","UUA", "L","UUC", "F","UUG", "L","UUU", "F" };
	vector<string> mas2;
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] == 'T') {
			s1[i] = 'U';
		}
	}
	for (int i = 0; i < s2.length(); i++) {
		for (int j = 1; j < mas.size(); j = j + 2) {
			buff = s2[i];
			if (buff == mas[j]) {
				mas2.emplace_back(mas[j - 1]);
			}
		}
	}
	for (int i = 0; i < (s1.length() - (s2.length() * 3)); i++) {
		s3.clear();
		for (int k = i; k < (s2.length()*3); k++) {
			s3 = s3 + s1[k];
		}


		/*for (int j = 0; j < s3.length(); j=j+3) {
			buff.clear();
			int w = j+3;
			int k = 0;
			while (k < 3) {
				buff = buff + s2[w];
				w++;
				k++;
			}
			for (int j1 = 0; j1<mas2.size(); j1++){
				if (buff == mas2[j1]) {
					int y = 1;
					int x = i + 3;
					int z = j;
					while (y < mas2.size()) {
						if (s3 == mas2[z]) {

						}
					}
				}*/
	//	}
	//
		//			
		//			system ("pause");
	//return 0;
//}


string reverse_complement_problem(string dna);
string dna_to_rna(string dna);
string rna_to_dna(string rna);
string rna_codon_table(string codon);
string protein_translation_problem(string rna);

int main(int argc, char** argv)
{
	string dna, amino_acid_string, rna, revers_rna;
	cin >> dna;
	cin >> amino_acid_string;

	rna = dna_to_rna(dna);
	revers_rna = dna_to_rna(reverse_complement_problem(dna));

	for (size_t i = 0; i < rna.size() - (amino_acid_string.size() * 3) + 1; i++)
	{
		string pattern = rna.substr(i, amino_acid_string.size() * 3);
		if (amino_acid_string.compare(protein_translation_problem(pattern)) == 0)
		{
			cout << rna_to_dna(pattern) << endl;
		}
	}

	for (size_t i = 0; i < revers_rna.size() - (amino_acid_string.size() * 3) + 1; i++)
	{
		string pattern = revers_rna.substr(i, amino_acid_string.size() * 3);
		if (amino_acid_string.compare(protein_translation_problem(pattern)) == 0)
		{
			cout << reverse_complement_problem(rna_to_dna(pattern)) << endl;
		}
	}

	return 0;
}

string reverse_complement_problem(string dna)
{
	vector<uint8_t> dna_uint8(dna.begin(), dna.end());
	string reverse_dna = "";
	for (size_t i = 0; i < dna_uint8.size(); i++)
	{
		if (dna_uint8[i] == 65 /* A == 65 */) { reverse_dna = "T" + reverse_dna; }
		if (dna_uint8[i] == 84 /* T == 84 */) { reverse_dna = "A" + reverse_dna; }
		if (dna_uint8[i] == 71 /* G == 71 */) { reverse_dna = "C" + reverse_dna; }
		if (dna_uint8[i] == 67 /* C == 71 */) { reverse_dna = "G" + reverse_dna; }
	}
	return reverse_dna;
}

string dna_to_rna(string dna)
{
	vector<uint8_t> dna_uint8(dna.begin(), dna.end());
	string rna = "";
	for (size_t i = 0; i < dna_uint8.size(); i++)
	{
		if (dna_uint8[i] == 84 /* T == 84 */) { rna += "U"; }
		else { rna += dna_uint8[i]; }
	}
	return rna;
}

string rna_to_dna(string rna)
{
	vector<uint8_t> rna_uint8(rna.begin(), rna.end());
	string dna = "";
	for (size_t i = 0; i < rna_uint8.size(); i++)
	{
		if (rna_uint8[i] == 85 /* U == 85 */) { dna += "T"; }
		else { dna += rna_uint8[i]; }
	}
	return dna;
}

string protein_translation_problem(string rna)
{
	string codon, amino_acid_string = "";

	for (size_t i = 0; i < rna.size(); i++)
	{
		codon += rna[i];
		if (i % 3 == 2)
		{
			amino_acid_string += rna_codon_table(codon);
			codon = "";
		}
	}
	return amino_acid_string;
}

string rna_codon_table(string codon)
{
	string amino_acid = "";
	if (codon == "AAA") { amino_acid += "K"; } if (codon == "AAC") { amino_acid += "N"; }
	if (codon == "AAG") { amino_acid += "K"; } if (codon == "AAU") { amino_acid += "N"; }
	if (codon == "ACA") { amino_acid += "T"; } if (codon == "ACC") { amino_acid += "T"; }
	if (codon == "ACG") { amino_acid += "T"; } if (codon == "ACU") { amino_acid += "T"; }
	if (codon == "AGA") { amino_acid += "R"; } if (codon == "AGC") { amino_acid += "S"; }
	if (codon == "AGG") { amino_acid += "R"; } if (codon == "AGU") { amino_acid += "S"; }
	if (codon == "AUA") { amino_acid += "I"; } if (codon == "AUC") { amino_acid += "I"; }
	if (codon == "AUG") { amino_acid += "M"; } if (codon == "AUU") { amino_acid += "I"; }
	if (codon == "CAA") { amino_acid += "Q"; } if (codon == "CAC") { amino_acid += "H"; }
	if (codon == "CAG") { amino_acid += "Q"; } if (codon == "CAU") { amino_acid += "H"; }
	if (codon == "CCA") { amino_acid += "P"; } if (codon == "CCC") { amino_acid += "P"; }
	if (codon == "CCG") { amino_acid += "P"; } if (codon == "CCU") { amino_acid += "P"; }
	if (codon == "CGA") { amino_acid += "R"; } if (codon == "CGC") { amino_acid += "R"; }
	if (codon == "CGG") { amino_acid += "R"; } if (codon == "CGU") { amino_acid += "R"; }
	if (codon == "CUA") { amino_acid += "L"; } if (codon == "CUC") { amino_acid += "L"; }
	if (codon == "CUG") { amino_acid += "L"; } if (codon == "CUU") { amino_acid += "L"; }
	if (codon == "GAA") { amino_acid += "E"; } if (codon == "GAC") { amino_acid += "D"; }
	if (codon == "GAG") { amino_acid += "E"; } if (codon == "GAU") { amino_acid += "D"; }
	if (codon == "GCA") { amino_acid += "A"; } if (codon == "GCC") { amino_acid += "A"; }
	if (codon == "GCG") { amino_acid += "A"; } if (codon == "GCU") { amino_acid += "A"; }
	if (codon == "GGA") { amino_acid += "G"; } if (codon == "GGC") { amino_acid += "G"; }
	if (codon == "GGG") { amino_acid += "G"; } if (codon == "GGU") { amino_acid += "G"; }
	if (codon == "GUA") { amino_acid += "V"; } if (codon == "GUC") { amino_acid += "V"; }
	if (codon == "GUG") { amino_acid += "V"; } if (codon == "GUU") { amino_acid += "V"; }
	if (codon == "UAA") { amino_acid += ""; } if (codon == "UAC") { amino_acid += "Y"; }
	if (codon == "UAG") { amino_acid += ""; } if (codon == "UAU") { amino_acid += "Y"; }
	if (codon == "UCA") { amino_acid += "S"; } if (codon == "UCC") { amino_acid += "S"; }
	if (codon == "UCG") { amino_acid += "S"; } if (codon == "UCU") { amino_acid += "S"; }
	if (codon == "UGA") { amino_acid += ""; } if (codon == "UGC") { amino_acid += "C"; }
	if (codon == "UGG") { amino_acid += "W"; } if (codon == "UGU") { amino_acid += "C"; }
	if (codon == "UUA") { amino_acid += "L"; } if (codon == "UUC") { amino_acid += "F"; }
	if (codon == "UUG") { amino_acid += "L"; } if (codon == "UUU") { amino_acid += "F"; }
	return amino_acid;
}