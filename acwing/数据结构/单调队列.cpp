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
const int N = 1e6 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int q[N], a[N], n, k;

void solved() {
	/* your code */
	std::cin >> n >> k;
	for (int i = 0; i < n; i ++) std::cin >> a[i];

	int hh = 0, tt = -1;
	for (int i = 0; i < n; i ++) {
		if(hh <= tt && i - k + 1 > q[hh]) hh ++; 
		while(hh <= tt && a[q[tt]] >= a[i]) tt --;

		q[++ tt] = i;
		if (i >= k - 1) std::cout << a[q[hh]] << " ";
	}

	std::cout << endl;
	
	hh = 0, tt = -1;
	for (int i = 0; i < n; i ++) {
		if(hh <= tt && i - k + 1 > q[hh]) hh ++;
		while(hh <= tt && a[q[tt]] <= a[i]) tt --;

		q[++ tt] = i;
		if (i >= k - 1) std::cout << a[q[hh]] << " ";
	}
	std::cout << endl;	
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}