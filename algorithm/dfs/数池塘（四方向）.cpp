#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
typedef long long LL;
int n, m;

void dfs(vector<vector<char>> &map, int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m || map[x][y] == '.') return ;
	map[x][y] = '.';
	dfs(map, x + 1, y);
    dfs(map, x - 1, y);
    dfs(map, x, y + 1);
    dfs(map, x, y - 1);
}

int countPonds(vector<vector<char>> &map) {
	int count = 0;
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			if(map[i][j] == 'W') {
				dfs(map, i, j);
				count ++;
			}
		}
	}
	return count;
}

int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	
	cin >> n >> m;
	std::vector<vector<char>> map(n, vector<char>(m));
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			cin >> map[i][j];
		}
	}
	cout << countPonds(map) << endl;
	return 0;
}