#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>

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


void simple(int n, int k) {
	std::vector<int> vist(n, 0);
	int now = -1;
	for (int i = 0; i < n; i ++) {
		int cnt = k;
		while(cnt --) {
			do {
				now = (now + 1) % n;
			} while(vist[now]);
		}
		std::cout << now + 1 << " ";
		vist[now] = 1;
	}
}

void line() {

}

void log() {

}

void solved() {
    /* your code */
    int n, k;
    std::cin >> n >> k;
    simple(n, k);
    // line(n, k);
    // log(n, k);
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}