#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
const int Max = 200005;
int h[Max],a[Max];
int n,s,ll;
bool check(int mid)
{
	int ans = 0;
	for(register int i = 1;i <= n;++ i)
	{
		int qwq = h[i] + a[i] * mid;
		if(qwq < ll)continue;
		ans += qwq;	
		if(ans >= s)return true;
	}
	return false;
}

signed main()
{
	cin >> n >> s >> ll;
	for(register int i = 1;i <= n;++ i)
		cin >> h[i];
	for(register int i = 1;i <= n;++ i)
		cin >> a[i];
	int l = 0,r = max(s,ll);
	while(l < r)
	{
		int mid = (r + l) >> 1;
		if(check(mid))r = mid;
		else	l = mid + 1;
	}
	cout << l << endl;
	return 0;
}