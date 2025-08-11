/*
* @Author: Yanpb
* @Date:   2025-06-30 12:18:55
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-06-30 13:17:55
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
struct Pos{
    int x, cos;
    Pos(int p=0, int c=0) {
        x = p, cos = c;
    }
};
int vis[N], n;
void bfs() {
    
    queue<Pos> q;
    q.push(Pos(1, 0));

    while(!q.empty()) {
        Pos now = q.front();
        q.pop();
        int x = now.x, c = now.cos;
        if(x < 1 || x > n) continue;
        if(vis[x]) continue;
        vis[x] = 1;
        if(x == n) {
            printf("%d", c);
            return ;
        }
        q.push(Pos(x - 1, c + 1));
        q.push(Pos(x + 1, c + 1));
        q.push(Pos(2 * x, c + 1));
    }
}
int main() {
    scanf("%d", &n);
    bfs();
    return 0;
} 