#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
const int N = 1e5 + 10;
typedef long long LL;
LL a, b, c, d, vm;

int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> a >> b >> c >> d >> vm;
	// 先计算最快的到达时间
	LL t = ceil(d * 1.0 / vm);
	// 计算经过红绿灯轮数
	LL s = t / (a + b); // 必须向下取整
	// cout << t << " " << s << endl;
	// 判断是否在红灯前到达
	if (t % (a + b) < a) {
		t = s * (a + b) + a;
	}

	// 绿灯的时间不够
	else if (t % (a + b) > (a + b) - c) {
		t = (s + 1) * (a + b) + a;
	}

	// 紧接着计算速度就可以
	LL ans = ceil(d * 1.0 / t);
	cout << ans;
	return 0;
}