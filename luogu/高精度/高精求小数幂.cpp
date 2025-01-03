/*
* @Author: Yanpb
* @Date:   2025-01-02 16:20:02
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-03 15:08:22
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

string a;
int A[N], B[N], ans[N];
int b, l, len;

void solved() {
	/* your code */
	// while(cin >> a >> b) {
		cin >> a >> b;
		if(b == 1) {
			cout << a;
			return ;
		}

		int n = a.size(), pos = a.find('.');
		for (int i = n - 1; i >= 0; i --) {
			if(a[i] == '.') continue;
			A[l ++] = a[i] - '0';
		}

		for (int i = 0; i < l; i ++) B[i] = A[i];
		int la = l;
		for (int k = 1; k < b; k ++) {
			
			for (int i = 0; i < la; i ++)
				for (int j = 0; j < l; j ++)
					ans[i + j] += A[i] * B[j];
			
			len = l * (k + 1), l = len;
			for (int i = 0; i < len; i ++) {	
				ans[i + 1] += ans[i] / 10;
				ans[i] %= 10;
			} 
			while(ans[len] == 0 && len > 0) len --;

			for (int i = 0; i <= len; i ++) B[i] = ans[i];
		}

		for (int i = len, cnt = 1; i >= 0; i --, cnt ++) {
			if(cnt == (n - pos - 1) * 2 - 1) cout << ".";
			cout << ans[i];
		}
		cout << endl;

	// }
	
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}