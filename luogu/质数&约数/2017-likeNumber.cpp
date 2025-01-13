/*
* @Author: Hetao
* @Date:   2025-01-13 14:14:00
* @Last Modified by:   Hetao
* @Last Modified time: 2025-01-13 16:13:56
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

int primes[N];
bool st[N];
int cnt;

void get_primes(int n) {
	for (int i = 2; i <= n; i ++) {
		if(!st[i]) primes[cnt ++] = i;
		for (int j = 0; primes[j] <= n / i; j ++) {
			st[i * primes[j]] = 1;
			if(i % primes[j] == 0) break;
		}
	}
}

int res[N] = {1, 1, 1};

void work(int n) {
	cnt = 0;
	for (int i = 3; i <= n; i ++) {
		if(!st[i] && !st[(i + 1) / 2]) res[i] ++;
		res[i] += res[i - 1];
	}
}


void solved() {
	/* your code */
	get_primes(N);
	work(N);
	// for (int i = 0; i <= 53; i ++) cout << res[i] << " ";
	int n; cin >> n;
	while(n --) {
		int a, b; cin >> a >> b;
		cout << res[b] - res[a - 1] << endl;
	}
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}