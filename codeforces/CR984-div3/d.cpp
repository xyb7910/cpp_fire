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

char a[N][N];
char str[4*N];

void solved() {
	/* your code */
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i ++) cin >> a[i];
	LL cnt = 0;
	for (int i = 0; i < min(n, m) / 2; i ++) {
		LL pos = 0;
		// 上方
		for (int j = i; j < m - i; j ++) str[pos ++] = a[i][j];
		// 右方	
		for (int j = i + 1; j < n - i - 1; j ++) str[pos ++] = a[j][m - i - 1];
		// 下方
		for (int j = m - i - 1; j >= i; j --) str[pos ++] = a[n - i - 1][j];
		// 左方
		for (int j = n - i - 2; j>= i + 1; j --) str[pos ++] = a[j][i]; 

		// 遍历存储的字符串
		for (int j = 0; j < pos; j ++) {
			if(str[j] == '1' && str[(j + 1) % pos] == '5' && str[(j + 2) % pos] == '4' && str[(j + 3) % pos] == '3')
				cnt ++;
		}	
	}
	cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T;
    cin >> T;
    while(T --) solved();
    return 0;
}