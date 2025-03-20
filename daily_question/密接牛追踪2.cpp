/*
* @Author: Yanpb
* @Date:   2025-03-20 19:44:01
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-03-20 20:11:18
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
const int N = 3e5 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int n;
char s[N];
std::vector<int> cnt;

void solved() {
	/* your code */
	cin >> n >> s;
	int r = n; // 表示天数
	for (int i = 0; i < n; i ++) {
		if(s[i] == '0') continue;
		int j = i + 1;
		while(j < n && s[j] == '1') j ++;
		int c = j - i, d = (c - 1) / 2;
		if(!i || j == n) d = c - 1;
		r = min(r, d);
		cnt.push_back(c);
		i = j;
	}

	int res = 0;
	for (auto c : cnt) {
		res += (c + 2 * r) / (2 * r + 1); 
	}
	cout << res;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}