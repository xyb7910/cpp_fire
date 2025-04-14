/*
* @Author: Yanpb
* @Date:   2025-04-13 15:35:40
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-13 15:41:22
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
const int N = 2e5 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int n, m;
int s[N];
priority_queue<PII, vector<PII>, greater<PII>> q[N];

void solved() {
	/* your code */
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> s[i];

	while(m --) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		while(q[b].size()  && q[b].top().x  <= a) {
			s[b] += q[b].top().y;
			q[b].pop();
		}
		if(s[b] < d) puts("-1");
		else {
			q[b].push({a + c, d});
			s[b] -= d;
			cout << s[b] << endl;
		}
	}
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}