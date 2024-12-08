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

// 两年OI一场空，不开 long long 见祖宗！！！
vector<LL> divide(LL n) {
	std::vector<LL> res;
	for (int i = 2; i <= n / i; i ++) {
		if(n % i == 0) {
			while(n % i == 0) {
				res.push_back(i);
				n /= i;
			}
		}
	}
	if(n > 1) res.push_back(n);
	return res;
}

void solved() {
	/* your code */
	LL num; cin >> num;
	std::vector<LL> ans = divide(num);
	for (int i = 0 ; i < ans.size(); i ++) cout << ans[i] << " ";
	cout << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T; cin >> T; while(T --) solved();
    return 0;
}