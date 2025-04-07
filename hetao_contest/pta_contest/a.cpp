/*
* @Author: Yanpb
* @Date:   2025-04-07 12:50:06
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-07 13:39:08
*/
#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n, m; cin >> n >> m;
	queue<int> q;
	for (int i = 1; i <= n; i ++) q.push(i);
	while(q.size()) {
		for (int i = 1; i < m; i ++) {
			int t = q.front(); 
			// cout << t << " ";
			q.pop();
			q.push(t);
		}
		cout << q.front() << " ";
		q.pop();
	}
	return 0;
}