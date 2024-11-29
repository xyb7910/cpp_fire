#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;

const int N = 3e3+10;

struct E{
    int x,y,step;
}pre[N][N];
char w[N][N];
int T,n,m;
bool st[N][N];
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
char op[]={'R','D','L','U'};
bool f;

void print(int x,int y){
    if(x==1&&y==1)return;
    int a=pre[x][y].x,b=pre[x][y].y;
    print(a,b);
    if(a-x==-1) putchar('D');
    if(a-x==1)  putchar('U');
    if(b-y==-1) putchar('R');
    if(b-y==1)  putchar('L');
}

void bfs(){
    queue<E>q;
    
    st[1][1]=true;
        
    q.push({1,1,0});
    
    while(q.size()){
        E t=q.front();
        q.pop();
        
        int x=t.x,y=t.y,step=t.step;

        if(x==n&&y==m){
            f=true;
            cout<<step<<endl;
            print(n,m);
            cout<<endl;
            return;
        }
        
        for(int i=0;i<4;i++){
            int a=dx[i]+x,b=dy[i]+y;
            if(a<1||b<1||a>n||b>m||st[a][b])continue;
            if(w[x][y]=='1'&&w[a][b]=='1')continue;
            if(w[x][y]=='0'&&w[a][b]=='0')continue;
            // cout<<x<<" "<<y<<' '<<"->"<<a<<" "<<b<<" "<<isone<<" "<<op[i]<<endl;
            q.push({a,b,step+1});
            st[a][b]=true;
            pre[a][b]={x,y};
            // pre[step+1]=op[i];
            // cout<<op[i]<<" "<<step+1<<endl;
            // cout<<pre[step+1]<<" ";
        }
    }
}

int main(){
    scanf("%d",&T);
    
    while(T--){
        f=false;
        scanf("%d%d",&n,&m);
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>w[i][j];
                st[i][j]=0;
            }
        }
        
        bfs();
        
        if(!f){
            puts("-1");
        }
    }
    
    return 0;
}
