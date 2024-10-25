#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;
typedef long long LL;
int q[N];
int n, tt = -1, hh;
int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	while(n --) {
		string op;
		cin >> op;
		if(op == "push") {
			int x;
			cin >> x;
			q[++ tt] = x; 
		} else if(op == "pop") {
			hh ++;
		} else if(op == "empty") {
			cout << (hh <= tt ? "NO" : "YES") << endl;
		} else {
			cout << q[hh] << endl;
		}
	}
	return 0;
}
