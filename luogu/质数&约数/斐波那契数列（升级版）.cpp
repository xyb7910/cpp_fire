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

const int MOD = 1 << 31;
LL finonacci(int n) {
	if(n == 1 || n == 2) return 1;
	LL a = 1, b = 1, c = 0;
	for (int i = 3; i <= n; i ++) {
		c = (a + b) % MOD;
		a = b;
		b = c;
	}
	return c;
}	


vector<int> div(LL n) {
	std::vector<int> factors;
	for (int i = 2; i <= n / i; i ++) {
		while(n % i == 0) {
			factors.push_back(i);
			n /= i;
		}
	}
	if(n > 1) factors.push_back(n);
	return factors;
}



void solved() {
	/* your code */
	int n; cin >> n;
	LL fib_n = finonacci(n);
	std::vector<int> factors = div(fib_n);
	cout << fib_n << "=" << factors[0];
	for (int i = 1; i < factors.size(); i ++) {
		cout << "*" << factors[i];
	}
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}