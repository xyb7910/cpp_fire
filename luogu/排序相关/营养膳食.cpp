/*
* @Author: Yanpb
* @Date:   2025-03-13 14:25:08
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-03-13 20:58:44
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

int n, m, k, res;
int mc[N];
PII food[N];

void solved() {
	/* your code */
    std::cin >> n >> m >> k;
    for (int i = 1; i <= k; i ++) std::cin >> mc[i];
    for (int i = 0; i < n; i ++) std::cin >> food[i].x >> food[i].y;
    sort(food, food + n, greater<PII>());
    for (int i = 0; i < n; i ++) {
        int id = food[i].y;
        if(mc[id] && m) {
            mc[id] --;
            m --;
            res += food[i].x;
        }
    }
    cout << res;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}