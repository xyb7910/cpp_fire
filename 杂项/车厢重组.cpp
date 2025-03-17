/*
* @Author: Yanpb
* @Date:   2025-03-17 20:42:10
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-03-17 20:43:46
*/
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
typedef long long i64;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int N = 1e5 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int n, cnt;
int a[N];
void solved() {
	/* your code */
	std::cin >> n;
	for (int i = 0; i < n; i ++) std::cin >> a[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j ++) {
			if(a[j] > a[i]) cnt ++;
		}
	}	
	std::cout << cnt;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}