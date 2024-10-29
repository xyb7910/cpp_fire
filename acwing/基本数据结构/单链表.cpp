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

int head, e[N], ne[N], idx;

// 初始化
void init() {
	head = -1;
	idx = 0;
}

// 在头部插入
void insert_to_head(int x) {
	e[idx] = x;
	ne[idx] = head;
	head = idx;
	idx ++;
}

// 在第 k 个位置之后插入一个元素
void insert(int k, int x) {
	e[idx] = x;
	ne[idx] = ne[k];
	ne[k] = idx;
	idx ++;
}

// 删除第 k 个位置之后的元素
void remove1(int k) {
	ne[k] = ne[ne[k]];
}

void solved() {
	/* your code */
	int M;
	std::cin >> M;
	init();
	while(M --) {
		char op;
		std::cin >> op;
		if(op == 'H') {
			int num;
			std::cin >> num;
			insert_to_head(num);
		}
		if(op == 'I') {
			int k, num;
			std::cin >> k >> num;
			insert(k - 1, num);
		}
		if(op == 'D') {
			int k;
			std::cin >> k;
			if(!k) head = ne[head];
			else remove1(k - 1);
		}
	}
	for (int i = head; i != -1; i = ne[i]) std::cout << e[i] << " ";
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}