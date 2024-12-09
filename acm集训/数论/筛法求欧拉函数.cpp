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
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int N = 1e6 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int primes[N], phi[N];
bool st[N];
int cnt;

LL get_eulars(int  n) {
	phi[1] = 1;
	for (int i = 2; i <= n; i ++) {
		if(!st[i]) {
			primes[cnt ++] = i;
			phi[i] = i - 1;
		}
		for (int j = 0; primes[j] * i <= n; j ++) {
			st[primes[j] * i] = 1;
			if(i % primes[j] == 0) {
				phi[i * primes[j]] = primes[j] * phi[i];
				break;	
			}
			phi[primes[j] * i] = phi[i] * (primes[j] - 1);
		}
	}

	LL res = 0;
	for (int i = 1; i <= n; i ++) res += phi[i];

	return res;
}

void solved() {
	/* your code */
	// 给定一个正整数 n，求 1∼n 中每个数的欧拉函数之和。
	int n; cin >> n;
	cout << get_eulars(n) << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}