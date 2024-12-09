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
typedef unsigned long long ULL;
const int N = 1e5 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int n, m;
char str[N];
ULL p[N], h[N];
const int P = 13331;

int get(int l, int r) {
	return h[r] - h[l - 1] * p[r - l + 1];
}

void solved() {
	/* your code */
	std::cin >> n >> m;
	std::cin >> str + 1;

	p[0] = 1;
	for (int i = 1; i <= n; i ++) {
		h[i] = h[i - 1] * P + str[i];
		p[i] = p[i - 1] * P;
	}

	while(m --) {
		int l1, r1, l2, r2;
		std::cin >> l1 >> r1 >> l2 >> r2;
		if(get(l1, r1) == get(l2, r2)) puts("Yes");
		else puts("No");
	}

}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}