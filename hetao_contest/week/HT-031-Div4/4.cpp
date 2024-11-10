#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

#define x first
#define y second

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int N = 1e5 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

LL ans;
void solved() {
	/* your code */
	LL num, p, q;
	cin >> num >> p >> q;
	// 切割数字，从个位数字开始，到只剩下最后一位数字即可
	LL back_up = num, pos = 1; // 对 back_up 进行操作， pos表示位数
	LL num1 = num, num2 = 0;
	while(back_up > 9) {
		num2 += (back_up % 10) * pos;
		num1 = back_up / 10;
		if(num1 % p == 0 && num2 % q == 0) ans ++;
		back_up /= 10;
		pos *= 10;
	}
	cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}