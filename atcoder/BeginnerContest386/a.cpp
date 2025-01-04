/*
* @Author: Yanpb
* @Date:   2025-01-04 16:48:37
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-04 18:33:38
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

unordered_map<int, int> heap;
vector<int> res;

void solved() {
	/* your code */
	for (int i = 1; i <= 4; i ++) {
		int num; cin >> num;
		heap[num] ++;
	}

	for (auto a : heap) res.push_back(a.y);
	sort(res.begin(), res.end());
	if(res.size() == 2 && (res[0] == 1 || res[0] == 2)) puts("Yes");
	else puts("No");
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}