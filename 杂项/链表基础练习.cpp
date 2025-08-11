/*
* @Author: Yanpb
* @Date:   2025-06-14 15:56:28
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-06-14 19:50:05
*/

/*
#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int n, l[N], head = -1;
string name[N];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		int id, x; cin >> id >> name[id] >> x;
		if(!x) {
			l[id] = head;
			head = id;
		}
		else {
			l[id] = l[x];
			l[x] = id;
		}
	}
	for (int i = head; i != -1; i = l[i])
		cout << name[i] << " ";
	return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int n, l[N], w[N], x;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> w[i] >> l[i];
	}
	cin >> x;
	for (int i = 1; i <= n; i ++) {
		cout << w[i] << " " << l[i] << endl;
	}
	// for (int i = 1; i != -1; i = l[i]) {
	// 	cout << i << endl;
	// 	// cout << w[i] << " ";
	// }
	return 0;
}