/*
* @Author: Yanpb
* @Date:   2025-04-05 14:41:28
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-16 11:06:52
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

#define x first
#define y second

using namespace std;
typedef long long i64;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int N = 1e5 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};


int n, p;
priority_queue<int> heap[10];

void solved() {
	/* your code */
    cin >> n >> p;
    int cnt = 0;
    for (int i = 0; i < n; i ++) {
        int id, pos; cin >> id >> pos;
        while(heap[id].size() && heap[id].top() > pos) {
            heap[id].pop(); 
            cnt ++;
        } 
        if(heap[id].size() == 0 || heap[id].top() != pos) {
            heap[id].push(pos); 
            cnt ++;
        } 
    }
    cout << cnt;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}