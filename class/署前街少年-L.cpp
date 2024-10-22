#include <iostream>
#include <algorithm>
#include <cstring>


using namespace std;

typedef long long ll;
const ll N=1e6+10;
ll a[N];
ll s[N];

int main()
{
    ll n,k;
    cin>>n>>k;
    
    for(ll i=1;i<=2*n;i++)
    {
        ll p;
        cin>>a[i];
        p=i%k;
        s[p]+=a[i];//相同象限的a[i]累加
    }

    for(ll i=1;i<=2*n;i++)
    {
        ll p;
        //奇位数
        if(i%2==1)
        {
            p=i%k;
            //a[i]:所有第 p 象限数的和对 i 取模的值
            a[i]=s[p]%i;
        }
        cout<<a[i]<<" ";
    }

    return 0;
}
