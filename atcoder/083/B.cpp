#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;
typedef long long LL;
int n, a, b;
int sum;

int count_sum(int k) {
	int sum = 0;
	while(k) {
		int s = k % 10;
		sum += s;
		k /= 10;
	}
	return sum;
}

int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> a >> b;
	for (int  i = 0; i <= n; i ++) {
		if(count_sum(i) >= a && count_sum(i) <= b) {
			sum += i;
		}
	}
	cout << sum;
	return 0;
}