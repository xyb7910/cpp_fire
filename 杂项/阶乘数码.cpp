/*
* @Author: Yanpb
* @Date:   2025-01-11 15:19:51
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-11 15:42:50
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

int res[N];

void solved() {
	/* your code */
	int t; cin >> t;
	while(t --) {
		memset(res, 0, sizeof (res));
		res[0] = {1};

		int n, a; cin >> n >> a;
		int k = 1; 
		for (int i = 1; i <= n; i ++) {
			for (int j = 0; j < k ; j ++) res[j] *= i;
			for (int j = 0; j < k - 1; j ++) {
				res[j + 1] += res[j] / 10;
				res[j] %= 10;
			}	
			while(res[k - 1] > 9) {
				res[k] = res[k - 1] / 10;
				res[k - 1] %= 10;
				k ++;
			}
		}

		int cnt = 0;
		for (int i = 0; i < k; i ++)
			if(res[i] == a) cnt ++;
		cout << cnt << endl;
	}
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}