/*
* @Author: Yanpb
* @Date:   2025-04-25 20:56:35
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-25 21:07:56
*/
#include <iostream>
using namespace std;
typedef long long LL;
const int N = 1e9;
int a, b;
int main() {
	cin >> a >> b;
	LL res = 1;
	for (int i = 1; i <= b; i ++) {
		res *= a;
		if(res > N) {
			puts("-1");
			return 0;
		}
	}
	cout << res;
	return 0;
}