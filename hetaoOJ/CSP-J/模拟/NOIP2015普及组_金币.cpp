/*
* @Author: Yanpb
* @Date:   2025-04-22 23:02:11
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-22 23:08:27
*/
#include <iostream>

using namespace std;

int k, sum;

int main() {
	cin >> k;
	for (int i = 1, days = 1; days <= k; i ++) {
		for (int j = 1; j <= i && days <= k; j ++, days ++) {
			sum += i;
		}
	}
	cout << sum;
	return 0;
}