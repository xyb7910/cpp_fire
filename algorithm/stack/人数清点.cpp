#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;
typedef long long LL;
LL tt, n, ans;
int s[N], a[N];
// 将数组下表入栈
int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i];

	for (int i = 1; i <= n; i ++) {
		// 如果栈顶的元素小于当前位置的元素则进行出栈
		while(tt && a[s[tt]] <= a[i]) {
			// 取出栈顶元素
			int x = s[tt];
			// 计算距离
			ans += i - x - 1;
			// 出栈
			tt --;
		}
		// 栈顶的元素大于当前元素的时候直接入栈
		s[++ tt] = i;
	}
	cout << ans + 1 << endl;
	return 0;
}