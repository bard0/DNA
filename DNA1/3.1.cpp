#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>
using namespace std;
int T[18] = { 57,71,87,97,99,101,103,113,114,115,128,129,131,137,147,156,163,186 };

vector <vector <int>> expand(vector <vector <int>> ex) {
	/*vector <vector <int>> res;
	vector <int> tmp;
	for (int i = 0; i < peps.size(); i++) {
		for (int j = 0; j < 18; j++) {
			tmp = peps[i];
			tmp.push_back(T[j]);
			res.push_back(tmp);
			tmp.clear();
		}
	}
	return res;*/
	vector <int> tmp;
	vector <vector<int>> res;
	for (int i = 0; i < ex.size(); i++) {
		for (int j = 0; j < 18; j++) {
			tmp = ex[i];
			int n = tmp.size() - 1;
			bool flag = true;
			//for (int k = 0; k < tmp.size(); k++){
			if (tmp[n] == T[j])
				flag = false;
			//}
			if (flag) {
				tmp.push_back(T[j]);
				res.push_back(tmp);
			}
			tmp.clear();
		}
	}
	return res;
}

int mass(vector <int> pep) {
	int mass = 0;
	for (int i = 0; i < pep.size(); i++) {
		mass += pep[i];
	}
	return mass;
}

int parentMass(vector <int> spectr) {
	return spectr[spectr.size()-1];

}

vector <int> cyclo(vector <int> s) {
	vector <int> s1;
	vector <int> res;
	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < s.size(); i++) {
			s1.push_back(s[i]);
		}
	}
	for (int i = 0; i < s.size(); i++)
	{
		int tmp = 0;
		for (int j = 0; j < s.size() - 1; j++) {
			int n = i + j;
			tmp += s1[n];
			res.push_back(tmp);
		}
	}
	int tmp = 0;
	for (int i = 0; i < s.size(); i++) {
		tmp += s[i];
	}
	res.push_back(tmp);
	sort(res.begin(), res.end());
	return res;
}

bool flag(vector <int> v, vector <int> spectr) {
	vector <int> tmp = spectr;
	bool f;
	for (int i = 0; i < v.size(); i++) {
		f = false;
		for (int j = 0; j < tmp.size(); j++) {
			if (v[i] == tmp[j]) {
				f = true;
				tmp[j] = 0;
				break;
			}
		}
		if (f == false) return false;
	}
	return true;
}

bool spectrum(vector <int> s, vector <int> spectr) {
	vector <int> tmp, tmp2;

	int su = 0;
	int a = s.size();


	while (a != 1) {
		int su = 0;
		if (a == 2) {
			su = s[0] + s[1];
			tmp2.push_back(su);
			s.pop_back();
			a = s.size();
		}
		else if (a == 3) {
			su = s[2] + s[1];
			tmp2.push_back(su);
			s.pop_back();
			a = s.size();
		}
		else {
			for (int i = s.size() - 1; i > -1; i--) {
				su += s[i];
				tmp2.push_back(su);
			}
			s.pop_back();
			a = s.size();
		}
	}

	if (!flag(tmp2, spectr)) {
		return false;
	} else 
		return true;

}

int main() {
	vector <int> spectr, tmp, tmp3;
	int n = 0;
	int k = 0;
	/*while (cin >> n) {
		spectr.push_back(n);
	}*/
	spectr = {0, 97, 97, 99, 101, 103, 196, 198, 198, 200, 202, 295, 297, 299, 299, 301, 394, 396, 398, 400, 400, 497 };
	//spectr = { 113,128,186,241,299,314,427 };
	vector <vector <int>> res, Res, tmp2;
	
	for (int i = 0; i < spectr.size(); i++) {
		for (int j = 0; j < 18; j++) {
			if (spectr[i] == T[j]) {
				tmp.push_back(spectr[i]);

				bool flag = true;
				for (int k = 0; k < res.size(); k++) {
					if (res[k] == tmp) {
						flag = false;
						break;
					}
				}
				if (flag) {
					res.push_back(tmp);
				}
				//tmp.push_back(n);
				tmp.clear();
			}
		}
	}
	vector <int> t1 = { 0 };
	res.push_back(t1);
	while (!res.empty()) {
		res = expand(res);
		vector <vector<int>> t;
		int j = 0;
		while (!res.empty()){
			/*if (!spectrum(res[55], spectr)) {
				cout << "sdfsd";
			}*/
			if (mass(res[0]) == parentMass(spectr)) {
				if (cyclo(res[0]) == spectr) {
					Res.push_back(res[0]);
				}
				res.erase(res.begin());
			}
			else
				if (!spectrum(res[0], spectr)) {
					res.erase(res.begin());
				}
				else {
					t.push_back(res[0]);
					res.erase(res.begin());
				}
		}
		res = t;
		
	}
	
	for (int i = 0; i < Res.size(); i++) {
		tmp = Res[i];
		for (int j = 0; j < tmp.size(); j++) {

			if (j == tmp.size() - 1) {
				cout << tmp[j] << " ";
			}
			else
				cout << tmp[j] << "-";
		}
	}
	return 0;
}