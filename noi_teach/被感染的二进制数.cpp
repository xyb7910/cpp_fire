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
	
std::vector<int> add(const std::vector<int>& A, const std::vector<int>& B) {
	std::vector<int> ans;
	int t = 0;
	for (int i = 0; i < A.size() || i < B.size() || t; i ++) {
		if(i < A.size()) t += A[i];
		if(i < B.size()) t += B[i];
		ans.push_back(t % 2);
		t /= 2;
	}
	return ans;
}

void solved() {
    /* your code */
    // 因为题目中是乘17，在二进制中乘16的话，可以将二进制数字向左移动四位
    // 那么，我们就可以将乘17，转换成乘16 + 1 倍就行了
    // 首先先左移四位，最后使用高精度加法计算答案
    std::string a;
    std::cin >> a;

    std::string b = a + "0000";

    std::vector<int> A, B;
    for (int i = a.size() - 1; ~i; i --) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; ~i; i --) B.push_back(b[i] - '0');

    auto C = add(A, B);
	reverse(C.begin(), C.end());
	for (auto c : C) std::cout << c;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}