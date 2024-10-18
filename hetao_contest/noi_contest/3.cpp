#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
const int N = 100;
typedef long long LL;
int r, c, x, y;
char m[N][N];

int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> r >> c >> x >> y;
	for (int i = 0; i < r; i ++)
		for (int j = 0; j < c; j ++)
			cin >> m[i][j];

	for (int i = 0; i < r; i ++) {
		for (int l = 0; l < x; l ++) {
			for (int j = 0; j < c; j ++) {
					for (int k = 0; k < y; k ++) {
					cout << m[i][j];
					}
				}
				cout << endl;
			}
		}
			
	

	return 0;
}