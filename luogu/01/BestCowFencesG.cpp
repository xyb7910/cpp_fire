#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;
double sum[N];

int main() {
	int n, l;
	cin >> n >> l;
	for (int i = 1; i <= n; i ++) {
		int num;
		cin >> num;
		sum[i] = num;
		sum[i] += sum[i - 1];
	}
	double avg = 0;
	for (int i = l; i <= n; i ++) { // 枚举长度
		for (int j = 1; j <= n - i + 1; j ++) { // 起点
			double res = sum[j + i - 1] - sum[j - 1];
			avg = max(avg, (res / i * 1000));
		}
	}
	cout << avg << endl;
	return 0;
}