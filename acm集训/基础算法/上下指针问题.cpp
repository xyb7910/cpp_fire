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

int n, m;
int a[N], b[N];

void solved() {
	/* your code */
	cin >> n >> m;
	for (int i = 0; i < n; i ++) cin >> a[i];
	for (int j = 0; j < m; j ++) cin >> b[j];

	int i = 0, j = 0;
	while(i < n && j < m) {
		if(a[i] == b[j]) i ++;
		j ++;
	}
	if(i == n) puts("Yes");
	else puts("No");
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}