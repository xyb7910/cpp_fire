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

// 方案数统计问题
// 解法一：
// 情况考虑：1、完全答对 2、完全打错 3、都跳过 4、中间穿插
// 所以全打错就是 -N 全答对就是 N 中间有一种全跳过 0 ==> 统计 [-N, N]多少个数字
// 扩展一：如果要我们打印出所有题的的的得分情况，枚举即可。
// 问题转换 ==> 排列问题：每个位置有三种情况 -1 0 1
void solved() {
	/* your code */
	LL n;
	cin >> n;
	cout << 2 * n + 1 << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}