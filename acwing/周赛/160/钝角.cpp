#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, cnt;
int main() {
	cin >> n;
	while(n --) {
		int num;
		cin >> num;
		if(num > 90 && num < 180) cnt ++;
	}
	cout << cnt << endl;
	return 0;
}