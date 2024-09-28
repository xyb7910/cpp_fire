#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const double eps = 1e-5;
const int maxn = 1000005;
typedef double db;
int n;
double p, sum = 0;
db a[maxn], b[maxn];
bool check(db ans) {
	db maxx = p * ans;
	db real = 0.0;
	for(int i = 1; i <= n; i ++) {
		if(a[i] * ans <= b[i]) continue;
		real += a[i] * ans - b[i];
	} return real <= maxx;
}
int main() {
	cin >> n >> p;
	for(int i = 1; i <= n; i ++)  {
		cin >> a[i] >> b[i];
		sum += a[i];
	} if(sum <= p) return puts("-1") & 0;
	double l = 0.0, r = 1e10, mid;
	while(r - l > eps) {
		mid = (l + r) / 2;
		if(check(mid)) l = mid;
		else r = mid;
	} 
	printf("%.10lf", l);
}
