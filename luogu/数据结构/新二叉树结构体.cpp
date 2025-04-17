/*
* @Author: Yanpb
* @Date:   2025-04-16 10:02:35
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-16 10:24:39
*/
#include <iostream>
using namespace std;

const int N = 1e5 + 10;

struct Node{
	int l, r;
}t[N];

int a[N], b[N], c[N];

void dfs(int x) {
	cout << char(x);
	if(t[x].l != 0) dfs(t[x].l);
	if(t[x].r != 0) dfs(t[x].r);
}

int main() {
	int n; cin >> n;
	for(int i = 1; i <= n; i ++) {
		string s; cin >> s;
		a[i] = s[0]; b[i] = s[1]; c[i] = s[2];
		if(b[i] != '*') t[a[i]].l = b[i];
		if(c[i] != '*') t[a[i]].r = c[i];
	}
	dfs(a[1]);
	return 0;
}