/*
* @Author: Yanpb
* @Date:   2025-01-17 15:02:54
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-17 16:35:11
*/
#include <iostream>
#include <cmath>
using namespace std;
int nn;
int a[101],b[101];
double n;
int main()
{
    cin >> nn;
    for(int i=1;i<=nn;i++)
    {
        cin >> a[i];
    }
    n=nn;
    for(int i=ceil(n/2);i>=1;i--)
    {
        int k=ceil(n/2);
        b[(k-i+1)*2-1]=a[i];
    }
    for(int i=ceil(n/2)+1;i<=nn;i++)
    {
        int k=ceil(n/2);
        b[(i-k)*2]=a[i];
    }
    for(int i=1;i<=nn;i++)
    {
        cout << b[i] << " ";
    }
    return 0;
}