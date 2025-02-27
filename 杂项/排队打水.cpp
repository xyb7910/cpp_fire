/*
* @Author: Yanpb
* @Date:   2025-02-23 18:46:18
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-02-23 18:51:04
*/
#include <iostream>
#include <cstring>
#include <algorithm>

#define x first
#define y second

using namespace std;
const int N = 1010;

typedef pair<int, int> PII;
int n;
double res;
PII a[N];

int main() {
	cin >> n;
	for (int i = 0; i < n; i ++) {
		cin >> a[i].x;
		a[i].y = i + 1;
	}
	sort(a, a + n);
	for (int i = 0; i < n; i ++) {
		res += a[i].x * (n - i - 1);
		cout << a[i].y << " ";
	}
	printf("\n%.2lf", res / n);
	return 0;
}