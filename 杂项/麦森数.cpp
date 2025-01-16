/*
* @Author: Yanpb
* @Date:   2025-01-16 19:27:39
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-16 19:39:16
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 1e5 + 10;

int res[N], a[N], c[N];

void mul(int a[], int b[], int res[]) {
	memset(c, 0, N * 4);
	for (int i = 0; i < 500; i ++)
		for (int j = 0; j < 500; j ++)
			if(i + j < 500) 
				c[i + j] += a[i] * b[j];

	for (int i = 0, t = 0; i < 500; i ++) {
		t += c[i];
		res[i] = t % 10;
		t /= 10;
	}
}

void qmi(int p) {
	res[0] = 1;
	a[0] = 2;
	while(p) {
		if(p & 1) mul(a, res, res);
		mul(a, a, a);
		p >>= 1;
	}
	res[0] --;
}

int main() {
	int p; cin >> p;
	cout << int(p * log10(2) + 1) << endl;

	qmi(p);

	for (int i = 499, j = 0; j < 10; j ++) {
		for (int k = 0; k < 50; k ++, i --) {
			cout << res[i];
		}
		cout << endl;
	}
	return 0;
}