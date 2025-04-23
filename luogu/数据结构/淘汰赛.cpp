/*
* @Author: Yanpb
* @Date:   2025-04-17 16:19:17
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-23 16:30:31
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 10;
int n;
int val[1 << N], win[1 << N];

void dfs(int x) {
	if(x >= (1 << n)) return ;

	
}

int main() {
	cin >> n;
	for (int i = 0; i < (1 << n); i ++) {
		cin >> val[i + (1 << n)];
		win[i + (1 << n)] = i + 1;
	}
	dfs(1);
	cout << (val[2] > val[3] ? win[3] : win[2]);
	return 0;
}