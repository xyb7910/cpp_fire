/*
* @Author: Yanpb
* @Date:   2025-04-22 23:25:06
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-22 23:29:11
*/
#include <iostream>

using namespace std;

int l, r, cnt;

int main() {
	cin >> l >> r;
	for (int i = l; i <= r; i ++) {
		int num = i;
		while(num) {
			if(num % 10 == 2) cnt ++;
			num /= 10;
		}
	}
	cout << cnt;
	return 0;
}