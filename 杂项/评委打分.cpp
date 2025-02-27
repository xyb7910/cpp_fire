/*
* @Author: Yanpb
* @Date:   2025-02-24 20:23:25
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-02-24 20:29:41
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int main() {
	cin >> n;
	int maxv = -1, minv = 101;
	double sum = 0;
	for (int i = 1; i <= n; i ++) {
		int x; cin >> x;
		minv = min(minv, x), maxv = max(maxv, x);
		sum += x;
		if(i > 2) {
			sum -= (minv + maxv);
			printf("%.2lf\n", sum / (i - 2));
			sum += (minv + maxv);
		}
	}
	return 0;
}