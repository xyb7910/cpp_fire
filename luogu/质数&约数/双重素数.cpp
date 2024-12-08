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
const int N = 1e5 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int primes[N];
bool st[N];
int cnt;

int count(int k) {
	int res = 0;
	while(k) {
		res += k % 10;
		k /= 10;
	}
	return res;
}

bool is_prime(int x) {
	if(x < 2) return false;
	for (int i = 2; i <= x / i; i ++)
		if(x % i == 0) return false;
	return true;
}

void get_primes(int n) {
	for (int i = 2; i <= n; i ++) {
		if(!st[i] && is_prime(count(i))) primes[cnt ++] = i;
		for (int j = 0; primes[j] * i <= n; j ++) {
			st[primes[j] * i] = 1;
			if(i % primes[j] == 0) break;
		}
	}
}

void solved() {
	/* your code */
	int l, r; cin >> l >> r;
	int start = lower_bound(primes, primes + cnt, l) - primes;
	int end = upper_bound(primes, primes + cnt, r) - primes;
	// cout << start << " " << end << endl;
	cout << end - start << endl;
}

int main() {
    get_primes(N);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
   	int T; cin >> T; while(T --) solved();
    return 0;
}