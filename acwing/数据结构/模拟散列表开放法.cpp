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
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int N = 1e5 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int n;

// 开放定址法
int h[N], null = 0x3f3f3f3f;

// 如果当前位置为 空， 就返回它应该存储位置
int find(int x) {
	int t = (x % N + N) % N;
	while(h[t] != null && h[t] != x) {
		t ++;
		if(t == N) t = 0;
	}
	return t;
}


void solved() {
	/* your code */
	memset(h, 0x3f, sizeof h);
	std::cin >> n;
	while(n --) {
		char op[2];
		int num;
		std::cin >> op >> num;
		if(*op == 'I') h[find(num)] = num;
		else {
			if(h[find(num)] == null) puts("No");
			else puts("Yes");
		}
	}
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}