#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;
typedef long long LL;
int n, m, cnt;
int k, s;

struct msg {
	int id;
	int sc;
	bool operator<(const msg& t) {
		if(sc != t.sc) return sc > t.sc;
		return id < t.id;
	};
};
msg P[N];
int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for (int  i = 0; i < n; i ++) cin >> P[i].id >> P[i].sc;
	sort(P, P + n);

	// for (int  i = 0; i < n; i ++) cout <<  P[i].id <<" " << P[i].sc << endl;
	int score = P[m * 150 / 100 - 1].sc;
	cout << score << " ";
	for (int  i = 0; i < n; i ++) {
		if (P[i].sc >= score) cnt ++;
	}
	cout << cnt << endl;
	for (int i = 0; i < n; i ++) {
		if(P[i].sc >= score) cout << P[i].id << " " << P[i].sc << endl;
	}
	return 0;
}