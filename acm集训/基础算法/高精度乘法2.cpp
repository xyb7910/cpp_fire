/*
* @Author: Yanpb
* @Date:   2024-12-30 11:21:09
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-06 16:33:58
*/
// 高精度 ✖️ 高精度

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

i64 A[N], B[N], C[N], l1, l2;

void solved() {
    /* your code */
    string a, b; cin >> a >> b;
    int n = a.size(), m = b.size();
    for (int i = n - 1; ~i; i --) A[l1 ++] = a[i] - '0';
    for (int i = m - 1; ~i; i --) B[l2 ++] = b[i] - '0';

    // 进行模拟乘法
    for (int i = 0; i < n; i ++)
    	for (int j = 0; j < m; j ++) {
    		int dis = i + j;
    		C[dis] += A[i] * B[j];
    	}

   
  	// 最大的可能位数为 n + m
    int l = n + m;
    for (int i = 0; i < l; i ++) {
        C[i + 1] += C[i] / 10;
        C[i] %= 10;
    }
    		
    // 寻找第一个非零元素	
    while(l > 1 && C[l - 1] == 0) l --;

    for (int i = l - 1; ~i; i --) cout << C[i];
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}