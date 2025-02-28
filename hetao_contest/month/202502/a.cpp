/*
* @Author: Yanpb
* @Date:   2025-02-28 13:03:45
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-02-28 15:00:36
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;
typedef long long i64;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int N = 1e5 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

char x, z;
i64 y, w;
bool f;
i64 cnt;
void solved() {
	/* your code */
	cin >> x >> y >> z >> w;
	if(x >= 'a' && x <= 'z' && z >= 'a' && z <= 'z' 
		&& x == z) f = 1;
	
	if(f && y<= w) cnt = w - y + 1;
	if(f && y > w)cnt =  y - w + 1;
	
	if(f)  {
		cout << "valid" << endl << cnt;
	}
	else{
		cout << "Invalid" << endl << -1;
	} 
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}