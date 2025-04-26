/*
* @Author: Yanpb
* @Date:   2025-04-25 13:21:12
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-25 14:33:09
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
typedef priority_queue<int,vector<int>,greater<int>> PIG;
typedef priority_queue<int> PIL; 
const int N = 1e5 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int n;
PII t[N];

void pre(int u) {
	if(!u) return ;
	cout << u;
	pre(t[u].x);
	pre(t[u].y);
}

void inor(int u) {
	if(!u) return ;
	inor(t[u].x);
	cout << u;
	inor(t[u].y);
}

void solved() {
	/* your code */
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> t[i].x >> t[i].y;
	}
	pre(1); cout << endl;
	inor(1);
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}