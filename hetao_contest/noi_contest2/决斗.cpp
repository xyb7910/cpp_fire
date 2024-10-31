#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,r[200001] = {0},b[200001] = {0},a[200001] = {0},an; 
signed main(){
    cin.tie();
    cout.tie();
    cin>>n;
    for(int i = 1;i<=n;i++)cin>>r[i];
    for(int i = 1;i<=n;i++){
        b[r[i]]++;
    } 
    for(int i = 1;i<=150000;i++){
        if(b[i]!=0){
            a[++an] = i;
        }
    }
    int ans = 0,k = 0;
    for(int i = 1;i<=an;i++){
        k+=b[a[i]];
        if(b[a[i+1]]>k){
            ans+=k;
            k = 0;
        }else{
            k-=b[a[i+1]];
            ans+=b[a[i+1]];
        }
        
    }
    cout<<n-ans<<endl;
    return 0;
}