#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int N=1e6+10;
int maxx1,maxx2;
int a[N],n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int nn=n;
	maxx1=a[n];
	while(a[n]==maxx1&&n>0) n--;
	maxx1=a[n];
	for(int i=n;i>=1;i--){
		if(a[i]!=maxx1) maxx2=a[i];
		if(maxx2!=0) break;
	}
	if(a[nn]%maxx1>maxx2) maxx2=a[nn]%maxx1;
	if(maxx1==0||maxx2==0) printf("-1");
	else printf("%d",maxx2);
	return 0;
}