#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int cnt;
int main() {
	int s;
	cin >> s;
	for (int i = 1; i <= s / i; i ++) {
		if(s % i == 0) cnt ++;
	}
	cout << cnt << endl;

	return 0;
}