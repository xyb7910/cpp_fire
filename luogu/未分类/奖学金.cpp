#include <bits/stdc++.h>
using namespace std;
struct stu{
	int id;
	int yuwen;
	int shuxue;
	int yingyu;
	int zongfen;
}a[303];
int cmp(stu x,stu y)
{
	if(x.zongfen!=y.zongfen)
		return x.zongfen>y.zongfen;
	else if(x.yuwen!=y.yuwen)
		return x.yuwen>y.yuwen;
	else
		return x.id<y.id;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].yuwen>>a[i].shuxue>>a[i].yingyu;
		a[i].id=i+1;
		a[i].zongfen=a[i].yuwen+a[i].shuxue+a[i].yingyu;
		
	}
	sort(a,a+n,cmp);
	for(int i=0;i<5;i++)
	{
		cout<<a[i].id<<" "<<a[i].zongfen<<endl;
	}
	return 0;
}

