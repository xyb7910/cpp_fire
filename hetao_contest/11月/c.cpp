#include<bits/stdc++.h>
using namespace std;

int n;
int l, r; 
int ans = 0; 
vector<int> w; 


void dfs(int u, int sum)
{
    if (u == n)
    {
        if (sum >= l && sum <= r)
        {
            ans++;
        }
        return;
    }
   
    if (sum + w[u] <= r)   
    {
        dfs(u + 1, sum + w[u]);
    }
    dfs(u + 1, sum);
}

int main()
{
    cin >> n >> l >> r;
    w.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }

    dfs(0, 0); 
    cout << ans << endl; 

    return 0;
}
