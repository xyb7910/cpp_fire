#include<bits/stdc++.h>
using namespace std;
int n,m,x=1,lr,s;
struct node{
    int f;
    string name;
}a[100010];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i].f>>a[i].name;
    while(m--){
        cin>>lr>>s;
        //00 11 顺 01 10 逆
        x=(a[x].f==lr)?(x-s<=0?x-s+n:x-s):(x=((x+s-1)%n)+1);
    }
    cout<<a[x].name;
    return 0;
}