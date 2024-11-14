#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	int cnt = 0, n;
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= i; j ++) {
			cout << char('A' + (cnt ++) % 26);
		}
		cout << endl;
	}
	return 0;
}