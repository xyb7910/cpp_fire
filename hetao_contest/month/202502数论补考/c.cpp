/*
* @Author: Yanpb
* @Date:   2025-03-03 16:37:05
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-03-03 16:39:28
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
const int N = 1e7 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int cnt;
int primes[N];
bool st[N];

void get_primes(int n) {
	for (int i = 2; i <= n; i ++) {
		if(!st[i]) primes[cnt ++] = i;
		for (int j = 0; primes[j] * i <= n; j ++) {
			st[primes[j] * i] = 1;
			if(i % primes[j] == 0) break;
		}
	}
}

void solved() {
	/* your code */
	int m, n; cin >> m >> n;
	get_primes(N);
	for (int i = m; i <= n; i ++) {
		if(!st[i]) {
			bool f = 1;
			int num = i;
			while(num) {
				if(st[num] || num < 2)  {
					f = 0;
					break;
				}
				num /= 10;
			}
			if(f) cout << i << endl;
		}
	}
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}