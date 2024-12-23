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
const int N = 1e5 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int base[10] = {2, 3, 5, 7, 11, 13};
int res[10][10];

void solved() {
	/* your code */
	string s; cin >> s;
	int plus_pos = s.find('+'); 
	int j = 0;
	for (int i = plus_pos - 1; ~i; i --) {
		if(isdigit(s[i])) res[1][j ++] = s[i] - '0';
	}
	j = 0;
	for (int i = s.size() - 1; i > plus_pos; i --) {
		if(isdigit(s[i])) res[2][j ++] = s[i] - '0';
	}

	for (int i = 0; i < j; i ++) {
		res[3][i] = res[2][i] + res[1][i];
	}
	for (int i = 0; i < j; i ++) {
		if(res[3][i] >= base[i]) {
			res[3][i + 1] += res[3][i] / base[i];
			res[3][i] %= base[i];
		}
	}
	if(res[3][j + 1]) j ++;
	for (int i = j; i; i --) cout << res[3][i] << ",";
	cout << res[3][0] << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}