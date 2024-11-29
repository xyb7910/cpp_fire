#include<iostream>

using namespace std;

int ax, ay;
int bx, by;
int num = 0;											 
int n, m, t;
int a[6][6] = { 0 };									

int H[4] = { 0, 1, 0, -1 };
int V[4] = { 1, 0, -1, 0 };

void dfs(int x, int y)
{
	if (x == bx && y == by && a[x][y] == 0)		 
	{
		num++;
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			if (x >= 1 && x <= m && y >= 1 && y <= n && a[x][y] == 0)		
			{
				a[x][y] = 2;											 
				dfs(x + H[i], y + V[i]);
				a[x][y] = 0;											 
			}
		}
	}
}

int main()
{
	int block_x, block_y;
	cin >> n >> m >> t;
	cin >> ax >> ay >> bx >> by;
	for (int i = 0; i < t; i++)
	{
		cin >> block_x >> block_y;
		a[block_x][block_y] = 1;
	}
	dfs(ax, ay);
	cout << num << endl;
	return 0;
}