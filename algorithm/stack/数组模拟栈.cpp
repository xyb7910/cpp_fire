#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;
typedef long long LL;
int tt; // tt 表示为 栈顶部
int s[N];

int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int m;
	cin >> m;

	while(m --) {
		string op;
		cin >> op;
		if(op == "push") {
			int x;
			cin >> x;
			s[++ tt] = x; 	
		} else if(op == "pop") {
			tt --;
		} else if(op == "empty") {
			cout << (!tt ? "YES" : "NO") << endl;
		} else {
			cout << s[tt] << endl;
		}
	}
	return 0;
}