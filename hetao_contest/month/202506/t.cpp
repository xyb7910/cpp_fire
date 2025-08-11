/*
* @Author: Yanpb
* @Date:   2025-06-30 15:42:49
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-06-30 15:43:37
*/
#include <cstdio>
#include <cstdlib>
#include <queue>

using std::queue;

struct Place  
{
	int x,y,step,HP;
};

int n,m;
int square[10][10]={};  
int visited[10][10]={};  
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};

queue<Place> que;  

void BFS()  
{
	while(!que.empty())
	{
		int x=que.front().x,y=que.front().y,step=que.front().step,HP=que.front().HP;
		que.pop();
		if(square[x][y]==3)
		{
			printf("%d\n",step);  
			exit(0);
		}
		if(HP>1) 
		{
			for(int i=0;i<=3;++i)
			{
				int nx=x+dx[i],ny=y+dy[i];
				if(nx>=1 && nx<=n && ny>=1 && ny<=m)  
				{
					if(square[nx][ny]==1 || square[nx][ny]==3)  
					{
						if(visited[nx][ny]<HP-1)  
						{
							visited[nx][ny]=HP-1;
							que.push(Place{nx,ny,step+1,HP-1});  
						}
					}
					if(square[nx][ny]==4)  
					{
						if(!visited[nx][ny])  
						{
							visited[nx][ny]=1;
							que.push(Place{nx,ny,step+1,6});  
						}
					}
				}
			}
		}
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			scanf("%d",&square[i][j]);
			if(square[i][j]==2)
			{
				que.push(Place{i,j,0,6});  
			}
		}
	}
	BFS();
	puts("-1");  
	return 0;
}