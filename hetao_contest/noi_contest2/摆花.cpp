#include<iostream>  
using namespace std;  
int num[101];  
int n,m;  
int f[101][101];  
int dfs(int i,int m)  
{  
    if(f[i][m] > 0) return f[i][m];  
    if(m == 0) return 1;  
    if(i == 0 && m != 0) return 0;  
    for(int k = 0; k <= num[i]; k++)  
        if(m >= k)  
            f[i][m] = (f[i][m] + dfs(i-1,m-k))%1000007;   
    return f[i][m];  
}  
  
int main()  
{  
     cin >> n >> m;  
     for(int i = n; i >= 1; i--)  
         cin >> num[i];  
     cout<<dfs(n,m);  
     return 0;  
}