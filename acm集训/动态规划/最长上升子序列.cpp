/*
* @Author: Yanpb
* @Date:   2025-04-20 16:47:19
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-20 17:03:36
*/
#include <iostream>
using namespace std;

/*
f[i]:表示以 第i个数字 为结尾的最长上升子序列的长度

注意： f[n] 不是最终答案。
不是的，因为最后一个数字不一定是最长上升子序列的数字
因此，最终的答案要找 f[n] 数组的最大值。
*/
const int N = 6010;
int a[N], f[N];

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	int ans = 0;
	for (int i = 1; i <= n; i ++) {
		f[i] = 1;
		for (int j = 1; j < i; j ++)
			if(a[j] < a[i])
				f[i] = max(f[i], f[j] + 1);
		ans = max(ans, f[i]);
	}	
	cout << ans;
	return 0;
}