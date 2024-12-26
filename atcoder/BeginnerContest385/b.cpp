/*
* @Author: Yanpb
* @Date:   2024-12-26 16:37:22
* @Last Modified by:   Yanpb
* @Last Modified time: 2024-12-26 18:46:18
*/
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
typedef long long i64;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int N = 1e2 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};
char map[N][N];
string t;
bool st[N][N];

void solved() {
	/* your code */
	int h, w, x, y; cin >> h >> w >> x >> y;
	for (int i = 1; i <= h; i ++)
		for (int j = 1; j <= w; j ++)
			cin >> map[i][j];
	cin >> t;
	int cnt = 0, dx = 0, dy = 0;
	for (int i = 0; i < t.size(); i ++) {
		char d = t[i];
		if(d == 'L') dx = 0, dy = -1;
		if(d == 'D') dx = 1, dy = 0;
		if(d == 'R') dx = 0, dy = 1;
		if(d == 'U') dx = -1, dy = 0;
		
		int a = x + dx, b = y + dy;
		if(a > 0 && a <= h && b > 0 && b <= w && map[a][b] == '.' || map[a][b] == '@') {
			if(map[a][b] == '@' && !st[a][b]) {
				cnt ++;
				st[a][b] = 1;
			}
			x = a, y = b;
		}
		
		// cout << x << " " << y << endl;
	}
	cout << x << " " << y << " " << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}