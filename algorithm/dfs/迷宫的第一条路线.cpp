// #include <iostream>
// #include <cstring>
// #include <algorithm>
// #include <vector>
// using namespace std;
// const int N = 30;
// typedef long long LL;
// typedef pair<int, int> PII;
// int n;
// vector<PII> res;

// void print_ans() {
// 	cout << "(" << res[0].first << "," << res[0].second << ")";
// 	for (int  i = 1; i < res.size(); i ++) {
// 		cout << "->" << "(" << res[i].first << "," << res[i].second << ")";
// 	}
// 	cout << "->" << "(" << n << "," << n << ")";
// }

// void dfs(vector<vector<int>> &map, int x, int y) {
// 	if(x == n && y == n) print_ans();
// 	if(x < 1 || x > n || y < 1 || y > n || map[x][y]) return ;
// 	map[x][y] = 1;
// 	res.push_back({x, y});
// 	dfs(map, x, y - 1);
// 	dfs(map, x - 1, y);
// 	dfs(map, x, y + 1);
// 	dfs(map, x + 1, y);
// }
// int main() {
// 	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
// 	cin >> n;
// 	std::vector<vector<int>> map(n + 1, vector<int>(n + 1));
// 	for (int i = 1; i <= n; i ++) {
// 		string s;
// 		cin >> s;
// 		for (int j = 1; j <= s.size(); j ++) {
// 			map[i][j] = s[j - 1] - '0';
// 		}
// 	}

// 	dfs(map, 1, 1);
// 	return 0;
// }


#include<bits/stdc++.h> // 包含C++常用库函数
using namespace std; // 使用std命名空间以简化代码

int n, // 迷宫的尺寸
    mg[30][30], // 用于存储迷宫地图，0表示可通过，1表示障碍
    bj[1000][1000]; // 记录搜索过程中的路径坐标

// 深度优先搜索函数
// 参数: x, y 当前坐标；k 走过的步数（也作为bj数组的索引）
int dfs(int x, int y, int k){
    // 判断当前位置是否合法或已被访问
    if(x < 1 || x > n || y < 1 || y > n || mg[x][y] != 0){
        return k; // 不合法或已访问过，返回当前步数
    }
    
    // 记录路径
    bj[k][1] = x;
    bj[k][2] = y;
    mg[x][y] = 1; // 标记当前格子已访问
    
    // 如果到达右下角，输出路径并结束
    if(x == n && y == n){
        for(int i = 1; i <= k; i++){
            cout << "(" << bj[i][1] << "," << bj[i][2] << ")";
            if(i != k){ // 非最后一项添加箭头
                cout << "->";
            }
        }
    }
    
    // 递归搜索四个方向
    dfs(x, y-1, k+1); // 左
    dfs(x-1, y, k+1); // 上
    dfs(x, y+1, k+1); // 右
    dfs(x+1, y, k+1); // 下
    
    // 注意：此函数设计上没有直接利用返回值，实际搜索中无需返回具体值
}

int main(){
    // 输入迷宫尺寸
    cin >> n; 
    
    // 输入并构建迷宫地图
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        for(int j = 1; j <= n; j++){
            mg[i][j] = s[j-1] - '0'; // 字符转数字，'0' ASCII值为48，因此减去'0'得到数字
        }
    }
    
    // 开始搜索
    dfs(1, 1, 1); // 从(1,1)开始搜索，初始步数为1
    
    return 0; // 程序正常结束
}

