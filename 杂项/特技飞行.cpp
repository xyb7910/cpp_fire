/*
* @Author: Yanpb
* @Date:   2025-06-09 19:11:55
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-06-09 19:40:03
*/
#include <bits/stdc++.h>
using namespace std;
/*
价值总和sum = ${C_i}$ * (最迟的动作时间 - 上一次动作时间) 
*/
const int N = 1e3 + 10;
int c[N];
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; i ++)
		scanf("%d", &c[i]);
	sort(c, c + k, greater<int>());
	int sum = 0;
	for (int i = 0, t = n - 1; i < k && t > 0; i ++, t -= 2)
		sum += t * c[i];
	printf("%d", sum);
	return 0;
}