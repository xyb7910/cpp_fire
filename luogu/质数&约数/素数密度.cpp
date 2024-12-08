#include<bits/stdc++.h>
using namespace std;
bool f[100005];
int prime[10000],tot;
bool flag[1000005];
void Euler(int n)
{
     f[0]=f[1]=true;
        for(int i=2;i<=n;i++)
        {
            if(!f[i])
            {
                prime[++tot]=i;
            }
            for(int j=1;j<=tot&&1ll*i*prime[j]<=n;j++)
            {
                f[i*prime[j]]=true;
                if(i%prime[j]==0)break;
            }
        }
}
int main()
{
    Euler(100000);
    long long l,r;
    cin>>l>>r;
    for(long long i=1;i<=tot&&prime[i]*prime[i]<=r;i++){
        long long L=(l+prime[i]-1)/prime[i]*prime[i];
        L=max(2ll*prime[i],L);
        for(long long j=L;j<=r;j+=prime[i]){
            flag[j-1]=true;
        }
    }
    int cnt=0;
    for(long long i=max(2ll,l);i<=r;i++){
        if(!flag[i-l]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}