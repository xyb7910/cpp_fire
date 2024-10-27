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


void solved() {
	/* your code */
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> v(1010);
	while(n --) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
	}
	int m;
	std::cin >> m;
	while(m --) {
		int a;
		std::cin >> a;
		int n = v[a].size();
		if(!n) cout << endl;
		else {
			if(n % 2 == 0) cout << v[a][n / 2 - 1] << " " << v[a][n / 2 ] << endl;
			else cout << v[a][n / 2] << endl;
		}
	}
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}