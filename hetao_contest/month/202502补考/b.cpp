/*
* @Author: Yanpb
* @Date:   2025-03-03 16:48:00
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-03-03 19:57:22
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
const int N = 1e5 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

typedef pair<int, char> IC;
int k, n;
IC question[N];

void solved() {
	/* your code */
	cin >> k >> n;
	for (int i = 0; i < n; i ++) 
		cin >> question[i].x >> question[i].y;
	int time = 210, i = 0;
	while(time >= question[i].x && i < n) {
		// 时间
		time -= question[i].x;
		if(question[i].y == 'T') {
			// 传个下一个人
			k ++;
			if(k > 8) k %= 8;
		} 
		i ++;
	}
	cout << k;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}