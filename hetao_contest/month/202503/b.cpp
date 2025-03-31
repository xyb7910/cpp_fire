/*
* @Author: Yanpb
* @Date:   2025-03-31 12:33:53
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-03-31 13:29:21
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
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


void solved() {
	/* your code */
	deque<int> q;
	int n; cin >> n;
	int id = 1;
	while(n --) {
		char op, dir; cin >> op >> dir;
		if(op == 'A') {
			if(dir == 'L') q.push_front(id ++);
			else q.push_back(id ++);
		}
		if(op == 'D') {
			int k; cin >> k;
			while(k --) {
				if(dir == 'L') q.pop_front();
				else q.pop_back();
			}
		}
	}
	for (auto a : q) cout << a << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}