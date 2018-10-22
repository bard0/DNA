
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1, s2;
	int k = 0;
	cin >> s1 >> s2;
	for (int i = 0; i < s2.size(); i++) {
		if (s1[0] == s2[i]) {
			bool flag = true;
			int a = i;
			for (int j = 1; j < s1.size(); j++) {
				if (s1[j] != s2[++a]) {
					flag = false;
					break;
				}
			}
			if (flag == true) k++;
		}
	}
	cout << k;
	return 0;
}