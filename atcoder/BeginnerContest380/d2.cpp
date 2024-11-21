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


/*
a
aA
aAAa
aAAaAaaA
aAAaAaaAAaaAaAAa
*/
typedef long long LL;
char change(char ch) {
    return ch >= 'a' ? (ch - 32) : (ch + 32);
}

void solved() {
	/* your code */
	string s;
	int q;
	cin >> s >> q;
	int n = s.size();
	while(q --) {
		LL num;
		cin >> num;
		// 首先找一下在第几个串中
		LL block = num / s.size();
		if(num % n) block += 1;
		block -= 1;
		// 二进制中 1 的个数
		int cnt = 0;
		while(block) {
			if(block & 1) cnt ^= 1;
			block >>= 1;
		}
		// 接着判断输出的字符在串中的第几个位置
		int pos = (num - 1 + n) % n;
		if(cnt) cout << change(s[pos]) << " ";
		else cout << s[pos] << " ";
	}
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}