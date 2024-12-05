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

int n, m;
int p[N], cnt[N];
int find(int x) {
	return p[x] != x ? p[x] = find(p[x]) : p[x];
}

void solved() {
	/* your code */
	cin >> n >> m;  
	for (int i = 1; i <= n; i ++) p[i] = i, cnt[i] = 1;	

	while(m --) {
		string op;
		int a, b;
		cin >> op;
		if(op == "C") {
			cin >> a >> b;
			a = find(a);
			b = find(b);
			if(a != b) {
			   p[a] = b; // 将集合a添加到集合b中
			   cnt[b] += cnt[a]; // 更新一下集合b的大小 
			}
		} else if(op == "Q1") {
			cin >> a >> b;	
			cout << (find(a) == find(b) ? "Yes" : "No") << endl;
		} else if(op == "Q2") {
			cin >> a;
			cout << cnt[find(a)] << endl;
		}
	}
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}