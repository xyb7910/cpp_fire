/*
* @Author: Yanpb
* @Date:   2025-01-18 12:56:22
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-18 13:46:40
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
const int N = 1024;

int h, w;
int st_x, st_y, ed_x, ed_y;
bool is_obstacle[N][N];
bool vis[N][N][2];
struct State{
	int x, y;
	int num_steps, last_dir; // last_dir 为 1 表示竖直方向 0 表示水平方向
};

int bfs() {
	queue<State> q;
	q.push(State{st_x, st_y, 0, 0});
	q.push(State{st_x, st_y, 0, 1});
	vis[st_x][st_y][0] = 1;
	vis[st_x][st_y][1] = 1;
	// cout << q.size() << endl;
	while(q.size()) {
		State cur = q.front();
		q.pop();

		// cout << cur.x << " " << cur.y << " "<< cur.num_steps << " " << cur.last_dir << endl;
		
		if(cur.x == ed_x && cur.y == ed_y) return cur.num_steps;

		for(int delta = -1; delta <= 1; delta += 2) {

			State new_state = cur;
			// 上一次是竖直这一次就是水平
			// 上一次是水平这一次就是竖直
			if(cur.last_dir) {
				new_state.y += delta;
			} else {
				new_state.x += delta;
			}

			new_state.last_dir ^= 1;
			new_state.num_steps += 1;

			if(new_state.x < 1 ||new_state.x > h ||
				new_state.y < 1 || new_state.y > w) continue;
			if(is_obstacle[new_state.x][new_state.y]) continue;
			if(vis[new_state.x][new_state.y][new_state.last_dir]) continue;

			vis[new_state.x][new_state.y][new_state.last_dir] = true;

			q.push(new_state);

		}

	}
	return -1;

}

int main() {
	cin >> h >> w;
	for (int i = 1; i <= h; ++ i) {
		string s; cin >> s;
		for (int j = 1; j <= w; ++ j) {
			if(s[j - 1] == 'S') st_x = i, st_y = j;
			if(s[j - 1] == 'G') ed_x = i, ed_y = j;
			if(s[j - 1] == '#') is_obstacle[i][j] = true;
		}
	}
	// cout << st_x << " " << st_y << " " << ed_x << " " << ed_y << endl;
	int ans = bfs();
	cout << ans << endl;
	return 0;
}