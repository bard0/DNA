#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	string s1, s2, s3;
	stack <string> st;
	int k = 0, lmax = 1, b=0;
	cin >> s1 >> k;
	for (int i = 0; i < s1.size() - k; i++) {
		int l = 0;
			b = i;
			s2.clear();
			while (b < i + k ) { //формируем слово
				s2 = s2 + s1[b];
				b++;
			}
			for (int a = 0; a < s1.size(); a++) { //ищем частоту вхождения слова 
				if (s2[0] == s1[a]) {
					bool flag = true;
					b = a;
					for (int j = 1; j < k; j++) {
						if (s2[j] != s1[++b]) {
							flag = false;
							break;
						}
					}
					if (flag == true) l++;
				}
			}
			if (l > lmax) { //добавляем слова с наибольшей частотой в стек
				lmax = l;
				while (!st.empty()) {
					st.pop();
				}
				st.push(s2);
			} else if (l == lmax)  st.push(s2); 
	}
	while (!st.empty()) { //берем из стека неповторяющиеся слова 
		if (s3.find(st.top()) == -1) {
			s3 = s3 + st.top() + " ";
			st.pop();
		}
		else st.pop();
	}
	cout << s3;
	return 0;
}