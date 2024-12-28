/*
* @Author: Yanpb
* @Date:   2024-12-28 08:51:05
* @Last Modified by:   Yanpb
* @Last Modified time: 2024-12-28 08:56:38
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>

#define x first
#define y second

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int N = 1e5 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

std::vector<char> res(N);

void solved() {
    /* your code */
    int base; cin >> base;
    for (int i = 1; i <= 300; i ++) {
    	int num = i * i;
    	cout << num << endl;
    	bool f = 0;
    	while(num) {
    		int r = num % base;
    		if(r > 9) res.push_back(r - 10 + 'A');
    		else res.push_back(r + '0'); 
    		vector<char> back_up = res;
    		reverse(res.begin(), res.end());
    		if(res == back_up) f = 1;
    	}
    	if(f) cout << i << " " <<  i * i << endl;
    }
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}