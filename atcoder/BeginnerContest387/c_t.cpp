/*
* @Author: Yanpb
* @Date:   2025-01-17 21:03:39
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-18 09:50:39
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

/*
题意：有一个 H 乘 W 的棋盘格，每个格子上要么是空的，要么是障碍。给定一个起点和一个终点，问从起点到终点，最少需要走几步。走的时候，必须水平移动、垂直移动交替进行（必须：水平移动、垂直移动、水平移动、垂直移动，水平和垂直交替进行，第一次移动可以水平也可以垂直）。如果无解，输出 -1。

题解：
首先，如果忽略“水平移动、垂直移动交替进行”，可以使用最短路或宽度优先搜索。由于每次移动的代价都是 1，我们选择宽度优先搜索。

考虑加上“水平移动、垂直移动交替进行”应该怎么办：原先的 BFS 相当于在找：到达一个点所需要的最小步数；我们可以将其改成：到达一个点，且上一步是水平 / 垂直移动，所需要的最小步数，进行宽度优先搜索即可。
*/

#define MAXN 1024

int h, w;
bool is_obstacle[MAXN][MAXN];
int st_x, st_y, ed_x, ed_y;	// 起点和终点的坐标

struct State {
	int x, y;
	int last_dir;	// 0 是水平，1 是垂直
	int num_steps;
};

bool vis[MAXN][MAXN][2];


int bfs() {
	queue<State> q;
	q.push({st_x, st_y, 0, 0});
	q.push({st_x, st_y, 1, 0});
	vis[st_x][st_y][0] = true;
	vis[st_x][st_y][1] = true;
	while (!q.empty()) {
		State cur = q.front();
		q.pop();

		if (cur.x == ed_x && cur.y == ed_y) {
			return cur.num_steps;
		}

		for (int delta = -1; delta <= 1; delta += 2) {

			State new_state = cur;

			if (cur.last_dir == 0) {
				// 上一步是水平移动的
				// 现在应该垂直移动了
				new_state.x += delta;
			} else {
				// 上一步是垂直移动
				// 现在应该就是水平移动
				new_state.y += delta;
			}


			new_state.last_dir ^= 1;
			
			new_state.num_steps += 1;

			if (new_state.x < 1 || new_state.x > h ||
				new_state.y < 1 || new_state.y > w)
				continue;
			if (is_obstacle[new_state.x][new_state.y])
				continue;
			if (vis[new_state.x][new_state.y][new_state.last_dir])
				continue;

			vis[new_state.x][new_state.y][new_state.last_dir] = true;
			q.push(new_state);
		}
	}
	// 不要忘了无解的情况
	return -1;
}

int main() {
	cin >> h >> w;
	for (int i = 1; i <= h; ++i) {
		string s;
		cin >> s;
		for (int j = 1; j <= w; ++j) {
			char c = s[j-1];
			if (c == 'S') {
				st_x = i; st_y = j;
			} else if (c == 'G') {
				ed_x = i; ed_y = j;
			} else if (c == '#') {
				is_obstacle[i][j] = true;
			}
		}
	}

	int ans = bfs();
	cout << ans << endl;

	return 0;
}