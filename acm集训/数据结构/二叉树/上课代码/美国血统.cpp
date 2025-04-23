/*
* @Author: Yanpb
* @Date:   2025-04-23 10:57:09
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-23 10:57:48
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

void dfs(string a,string b)
{
    if(a.size()==0) return ;
    int t=b.find(a[0]); //左子树节点个数
    dfs(a.substr(1,t),b.substr(0,t));//左子树
    dfs(a.substr(t+1),b.substr(t+1)); //右子树
    cout<<a[0];//当前树的根节点

}
int main()
{
    string a,b;
    cin>>b>>a;
    dfs(a,b);
    return 0;
}