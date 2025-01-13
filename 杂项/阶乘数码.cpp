/*
* @Author: Yanpb
* @Date:   2025-01-11 15:19:51
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-13 20:22:37
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

int res[N];
/*
 高精度 * 低精度 
 1、 计算阶乘 初始化 = 1 最终计算结果 ans 
 2、 统计ans中a的出现次数

 1、 上一次阶乘答案
 2、 下个数
*/

void solved() {
	/* your code */
	int t; cin >> t;
	while(t --) {
		memset(res, 0, sizeof (res));
		res[0] = {1};

		int n, a; cin >> n >> a;
		int k = 1; 
		// i 计算的次数
		for (int i = 1; i <= n; i ++) {
			// 遍历 result 数组每一个数字
			/*
			1、res[i] * b ==>  res[] = {1,2,3} * 12
			// res[] = {12, 24, 36}
			2、考虑进位 和 保留
			// 下一位的进位 ==> 当前位置的数 / 进制数
			// 保留数字 ==> 当前位置的数 % 进制数
			*/
			for (int j = 0; j < k ; j ++) res[j] *= i;

			// 考虑到计算结果的倒数第二位	k - 2
			for (int j = 0; j < k - 1; j ++) {
				res[j + 1] += res[j] / 10;
				res[j] %= 10;
			}
			
			// 考虑最高位进位	k - 1 (123)
			while(res[k - 1] > 9) {
				res[k] = res[k - 1] / 10;
				res[k - 1] %= 10;
				k ++;
			}
		}

		int cnt = 0;
		for (int i = 0; i < k; i ++)
			if(res[i] == a) cnt ++;
		cout << cnt << endl;
	}
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}