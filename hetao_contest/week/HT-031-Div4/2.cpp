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
// 这道题 k > 1 少了不少情况的考虑
// 情况1： 0 <= L < R; 总个数等于 R / K - L / R，向下取整
// 情况2： L < 0 < R; 总个数等于 R / K - L / R，向下取整
// 情况3： L < R <= 0; 总个数等于 R / K - L / R，向下取整
void solved() {
	/* your code */
	double L, R, K;
	cin >> L >> R >> K;
	// 因为 c++ 编译编译器默认向0取整，我们这里一定要向下取整（只有负数才考虑）
	cout << floor(R / K) - floor((L - 1) / K) << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}