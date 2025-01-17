/*
* @Author: Yanpb
* @Date:   2025-01-17 17:08:31
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-17 18:22:25
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

/*
一定保证已经染成黑色的点的左上角没有白色的点。

首先，所有节点先进行排序。
接着，依次检测每个黑色节点的左上方有没有白色节点即可。
*/

struct Point {
	int row, col;
	bool black;
};


bool operator<(Point p1, Point p2) {
	// 当行相同的时候，按照纵坐标由小到大排序
	return p1.row != p2.row ? p1.row < p2.row : p1.col < p2.col;
}

vector<Point> ps;

int main(int argc, char const *argv[])
{
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; ++ i) {
		int row, col; char color;
		cin >> row >> col >> color;
		ps.push_back(Point{row, col, color == 'B'}); 
	}
	sort(ps.begin(), ps.end());
	// 最小的白色节点的纵坐标
	int min_white_col = n + 1;
	for (auto p : ps) {
		if(p.black) {
			if(p.col >= min_white_col) {
				puts("No");
				return 0;
			}
		} else {
			min_white_col = min(min_white_col, p.col);
		}
	}
	puts("Yes");
	return 0;
}

