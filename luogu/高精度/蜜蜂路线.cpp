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
const int N = 1e3 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int res[N][N];
int l = 1;
void add(int x) {
	for (int i = 1; i <= l; i ++)
		res[x][i] = res[x - 1][i] + res[x - 2][i];
	for (int i = 1; i <= l; i ++) 
		if(res[x][i] > 9) {
			res[x][i + 1] += res[x][i] / 10;
			res[x][i] %= 10;
		}
	if(res[x][l + 1]) l ++;
}

void solved() {
	/* your code */
	int n, m; cin >> n >> m;
	res[1][1] = 1;  
	res[2][1] = 2; 
	for (int i = 3; i <= m - n; i ++) add(i);
	for (int i = l; i; i --) cout << res[m - n][i];
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}