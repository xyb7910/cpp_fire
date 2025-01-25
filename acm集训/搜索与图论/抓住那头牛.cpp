/*
* @Author: Yanpb
* @Date:   2025-01-25 14:54:45
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-25 15:08:04
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
/*
一维： BFS
*/
const int N = 1e5 + 10;
int n, k;
int dist[N];
int q[N];

int bfs(int start) {
    int hh = 0, tt = 0;
    memset(dist, -1, sizeof dist);
    
    q[0] = start;
    dist[start] = 0;
    
    while(hh <= tt) {
        int t = q[hh ++];
        if(t == k) return dist[t];
        if(t - 1 >= 0 && dist[t - 1] == -1) {
            q[++ tt] = t - 1;
            dist[t - 1] = dist[t] + 1;
        }
        if(t + 1 < N && dist[t + 1] == -1) {
            q[++ tt] = t + 1;
            dist[t + 1] = dist[t] + 1;
        }
        if(t * 2 < N && dist[t * 2] == -1) {
            q[++ tt] = 2 * t;
            dist[2 * t] = dist[t] + 1;
        }
    }
    return -1;
}

int main() {
    cin >> n >> k;
    cout << bfs(n);
    return 0;
}