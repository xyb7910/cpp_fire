/*
* @Author: Yanpb
* @Date:   2025-05-08 16:43:56
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-05-08 19:25:47
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int n;
int main() {
	cin >> n;
	int cnt = 0, ans = 0;
	while(n) {
		cnt ++;
		int sum = (n + 2) / 3;
		if(n % 3 == 1 && !ans) ans = cnt;
		n -= sum;
	}
	cout << cnt << " " << ans;
	return 0;
}