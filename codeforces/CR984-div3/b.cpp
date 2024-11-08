#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <numeric>
#define x first
#define y second

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int N = 2e5 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool cmp(int a, int b) {
	return a > b;
}

void solved() {
	/* your code */
	int T;
	cin >> T;
	while(T --) {
		int n, k;
		cin >> n >> k;
		std::vector<int> w(k + 1, 0);
		for (int i = 1; i <= k; i ++) {
			int id, p;
			cin >> id >> p;
			w[id] += p;
		}
		sort(w.begin(), w.end(), cmp);
		int s = 0;
		for (auto a : w) if(a) s ++;
		if (n >= s) {
			cout << accumulate(w.begin(), w.end(), 0) << endl;
		} else {
			cout << accumulate(w.begin(), w.begin() + n, 0) << endl;
		}

	}
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}