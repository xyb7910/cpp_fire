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

int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

// 首先想一下相反的操作怎么存储，这里使用一个 string 数组存储，怎么去相反操作呢？
// （i + 2） % 4 即可，环形才做最常用
string dir[4] = {"forward", "right", "backward", "left"};
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};

// 如何将 dir 数组与 4联通量结合起来，是巧妙所在，在数组存储的时候采用 前右后左 的方向存储
void solved() {
	/* your code */
	LL n, x, y;
	cin >> n >> x >> y;
	while(n --) {
		int op;
		string st, direction;
		cin >> op >> st >> direction;
		// 查询一下下标，为之后去相反操作提供便利
		int d = find(dir, dir + 5, direction) - dir;
		if(op == 0) {
			cout << st << " " << dir[d] << endl;
			x += dx4[d], y += dy4[d]; 
		}
		if(op == 1) {
			cout << st << " " << dir[d] << endl;
			x += dx4[(d + 2) % 4], y += dy4[(d + 2) % 4];  
		}
		if(op == 2) {
			cout << st << " " << dir[(d + 2) % 4] << endl;
			x += dx4[(d + 2) % 4], y += dy4[(d + 2) % 4]; 
		}
		if(op == 3) {
			cout << st << " " << dir[(d + 2) % 4] << endl;
			x += dx4[d], y += dy4[d]; 
		}
	}
	cout << x << " " << y << endl;

}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}