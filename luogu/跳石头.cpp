#include<iostream>
using namespace std;
const int N = 50005;
int a[N];
int L, n, m;

int check(int k) 
{
    int now = 0; 
    int count = 0;
    for(int i=1;i<=n+1;i++)
    {
        if (a[i] - a[now] < k)  
            count++; 
        else 
            now = i;    
    }
    return count <= m;
}

int main()
{
    cin >> L >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    a[n+1] = L;
    int ans, b = 0, r = L;
    while (b <= r)
    {
        int mid = (b + r) / 2;
        if (check(mid))
        {
            ans = mid; 
            b = mid + 1; 
        }
        else 
            r = mid - 1; 
    } 
    cout << ans;
    return 0;
}