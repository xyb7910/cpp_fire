#include<bits/stdc++.h>
using namespace std;
const int N=100005;
struct son{
   long long k;
   long long sum;
};
struct son s[N];
bool cmp(son x,son y){
    return x.sum > y.sum;//降序排序
}
int main()
{
   long long n,m,a,b;
   scanf("%lld%lld%lld%lld",&n,&m,&a,&b);
   memset(s,0,sizeof(s));
   for(long long i=1;i<=n;i++)
   s[i].k=i;
   long long favoritevalue=0,favoriteid=0;//定义学号为b的同学最喜欢的歌
   for(long long i=1;i<=a;i++)
   {
      for(long long j=1;j<=n;j++)
      {
         long long t;
         scanf("%lld",&t);
         s[j].sum+=t;//累加歌曲的欢喜度
         if(i==b&&t>favoritevalue){//学号为b的同学单独处理
            favoritevalue=t;
            favoriteid=j;
         }
      }
   }
   long long i,j; 
   sort(s + 1, s + n + 1, cmp);//降序排序
   int flag=0;
   for(i=1;i<=m;i++)
   {
      if(s[i].k==favoriteid) {
         flag=1;//flag=1表示b同学喜欢的歌出现在了榜单上,需要提前输出.
         printf("%lld ",favoriteid);
         s[i].k=-1;
         break;
      }
   }
   if(flag==1)
   {
      for(i=1;i<=m;i++)
      {
         if(s[i].k>0) printf("%lld ",s[i].k);
      }
   }
   else if(flag==0)//b同学喜欢的歌未出现在榜单,替换榜单最后一名的歌曲
   {
      for(i=1;i<m;i++)
      printf("%lld ",s[i].k);
      printf("%lld ",favoriteid);
   }
   return 0; 
}