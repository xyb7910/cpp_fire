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

const int MOD = 1e9 + 10;
void solved() {
	/* your code */
	int n; cin >> n;
	unordered_map<int, int> prime_cnt;
	while(n --) {
		int num; cin >> num;
		for (int i = 2; i <= num / i; i ++) {
			while(num % i == 0) {
				prime_cnt[i] ++;
				num /= i;
			}
		}	
		if(num > 1)  prime_cnt[num] ++;
	}

	LL res = 1;
	for (auto p : prime_cnt) {
		LL a = p.x, b = p.y;
		LL t = 1;
		while(b --) t = (t * a + 1) % MOD;
		res = res * t % MOD;
	}
	cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}