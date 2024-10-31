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
typedef priority_queue<int, vector<int>, greater<int>> iheap;
const int N = 1e5 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int n;
iheap h;

void solved() {
	/* your code */
	std::cin >> n;
	while(n --) {
		int a;
		std::cin >> a;
		h.push(a);
	}
	int res = 0;
	while(h.size() > 1) {
		int a = h.top(); h.pop();
		int b = h.top(); h.pop();
		res += a + b;
		h.push(a + b);
	}
	std::cout << res << std::endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}