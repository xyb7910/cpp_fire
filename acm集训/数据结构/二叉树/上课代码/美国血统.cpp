/*
* @Author: Yanpb
* @Date:   2025-04-23 10:57:09
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-23 20:55:26
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

// 因为树是一种递归结构，所以常递归处理左子树 or 有子树
// dfs 函数的功能可以理解为 找根 输出根
// 第一个参数为 后序子串，第二个参数为 中序子串
void dfs(string a, string b)
{
    if(!a.size()) return ;
    int t = b.find(a[0]); //左子树节点个数
    dfs(a.substr(1, t), b.substr(0, t));//左子树
    dfs(a.substr(t + 1), b.substr(t + 1)); //右子树
    cout << a[0];//当前树的根节点
}

int main()
{
    // 先输入中序，在输出前序，让输出后序
    string a, b;
    cin >> b >> a;
    dfs(a, b);
    return 0;
}