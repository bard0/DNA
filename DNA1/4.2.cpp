#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>
#include <set>
using namespace std;
vector <string> create(int k);
void medianString(int n, vector<string> dna);
int d(vector<string>, string pattern);

int main() {
	int n = 5;
	cin >> n;
	vector <string> dna, dn1;
	string tmp;
	/*dna.push_back("GAAACTACGCACGTAGTGTTTTGCTACGGTTCTCA");
	dna.push_back("TATATCCACATGACCTCGACAACGCACGGTCGAAT");
	dna.push_back("TAGCGGGACAATCAGGTCTGAGTCGACTGTTGTGC");
	dna.push_back("TCCTGCCGGTTGCTAACTGTAGACGTTTACCCCTT");
	dna.push_back("TCCCTCCCTAACTCTAGGCTACTGTCGTCCGCAGT");
	dna.push_back("AGGCAGAAAGACAACGGTAGTAATCTAGAGACCGT");
	dna.push_back("CGCTCCACGCAGCTCATAGAACCGTGTTGTTCAAC");
	dna.push_back("ACTGTCTCCCGGAAACCATAAACTACTTGGTTTGT");
	dna.push_back("GGTTTTCTTGACTGTAATTACAATCCAGGAGACCA");
	dna.push_back("ATGTCGCTCTACAGTGAACACGTAACTGTCTTCGG");*/
	/*dn1.push_back("TTACCTTAAC");
	dn1.push_back("GATATCTGTC");
	dn1.push_back("ACGGCGTTCG");
	dn1.push_back("CCCTAAAGAG");
	dn1.push_back("CGTCAGAGGT");
	string s = "AAA";
	int a = d(dn1, s);*/
	while (cin >> tmp) {
		dna.push_back(tmp);
	}

	medianString(n, dna);
	return 0;
}

vector <string> create(int k) {
	string s = "ACTG";
	vector <string> creature, tmp;
	tmp.push_back("A");
	tmp.push_back("C");
	tmp.push_back("T");
	tmp.push_back("G");
	for (int k1 = 0; k1 < k - 1; k1++) {
		for (int i = 0; i < s.length(); i++) {
			for (int j = 0; j < tmp.size(); j++) {
				creature.push_back(tmp[j] + s[i]);
			}
		}
		if (k1 < k - 2) {
			tmp.clear();
			tmp = creature;
			creature.clear();
		}
		else return creature;
	}
}

int d(vector<string> dna, string pattern) {
	vector <string> tmpQ;
	int res = 0;
	int min = 0;
	for (int i = 0; i < dna.size(); i++) {
		tmpQ.clear();
		for (int j = 0; j < (dna[i].length() - pattern.length() + 1); j++) {
			tmpQ.push_back(dna[i].substr(j, pattern.length()));
		}
		min = pattern.length();
		for (int j = 0; j < tmpQ.size(); j++) {
			int diff = 0;
			for (int k = 0; k < tmpQ[j].length(); k++) {
				if ((pattern[k]) != tmpQ[j][k]){
				diff++;
				}
			}
			if (diff < min) {
				min = diff;
			}
		}
		res += min;
	}
	return res;
}

void medianString(int n, vector<string> dna) {
	vector <string> cr = create(n);
	int distance = dna[0].length();
	string median;
	for (int i = 0; i < cr.size(); i++) {
		if (distance > d(dna, cr[i])) {
			distance = d(dna, cr[i]);
			median = cr[i];
		}
	}
	for (int i = 0; i < median.length(); i++) {
		cout << median[i];
	}
}

