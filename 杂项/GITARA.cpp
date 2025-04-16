/*
* @Author: Yanpb
* @Date:   2025-04-16 16:20:44
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-16 16:25:23
*/
#include <iostream>
#include <queue>

using namespace std;

const int N = 10;
priority_queue<int> q[N];

int n, p;

int main() {
	cin >> n >> p;
	int cnt = 0;
	for (int i = 0; i < n; i ++) {
		int id, pos; cin >> id >> pos;
		while(q[id].size() && q[id].top() > pos) {
			q[id].pop();
			cnt ++;
		}

		if(!q[id].size() || q[id].top() != pos) {
			q[id].push(pos);
			cnt ++;
		}
	}
	cout << cnt;
	return 0;
}