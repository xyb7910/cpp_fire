		#include<bits/stdc++.h>
		using namespace std;
		const int N = 1e5 + 2, L = 1e6 + 2;
		int t, n, m, l, V, tmp, ans1, ans2;
		int d[N], v[N], a[N], p[N];
		int lft[L], rgt[L]; 
		int ld[N], rd[N]; 
		int g[N]; 
		int id; 
		bool cmp(int x, int y) {
			return rd[x] < rd[y];
		}
		void solve() {
			ans1 = ans2 = 0, id = -1;
			cin >> n >> m >> l >> V;
			for (int i = 1; i <= n; ++i)
				cin >> d[i] >> v[i] >> a[i];
			for (int i = 1; i <= m; ++i) {
				cin >> p[i];
				lft[p[i]] = rgt[p[i]] = i;  
			}
		 
			p[0] = 0, p[m + 1] = l + 1;
			for (int i = 0; i <= m; ++i)
				for (int j = p[i] + 1; j < p[i + 1]; ++j)
					lft[j] = i, rgt[j] = i + 1;
			for (int i = 1; i <= n; ++i) {
				if (d[i] > p[m]) continue; 
				if (a[i] == 0) {
					if (v[i] > V) {
						g[++ans1] = i;
						ld[i] = rgt[d[i]];
						rd[i] = m;
					} 
				} else if (a[i] > 0) {
					if (v[i] > V) {
						g[++ans1] = i;
						ld[i] = rgt[d[i]];
						rd[i] = m;
					} 
					else {
						tmp = V * V - v[i] * v[i];
						if (tmp % (2 * a[i]) == 0) {
							tmp = d[i] + tmp / (2 * a[i]); 
							if (tmp < p[m]) {
								g[++ans1] = i;
								ld[i] = rgt[tmp + 1];
								rd[i] = m;
							} 
						} else {
							tmp = d[i] + tmp / (2 * a[i]) + 1;
							if (tmp <= p[m]) {
								g[++ans1] = i;
								ld[i] = rgt[tmp];
								rd[i] = m;
							}
						}
					} 
				} else {
					if (v[i] > V) {
						tmp = v[i] * v[i] - V * V;
						if (tmp % (-2 * a[i]) == 0) {
							tmp = d[i] + tmp / (-2 * a[i]);
							if (tmp > p[m]) {
								g[++ans1] = i;
								ld[i] = rgt[d[i]];
								rd[i] = m;
							} else {
								ld[i] = rgt[d[i]];
								rd[i] = lft[tmp - 1];
								if (rd[i] >= ld[i]) g[++ans1] = i;
							}
						} else {
							tmp = d[i] + tmp / (-2 * a[i]);
							if (tmp >= p[m]) {
								g[++ans1] = i;
								ld[i] = rgt[d[i]];
								rd[i] = m;
							} else {
								ld[i] = rgt[d[i]];
								rd[i] = lft[tmp];
								if (rd[i] >= ld[i]) g[++ans1] = i;
							}
						}
					}  
				}
			}
		 
			sort(g + 1, g + 1 + ans1, cmp);
			for (int i = 1; i <= ans1; ++i)
				if (ld[g[i]] > id) {
					id = rd[g[i]];
					++ans2;
				}  
			cout << ans1 << " " << m - ans2 << endl;
		}
		int main() {
			cin >> t;
			while (t--) solve();
			return 0;
		}