#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;
const int N = 40;
LL c[N][N];

int n;
int main() {
	cin >> n;
	for (int i = 0; i <= n * 2; i ++) {
		for (int j = 0; j <= i; j ++) {
			if(!j) c[i][j] = 1;
			else c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
		}
	}
	cout << c[n * 2][n] / (n + 1) << endl;
	return 0;
}