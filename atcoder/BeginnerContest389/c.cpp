/*
* @Author: Yanpb
* @Date:   2025-01-24 14:17:39
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-24 22:03:13
*/
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
typedef long long i64;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int N = 3e5 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

struct Snake {
	int l; // 蛇的长度
	int head_pos; // 当前第 i 条蛇的蛇头位置
};

Snake sq[N];

void solved() {
	/* your code */
	int q; cin >> q;
	int tt = 0, hh = 0, h = 0;
	while(q --) {
		int op, l;
		cin >> op;
		if(op == 1) {
			cin >> l;
			Snake new_na = {l, h};
			sq[++ tt] = new_na;
			h += l;
		} else if(op == 2) {
			int m = sq[hh ++].l;
			for (int i = hh; i <= tt; i ++ ) {
				sq[i].head_pos -= m;
			} 
			h -= m;
		} else if(op == 3){
			cin >> l;
			auto head = sq[hh + l];
			cout << head.head_pos << endl;
		}

	}
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}