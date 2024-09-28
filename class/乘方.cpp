#include<bits/stdc++.h>
using namespace std;
int a,b;
int main(){
	cin>>a>>b;
	long long ans=1;
	if(a==1){
		cout<<1;
		return 0;
	}
	if (b==1) {
		cout<<a;
		return 0;
	}
	while(b&&ans<=1e9){
		ans*=a;
		b--;
	}
	if(ans>1e9){
		cout<<-1;
		return 0;
	}
	cout<<ans;
	return 0;
}