#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int num[3];

int main() {
	int n;
	cin >> n;
	int cnt = 0;
	while(n != 495) {
		for (int i = 0; i < 3; i ++) {
			num[i] = n % 10;
			n /= 10;
		}
		sort(num, num + 3);
		n = num[2] * 100 + num[0] - num[0] * 100 - num[2];
		cnt ++;
	}
	cout << cnt << endl;

	return 0;
}