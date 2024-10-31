#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,d;
int sum = 0;
char a[1005][1005];
int main()
{
    int T;
    cin>>T;
    while(T--){
    	sum = 0;
    	cin>>n>>m>>k;
    	cin>>x>>y>>d;
    	for(int i = 1;i<=n;i++){
    		for(int j = 1;j<=m;j++){
    			cin>>a[i][j];
			}
		}
		for(int i = 1;i<=n;i++){
			a[i][0] = 'x';
		}
		for(int i = 0;i<=m+1;i++){
			a[0][i] = 'x';
		}
		for(int i = 0;i<=m+1;i++){
			a[n+1][i] = 'x';
		}
		for(int i = 1;i<=n;i++){
			a[i][m+1] = 'x';
		}
		a[x][y] = '-';
		for(int i = 0;i<k;i++){
			if(d==0&&a[x][y+1]!='x'){
				if(a[x][y+1]=='.'){
					sum++;
					a[x][y+1] = '-';
				}
				y = y+1;
			}else if(d==1&&a[x+1][y]!='x'){
				if(a[x+1][y]=='.'){
					sum++;
					a[x+1][y] = '-';
				}
				x = x+1;
			}else if(d==2&&a[x][y-1]!='x'){
				if(a[x][y-1]=='.'){
					sum++;
					a[x][y-1] = '-';
				}
				y = y-1;
			}else if(d==3&&a[x-1][y]!='x'){
				if(a[x-1][y]=='.'){
					sum++;
					a[x-1][y] = '-';
				}
				x = x-1;
			}else if(d==0&&a[x][y+1]=='x'){
				d = d+1;
			}else if(d==1&&a[x+1][y]=='x'){
				d = d+1;
			}else if(d==2&&a[x][y-1]=='x'){
				d = d+1;
			}else if(d==3&&a[x-1][y]=='x'){
				d = 0;
			}	
		}
		cout<<sum+1<<endl;
	}
    return 0;
}