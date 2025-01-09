/*
* @Author: Yanpb
* @Date:   2025-01-08 16:45:05
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-08 21:33:50
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>

#define x first
#define y second

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int N = 2e7 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int ans[N];
int n;

void solved() {
    /* your code */
    cin >> n;
    // 先把 4 * n 存起来
    ans[0] = 4 * n % 10, ans[1] = 4 * n / 10;
    // 然后计算 n 个 40 - n 个 8
    for (int i = 1; i <= n; ++ i) {
        ans[i << 1] = 4, ans[i] -= 8;
        // 计算保留位
        ans[i + 1] += ans[i] / 10, ans[i] %= 10;
        if(ans[i] < 0) {
            ans[i] += 10, ans[i + 1] --;
        }
    }
    
    // 处理高位进位 最高位为 n + 1
    for (int i = n + 1; ans[i] < 0; ++ i) {
        ans[i + 1] += ans[i] / 10, ans[i] %= 10;
        ans[i] += 10, ans[i + 1] --;
    }
    // 处理输出 ans 最后 除以 9; 总位数 等于 2 * n - 1
    for (int i = 2 * n - 1; ~i; -- i) {
        ans[i] += ans[i + 1] * 10;
        cout << char(ans[i] / 9 + '0');
        ans[i] %= 9;
    }
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}