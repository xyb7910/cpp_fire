/*
* @Author: Yanpb
* @Date:   2025-03-31 12:33:59
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-03-31 15:10:15
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
const int N = 1e5 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

string s;
int st[N], tt, res;

void solved() {
	/* your code */
	cin >> s;
	for (int i = 0; i < s.size(); i ++) {
		if(s[i] == '(') st[++ tt] = s[i];
		else {
			if(!tt) {
				st[++ tt] = '(', res ++;
			} else {
				tt --;
			}
		} 	
	}
	if(tt) {
		res += tt / 2;
	}
	cout << res;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}