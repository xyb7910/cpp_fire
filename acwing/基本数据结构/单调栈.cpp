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

int s[N], n, tt;

void solved() {
	/* your code */
	std::cin >> n;
	// 输出第 i 个数字左边第一个比他小的数字
	// 假如 i 号位置上元素的值 >= j 号位置上元素的值
	// 并且 位置 i 位于 位置 j 的前边， 那么 位置 i 上的元素一定不是想要的结果
	// 可以使用 单调栈的栈顶维护 当前元素 x 左边比他小的第一个元素 的 值
	for (int i = 0; i < n; i ++) {
		int x;
		std::cin >> x;
		while(tt && s[tt] >= x) tt --;
		if(tt) std::cout << s[tt] << " ";
		else std::cout << -1 << " ";

		s[++ tt] = x;
	}
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}