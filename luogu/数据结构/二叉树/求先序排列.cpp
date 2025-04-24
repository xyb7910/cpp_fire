/*
* @Author: Yanpb
* @Date:   2025-04-24 19:50:10
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-24 20:04:01
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
string in, pos;

void dfs(string in, string pos) {
	if(!pos.size()) return ;
	cout << pos.back();
	int t = in.find(pos.back());
	dfs(in.substr(0, t), pos.substr(0, t)); // 处理左子树
	dfs(in.substr(t + 1), pos.substr(t, pos.size() - t - 1)); // 处理右子树
}

int main() {
	cin >> in >> pos;
	dfs(in, pos);
	return 0;
}