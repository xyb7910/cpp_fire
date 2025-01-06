/*
* @Author: Yanpb
* @Date:   2025-01-03 00:47:05
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-06 19:07:06
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
typedef long long i64;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int N = 1e5 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

string a;
int A[N], C[N];
i64 b;

void solved() {
    /* your code */
    cin >> a >> b;
    int n = a.size();
    for (int i = 0; i < n; i ++) A[i] = a[i] - '0';

    i64 t = 0;
    for (int i = 0; i < n; i ++) {
        C[i] = (t * 10 + A[i]) / b;
        t = (t * 10 + A[i]) % b;
    }   

    int p = 0;
    while(C[p] == 0 && p < n - 1) p ++;
    for (int i = p; i < n; i ++) cout << C[i];
    cout << endl;
    cout << t;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}