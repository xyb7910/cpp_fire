/*
* @Author: Yanpb
* @Date:   2025-03-28 14:21:21
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-03-28 15:09:21
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int n, k;
queue<int> q;
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) q.push(i);

	while(q.size()) {
		for (int i = 0; i < k - 1; i ++) {
			q.push(q.front());
			q.pop();
		}
		cout << q.front() << " ";
		q.pop();
	}
	return 0;
}