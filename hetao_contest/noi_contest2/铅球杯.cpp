#include<bits/stdc++.h>
#include<cstring>
#include<queue>
#include<set>
#include<stack>
#include<vector>
#include<map>
#define ll long long
using namespace std;
const int N=1e5+10;
const int M=2023;
const int inf=0x3f3f3f3f;
int n,k,pp;
map<string,int> mp; 
string a;
string dfs(int pos,int end)
{
	string x;
	for(int i=pos+1;i<end;i++)
	{
		if(a[i]=='}')
		{
			pos=i;
			pp=i;
			return x;
		}
		x+=a[i];
	}
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		string x;
		int y;
		cin>>x>>y;
		mp[x]=y; 
	}
	for(int i=1;i<=k+1;i++)
	{
		getline(cin,a);
		if(i==1)continue;
		for(int j=0;j<a.size();j++)
		{
			if(a[j]=='{')
			{
				cout<<mp[dfs(j,a.size())];
				j=pp;
			}
			if(a[j]!='}')cout<<a[j]; 
			
		} 
		cout<<"\n";
	}
	return 0;
}