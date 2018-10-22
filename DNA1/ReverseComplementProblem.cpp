#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	string s1, s2;
	cin >> s1;
	stack <char> st;
	for (int i = 0; i < s1.length(); i++) {
		st.push(s1[i]);
	}
	while (!st.empty()) {
		if (st.top() == 'A') {
			s2 = s2 + "T";
			st.pop();
			
		}
		else {
			if (st.top() == 'T') {
				s2 = s2 + "A";
				st.pop();

			}
			else {
				if (st.top() == 'C') {
					s2 = s2 + "G";
					st.pop();

				} else 
				if (st.top() == 'G') {
					s2 = s2 + "C";
					st.pop();

				}
			}
		}
	}
	cout << s2;
	return 0;
}