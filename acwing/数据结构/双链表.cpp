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
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int N = 1e5 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int e[N], l[N], r[N], idx;
void init() {
    r[0] = 1, l[1] = 0;
    idx = 2;
}

// 在节点k的右边插入一个数x
void insert(int k, int x)
{
    e[idx] = x;
    r[idx] = r[k];
    l[idx] = k;
    l[r[k]] = idx; 
    r[k] = idx;
    idx ++;
}

//删除节点k
void remove1(int k)
{
    l[r[k]] = l[k];
    r[l[k]] = r[k];
}

void solved() {
	/* your code */
    int M;
    std::cin >> M;
    init();
    while(M --) {
        std::string op;
        std::cin >> op;
        if (op == "L") {
            int x;
            std::cin >> x;
            insert(0, x);
        }
        if (op == "R") {
            int x;
            std::cin >> x;
            insert(l[1], x);
        }
        if (op == "D") {
            int k;
            std::cin >> k;
            remove1(k + 1);
        }
        if (op == "IL") {
            int k, x;
            std::cin >> k >> x;
            insert(l[k + 1], x);   
        }
        if (op == "IR") {
            int k, x;
            std::cin >> k >> x;
            insert(k + 1, x);
        }
    }
    for (int i = r[0]; i != 1; i = r[i]) cout << e[i] << " ";
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}