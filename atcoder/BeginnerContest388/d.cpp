/*
* @Author: Yanpb
* @Date:   2025-01-19 09:22:45
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-19 11:33:17
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
 
/*
分析： 
	第i个位置的人可以给后面[i + 1, min(n ,i + a[i] + 1)] 
	个人提供石头。  
*/

const int N = 5e5 + 10;
int a[N], d[N];

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	int cur = 0;
	for (int i = 1; i <= n; i ++) {
		a[i] += (cur += d[i]);
		int l = i + 1, r = min(n, l + a[i]);
		a[i] -= r - l;
		d[l] ++, d[r + 1] --;
		cout << a[i] << " ";
	}
	return 0;	
}