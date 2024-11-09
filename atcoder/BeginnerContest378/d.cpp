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
const int N = 20;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int h, w, k;
char map[N][N];
bool st[N][N];
LL ans;

void dfs(int a, int b, int step) {
	if(step == k) {
		ans += 1;
		return ;
	}

	st[a][b] = 1;
	for (int i = 0; i < 4; i ++) {
		int x = a + dx4[i], y = b + dy4[i];
		if(x >= 0 && x < h && y >= 0 && y < w && !st[x][y] && map[x][y] == '.') {
			dfs(x, y, step + 1);
		}
	}
	st[a][b] = 0;
}
	
void solved() {
	/* your code */
	cin >> h >> w >> k;	
	for (int i = 0; i < h; i ++) cin >> map[i];

	for (int i = 0; i < h; i ++) {
		for (int j = 0; j < w; j ++) {
			if (map[i][j] == '.') {
				dfs(i, j, 0);
			}
		}
	}
	cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}