#include <iostream>
using namespace std;

int main() {
	int n, d; cin >> n >> d;
	string s; cin >> s;
	int res = 0;
	for (int i = 0; i < n; i ++) if(s[i] == '.') res ++;
		cout << res + d << endl;
	return 0;
}