#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

/*
1  
1 2 
1 2 3
*/

int main() {
	int n;
	cin >> n;	
	int sum = 0;
	// 方法一：
	// for (int i = 1; i <= n; i ++) {
	// 	for (int j = 1; j <= i; j ++) {
	// 		sum += j;
	// 	}
	// }
	// 方法二：
	int cnt = n;
	for (int i = 1, cnt = n; i <= n; i ++, cnt --) {
		sum += cnt * i;
	}
	cout << sum;

	return 0;
}