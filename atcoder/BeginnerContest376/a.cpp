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
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};
const int N = 1e5 + 10;

void solved() {
	/* your code */
	int N, C;
	std::cin >> N >> C;
	std::vector<int> v(N, 0);
	for (int i = 0; i < N; i ++) cin >> v[i];

	int sum = 1, start = v[0];
	for (int i = 1; i < N; i ++) {
		if (v[i] - start >= C) {
			sum ++;
			start = v[i];
		}
	}
	std::cout << sum << std::endl;
}

int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}