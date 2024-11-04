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

void solved() {
	/* your code */
	int n;
    std::cin >> n;

    // 定义一个二维向量存储答案 ==> 类似与二维数组
    std::vector<std::vector<int>> pascal_triangle(n);

    // 
    for (int i = 0; i < n; ++i) {
        // 每一次数组的大小为 当前的层数，所以使用 resize 重置每一个向量的大小 
        pascal_triangle[i].resize(i + 1);
        // 每一层第一个元素和最后一个元素都为 1
        pascal_triangle[i][0] = pascal_triangle[i][i] = 1;  

        for (int j = 1; j < i; ++j) {
            // 使用通项是计算当前位置的值： 每一个节点的值等于其正上方的值 + 其左上方的值
            pascal_triangle[i][j] = pascal_triangle[i - 1][j - 1] + pascal_triangle[i - 1][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            // 输出答案即可，注意边界
            std::cout << pascal_triangle[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}