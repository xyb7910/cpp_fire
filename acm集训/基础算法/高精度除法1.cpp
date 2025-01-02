/*
* @Author: Yanpb
* @Date:   2024-12-30 20:21:23
* @Last Modified by:   Yanpb
* @Last Modified time: 2024-12-30 21:16:11
*/
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

int A[N], C[N];
string a;
LL b, t;

void solved() {
    /* your code */
    cin >> a >> b;
    int n = a.size();

    for (int i = 1; i <= n; i ++) A[i] = a[i - 1] - '0';

    for (int i = 1; i <= n; ++ i) {
    	C[i] = (t * 10 + A[i]) / b;
    	t = (t * 10 + A[i]) % b;
    }

    int p = 1;
    while(C[p] == 0 && p < n) p ++;
    for (int i = p; i <= n; ++ i) cout << C[i];
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}