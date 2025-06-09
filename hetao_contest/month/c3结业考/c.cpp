/*
* @Author: Yanpb
* @Date:   2025-05-09 13:04:49
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-05-09 14:52:54
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

int x, y, k;
queue<int> q;
int num[N];

void solved() {
	/* your code */
	cin >> x >> y >> k;
	for (int i = 1; i <= x + y; i ++) q.push(i);
	for (int i = 1; i <= k && q.size() > x; i ++) {
		if(i == k) {
			i = 1;
			q.pop();
		}
		int t = q.front();
		q.pop();
		q.push(t);
	}
	int i = 0;
	while(q.size()) {
		num[i ++] = q.front();
		q.pop();
	}
	sort(num, num + i);
	for (int j = 0; j < i; j ++) cout << num[j] << " ";
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}