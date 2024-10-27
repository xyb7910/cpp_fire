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
int n;
struct Node{
	char value;
	int lc;
	int rc;
};
string Pre_ans, Mid_ans, Pos_ans;	
void Pre_order_traversal(const vector<Node>& nodes, int root, string& res) {
	if (!root) return ;
	res += nodes[root].value;
	Pre_order_traversal(nodes, nodes[root].lc, res);
	Pre_order_traversal(nodes, nodes[root].rc, res); 
}

void Mid_order_traversal(const vector<Node>& nodes, int root, string& res) {
	if(!root) return ;
	Mid_order_traversal(nodes, nodes[root].lc, res);
	res += nodes[root].value;
	Mid_order_traversal(nodes, nodes[root].rc, res);
}

void Post_order_traversal(const vector<Node>& nodes, int root, string& res) {
	if(!root) return ;
	Post_order_traversal(nodes, nodes[root].lc, res);
	Post_order_traversal(nodes, nodes[root].rc, res);
	res += nodes[root].value;
}

void solved() {
	/* your code */	
	std::cin >> n;
	std::vector<Node> nodes(n + 1);
	for (int i = 1; i <= n; i ++) 
		std::cin >> nodes[i].value >> nodes[i].lc >> nodes[i].rc;
	
	Pre_order_traversal(nodes, 1, Pre_ans);
	Mid_order_traversal(nodes, 1, Mid_ans);
	Post_order_traversal(nodes, 1, Pos_ans);

	std::cout << Pre_ans << std::endl;
	std::cout << Mid_ans << std::endl;
	std::cout << Pos_ans << std::endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}