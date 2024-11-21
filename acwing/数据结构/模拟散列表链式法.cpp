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

int n;
// 链式地址法
int h[N], e[N], ne[N], idx;

// 使用头插法
void insert(int x) {
	int t = (x % N + N) % N;
	e[idx] = x;
	ne[idx] = h[t];
	h[t] = idx;
	idx ++;
}

// 首先找出 x 在哈希表中的映射值
bool find(int x) {
	int t = (x % N + N) % N;
	for (int i = h[t]; i != -1; i = ne[i]) {
		int j = e[i];
		if(j == x) {
			return true;
		}
	}
	return false;
}

void solved() {
	/* your code */
	std::cin >> n;

	memset(h, -1, sizeof h);
	while(n --) {
		char op[2];
		std::cin >> op;
		int num;
		std::cin >> num;
		if(*op == 'I') {
			insert(num);
		} else {
			std::cout << (find(num) ? "Yes" : "No") << std::endl;
		}
	}
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}