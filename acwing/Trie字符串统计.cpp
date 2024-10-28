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
int n;
int cnt[N], son[N][26], idx;
char op[2], s[N];
void insert(char str[]) {
	int p = 0;
	for (int i = 0; str[i]; i ++) {
		int u = str[i] - 'a';
		if(!son[p][u]) son[p][u] = ++ idx;
		p = son[p][u];
	}
	cnt[p] ++;
}

int query(char str[]) {
	int p = 0;
	for (int i = 0; str[i]; i ++) {
		int u = str[i] - 'a';
		if(!son[p][u]) return 0;
		else p = son[p][u];
	}
	return cnt[p];
}


void solved() {
    /* your code */
    int n;
    std::cin >> n;
    while(n --) {
    	std::cin >> op >> s;
    	if(op[0] == 'I') insert(s);
    	else cout << query(s) << endl;
    }
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}