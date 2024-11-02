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
char map[10][10];
bool st[9][9];
void solved() {
	/* your code */
	for (int i = 1; i <=8; i ++) {
		for (int j = 1; j <= 8; j ++) {
			cin >> map[i][j];
			if (map[i][j] == '#') {
				// 在列上标记
				st[0][j] = 1;
				// 在行上标记
				st[i][0] = 1;
			}
		}
	}

	// for (int i = 1; i <= 8; i ++) {
	// 	cout << st[0][i] << " ";
	// }

	// for (int i = 1; i <= 8; i ++) {
	// 	cout << st[i][0] << endl;
	// }

	int sum = 0;
	for (int i = 1; i <= 8; i ++) {
		for (int j = 1; j <= 8; j ++) {
			if(!st[j][0] && !st[0][i]) sum ++;
		}
	}
	cout << sum << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}