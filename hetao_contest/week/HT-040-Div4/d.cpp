#include <bits/stdc++.h>
using namespace std;
int a[7],cnt;
int main()
{
    for(int i=1;i<=6;i++)
    {
        cin>>a[i];
    }
    cnt+=a[6];
    cnt+=a[5];
    cnt+=a[4];
    cnt+=a[3]/4;        
    a[3]-=a[3]/4*4;
    a[1]-=a[5]*11;     

    a[2]-=a[4]*5;       
    if(a[2]<0)
    {
        a[1]-=(0-a[2])*4; 
        a[2]=0;
        
    }                    
    if(a[3]!=0)           
    {
        cnt++;
        int m=(3-a[3])*2+1;  
        if(a[2]<=m)
        {
            a[1]-=36-a[3]*9-a[2]*4;
            a[2]=0;
        }
        if(a[2]>m)
        {
            a[2]-=m;
            a[1]-=(m+1)/2+4;
        }
        
    }
    if(a[2]!=0)
    {
        int mm=(a[2]-1)/9+1;
        cnt+=mm;
        a[1]-=(mm*9-a[2])*4;
    }
    if(a[1]>0)
    {
        cnt+=(a[1]-1)/36+1;
    }    
    cout<<cnt;
    return 0;
}