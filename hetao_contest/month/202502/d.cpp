/*
* @Author: Yanpb
* @Date:   2025-02-28 13:04:43
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-02-28 21:52:54
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
int m, n;
PII game[N];
bool st[N];
i64 res;
/*
优先让罚款多的先做
考试WA原因：贪心样例都分析错了， qaq
*/
void solved() {
    /* your code */
    cin >> m >> n;
    for (int i = 0; i < n; i ++) cin >> game[i].y;
    for (int i = 0; i < n; i ++) cin >> game[i].x;
    // 根据罚款多少进行排序
    sort(game, game + n, greater<PII>());
    // 给每一个游戏安排时间
    for (int i = 0; i < n; i ++) {
        // 先从截止时间进行安排
        for (int j = min(n, game[i].y); j >= 1; j --) {
            // 可以安排时间
            if(!st[j]) {
                st[j] = true;
                break;
            }
            // 无法安排时间
            if(j == 1) {
                res += game[i].x;
            }
        }
    }
    cout << m - res;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}