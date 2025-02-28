/*
* @Author: Yanpb
* @Date:   2025-02-28 13:04:36
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-02-28 15:11:38
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

int n, m;
int A[N], R[N], G[N], T[N];
void solved() {
	/* your code */
	cin >> n >> m;
	for (int i = 2; i <= n; i ++) cin >> A[i];
	for (int i = 1; i <= n; i ++) cin >> R[i];
	for (int i = 1; i <= n; i ++) cin >> G[i];
	for (int i = 1; i <= n; i ++) T[i] = G[i] + R[i];
	i64 res = m;
	for (int i = 1; i <= n; i ++) {
		res += A[i];
		int t = res % T[i];
		if(t > G[i]) {
			// red
			res += R[i] - (t - G[i]);	
		} else {
			// green
			res = res;
		} 
		cout << res << endl;
		
	}
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}