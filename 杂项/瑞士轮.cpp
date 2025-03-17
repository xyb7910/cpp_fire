/*
* @Author: Yanpb
* @Date:   2025-03-17 20:27:49
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-03-17 20:37:37
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
const int N = 2e5 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int n, r, q;
int s[N], w[N], p[N], p0[N], p1[N];

bool cmp(int a, int b) {
	if(s[a] != s[b]) return s[a] > s[b];
	return a < b; 
}

void solved() {
	/* your code */
	std::cin >> n >> r >> q;
	for (int i = 0; i < 2 * n; i ++) std::cin >> s[i];
	for (int i = 0; i < 2 * n; i ++) std::cin >> w[i];
	for (int i = 0; i < 2 * n; i ++) p[i] = i;

	sort(p, p + n * 2, cmp);

	while(r --) {
		int t0 = 0, t1 = 0;
		for (int i = 0; i < 2 * n; i += 2) {
			int a = p[i], b = p[i + 1];
			if(w[a] < w[b]) {
				s[b] ++;
				p0[t0 ++] = a;
				p1[t1 ++] = b;
			} else {
				s[a] ++;
				p0[t0 ++] = b;
				p1[t1 ++] = a;
			}
		}

		int i = 0, j = 0, t = 0;
		while(i < t0 && j < t1) {
			if(cmp(p0[i], p1[j])) {
				p[t ++] = p0[i ++];
			} else {
				p[t ++] = p1[j ++];
			}
		}

		while(i < t0) p[t ++] = p0[i ++];
		while(j < t1) p[t ++] = p1[j ++];
	}
	cout << p[q - 1] + 1;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}