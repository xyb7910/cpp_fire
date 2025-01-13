/*
* @Author: Yanpb
* @Date:   2025-01-12 22:25:25
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-13 20:22:38
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
string s;
int b;
int A[N], B[N], ans[N];
int l, cnt, len1, len2, len_s; // l 表示 小数点后的位数， cnt 表示A数组现在存到第几位

void mutilply(int b) {
	// 两个数组的长度 ==> 两个数字有多少位
	len1 = cnt, len2 = cnt;
	for (int k = 1; k < b; k ++) { // k 为计算次数
		// 清空ans数组
		memset(ans, 0, sizeof ans);

		for (int i = 0; i < len1; i ++)
			for (int j = 0; j < len2; j ++)
				ans[i + j] += A[i] * B[j];

		// 考虑乘完位数
		len_s = len1 + len2;
		// 考虑进位
		for (int i = 0; i < len_s; i ++) {
			ans[i + 1] += ans[i] / 10;
			ans[i] %= 10;
		}	

		// 把 ans 数组 重新 赋值 给 A
		for (int i = 0; i < len_s; i ++) A[i] = ans[i];
		len1 = len_s;
	}
}

int main() {
	// while(scanf("%s %d", s, b) == 2) {
	// scnaf 返回值是 参数个数
	// }
	while(cin >> s >> b) {
		// 先考虑存储
		memset(A, 0, sizeof A);
		memset(B, 0, sizeof B);
		l = 0, cnt = 0;
		// 倒序存储
		// ~i ==> i >= 0
		bool f = 0; // 1.32342412
		for (int i = s.size() - 1; i >= 0; i --) {
			if(s[i] == '.') f = 1;
			else {
				A[cnt ++] = s[i] - '0';
				B[cnt - 1] = A[cnt - 1];
			}
			// 计算一下小数点后的位数 l
			if(!f) l ++;
		}

		// 	删除后面的零 1.0100
		int i = 0;
		while(A[i] == 0 && i <= l) {
			i ++, l --;
		}

		// 考虑最终计算结果后小数点的位数
		l *= b;
		// 进行乘法
		mutilply(b);

		// 考虑多余 0
		while(A[len_s - 1] == 0) len_s --;

		i = 0;
		while(A[i] == 0) i ++;

		// 表示答案
		string s1;
		while((len_s - 1) >= i || l > 0) {
			s1 = char(A[i] + '0') + s1;
			i ++, l --;
			if(!l) s1 = '.' + s1; // s1 += '.'; ==> s1 = s1 + '.';
		}
		cout << s1 << endl;
	}	
	return 0;
}