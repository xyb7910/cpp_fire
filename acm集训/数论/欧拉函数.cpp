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

int euler_phi(int n) {
	int res = n;
	for (int i = 2; i <= n / i; i ++) {
		if(n % i == 0) {
			res = res / i * (i - 1);
			while(n % i == 0) n /= i;
		}
	}
	if(n > 1) res = res / n * (n - 1);
	return res;
}

void solved() {
	/* your code */
	int n; cin >> n;
	for (int i = 1; i <= n; i ++) {
		int num; cin >> num;
		cout << euler_phi(num) << endl;
	}
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}