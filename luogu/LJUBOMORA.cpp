#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
 
const int N=3e5+10;
 
ll a[N];
ll n;
int m;
 
bool check(int mid)
{
	ll sum=0;
	for(int i=0;i<m;i++)
	{
		if(a[i]%mid==0) sum+=a[i]/mid;
		else sum+=(a[i]/mid+1);
	}
	return sum<=n;
}
 
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
 
	cin>>n>>m;
	for(int i=0;i<m;i++) cin>>a[i];
	ll l=0,r=0;
	for(int i=0;i<m;i++)
	{
		r=max(r,a[i]);
	}
	while(l<r)
	{
		ll mid=(l+r)/2;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	cout<<l<<'\n';
}