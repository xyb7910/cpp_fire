/*
* @Author: Yanpb
* @Date:   2024-12-27 21:37:35
* @Last Modified by:   Yanpb
* @Last Modified time: 2024-12-28 13:16:45
*/
#include <iostream>
using namespace std;

const int N = 1e3 + 10;
int A[N], B[N], C[N];

int main() {
	string a, b; cin >> a >> b;

	int l1 = 0, l2 = 0;
	for (int i = a.size() - 1; ~i; i --) A[l1 ++] = a[i] - '0';
	for (int i = b.size() - 1; ~i; i --) B[l2 ++] = b[i] - '0';

	int l = max(a.size(), b.size());
	for (int i = 0; i < l; i ++) {
		C[i] = A[i] + B[i];
	}

	for (int i = 0; i < l; i ++) {
		C[i + 1] = C[i + 1] + C[i] / 10;
		C[i] = C[i] % 10;
	}
	if(C[l]) l ++;
	while(C[l] ==  0 && l > 0) l --;
	for (int i = l; i >= 0; i --) cout << C[i];
	return 0;
}