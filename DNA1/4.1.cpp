#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>
#include <set>
using namespace std;
vector <string> find(string s, vector <string> c, int d);
void motEn(vector <string> dna, int k, int d);
int main()
{
	vector <string> dna;
	int k = 4;
	int d = 1;
	dna.push_back("CACTGATCGACTTATC");
	dna.push_back("CTCCGACTTACCCCAC");
	dna.push_back("GTCTATCCCTGATGGC");
	dna.push_back("CAGGGTTGTCTTGTCT");
	dna.clear();
	cin >> k;
	cin >> d;
	string tmp;
	while (cin >> tmp) { 
		dna.push_back(tmp); 
	}
	motEn(dna, k, d);
	return 0;
}

vector <string> find(string s, vector <string> c, int d) {
	/*bool f = false;
	string s1;
	for (int i = 0; i < dna.size(); i++) {
		s1 = dna[i];
		for (int k = 0; k < s1.length(); k++){
			for (int j = 0; j < s.length(), j++) {
				if (s[j] != s1[k]) {
					f = false;
					break;
				}
				else f = true;
			}
			if (f) break;
		}
	}
	return f;*/
	vector <string> res;
	res.push_back(s);
	for (int i = 0; i < c.size(); i++) {
		int err = 0;
		for (int j = 0; j < c[i].length(); j++) {
			if (c[i][j] != s[j]) {
				err++;
			}
			if (err > d) 
				break;
		}
		if (err == d) {
			res.push_back(c[i]);
		}
	}
	return res;
}

vector <string> create(int k) {
	string s = "ACTG";
	vector <string> creature, tmp;
	tmp.push_back("A");
	tmp.push_back("C");
	tmp.push_back("T");
	tmp.push_back("G");
	for (int k1 = 0; k1 < k-1; k1++) {
		for (int i = 0; i < s.length(); i++) {
			for (int j = 0; j < tmp.size(); j++) {
				creature.push_back(tmp[j] + s[i]);
			}
		}
		if (k1 < k-2) {
			tmp.clear();
			tmp = creature;
			creature.clear();
		}
		else return creature;
	}
}

void motEn(vector <string> dna, int k, int d) {
	vector <string> tmp, tmpP;
	set <string> res;
	for (int i = 0; i < dna[0].length()-k+1; i++) {
		string tmp1 = dna[0];
		string tmp2 = "";
		for (int j = 0; j < k; j++) {
			int k = i + j;
			tmp2 += tmp1[k];
		}
		tmp.push_back(tmp2);
	}
	vector <string> cr = create(k);
	for (int i = 0; i < tmp.size(); i++) {
		tmpP.clear();
		tmpP = find(tmp[i], cr, d);
		for (int j = 0; j < tmpP.size(); j++) {
			int count = 0;
			for (int kk = 1; kk < dna.size(); kk++) {
				//string ss = dna[kk];
				for (int jj = 0; jj < dna[kk].length()-k+1; jj++) {
					string s = dna[kk].substr(jj, k);
					int mut = 0;
					for (int l = 0; l < tmpP[j].length(); l++) {
						//string sss = tmpP[j];
						if (tmpP[j][l] != s[l]) {
							mut++;
						}
					}
					if ((d == mut) || (mut == 0)) {
						count++;
						break;
					}

				}
			}
			if (count >= dna.size()-1)
				res.insert(tmpP[j]);
		}
	}
	for (auto i : res) {
		cout << i << " ";
	}

}


