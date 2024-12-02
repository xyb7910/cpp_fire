#include <iostream>
using namespace std;

int main() {
	int n, d; cin >> n >> d;
	string s; cin >> s;
	for (int i = n - 1; i >= 0; i --) {
		if(s[i] == '@' && d) {
			s[i] = '.';
			d --;
		}
	}
	cout << s << endl;
	return 0;
}