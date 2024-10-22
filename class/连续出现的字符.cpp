#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	string s;
	int n;
	cin >> n >> s;
	size_t pos = 0;
	int cnt = 1;
	for (int i = 1; i < s.size(); i ++) {
		if (s[i] == s[pos]) {
			cnt ++;
			// cout << pos << " " << cnt << endl;
			if (cnt >= n) {
			cout << s[i] << endl;
			break;
			}
		} else {
			pos = i;
			cnt = 1;
		}
		
	}
	return 0;
}