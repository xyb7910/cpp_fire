/*
* @Author: Yanpb
* @Date:   2025-01-03 12:54:02
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-03 14:57:31
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

#define x first
#define y second

using namespace std;
typedef long long i64;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int N = 1e5 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int res[N] = {1};

void solved() {
	/* your code */
	int n; cin >> n;
	int k = 1;
	for (int q = 1; q <= n; q ++) {
		for (int i = 0; i < k; i ++) 
			res[i] *= 2;
		for (int i = 0; i < k; i ++) {
			res[i + 1] += res[i] / 10;
			res[i] = res[i] % 10;
		}
		if(res[k]) k ++;
	}
	res[0] -= 1;
	cout << k;
	int cnt = 500 - k;
	for (int i = 0; i < cnt - 1; i ++) {
		if(i % 50 == 0) cout << endl;
		cout << "0";
	}
	n = k % 50;
	for (int i = k; i >= k  - n; i --)
		cout << res[i];
	
	for (int i = k - n - 1; i >= 0; i --) {
		if((i + 1) % 50 == 0) cout << endl;
		cout << res[i];
	}
		
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}