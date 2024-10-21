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
const int N = 2e5 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int N;
	std::cin >> N;
	std::vector<int> a(N, 0), b(N - 1, 0);
	for (auto& i : a) std::cin >> i;
	for (auto& i : b) std::cin >> i;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());


	// 如果存在 a[i] > b[i]，则直接返回即可
	for (int i = 0; i < N - 1; i ++) {
		if(a[i] > b[i]) {
			std::cout << -1 << std::endl;
			return 0;
		}
	}

	for (int i = N - 2; i >= 0; i --) {
		if(a[i + 1] > b[i]) {
			std::cout << a[i + 1] << std::endl;
			return 0;
		}
	}

	std::cout << a[0] << std::endl;
    return 0;
}