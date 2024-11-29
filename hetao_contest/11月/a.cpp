#include<bits/stdc++.h>
using namespace std;
queue<int> q;
int arr[1000010];
int main()
{
	memset(arr,-1,sizeof arr);
	int n;
	int m;
	arr[1]=0;
	cin>>n;
	q.push(1);
	while(!q.empty())
	{
		int f=q.front();
		m=arr[f];
		q.pop();
		int b1=f-1,b2=f+1,b3=f*2;
		if(b1>=1&&b1<=n&&arr[b1]==-1)	q.push(b1),arr[b1]=m+1;
		if(b2>=1&&b2<=n&&arr[b2]==-1)	q.push(b2),arr[b2]=m+1;
		if(b3>=1&&b3<=n&&arr[b3]==-1)	q.push(b3),arr[b3]=m+1;
      
	}
	cout<<arr[n]<<endl;
	return 0;
}