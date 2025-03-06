/*
* @Author: Hetao
* @Date:   2025-03-06 16:37:29
* @Last Modified by:   Hetao
* @Last Modified time: 2025-03-06 17:08:14
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
const int N = 1e6 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int R[N], Y[N], B[N];
int n, m, cnt;

void solved() {
	/* your code */
	cin >> n >> m;
	for (int i = 1; i <= m; i ++) {
		int l, r, k; cin >> l >> r >> k;
		if(k == 1) Y[l] ++, Y[r + 1] --;
		else if(k == 2) B[l] ++, B[r + 1] --;
		else R[l] ++, R[r + 1] --;
	}
	for (int i = 1; i <= n; i ++) {
		R[i] += R[i - 1];
		B[i] += B[i - 1];
		Y[i] += Y[i - 1]; 
		if(Y[i] && B[i] && !R[i]) cnt ++;
	} 	
	cout << cnt;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}