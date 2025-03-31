/*
* @Author: Yanpb
* @Date:   2025-03-27 17:02:17
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-03-28 18:22:05
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 50;

string str;
int st[N], tt;

int main() {
	cin >> str;
	int res = 0;
	for (int i = 0; i < str.size() - 1; i ++) {
		if(isdigit(str[i])) res = res * 10 + str[i] - '0';
		else if(str[i] == '.') st[++ tt] = res, res = 0;
		else {
			int end = st[tt]; tt --;
			int front = st[tt]; tt --;
			int num = 0;
			if(str[i] == '+') num = front + end;
			if(str[i] == '-') num = front - end;
			if(str[i] == '*') num = front * end;
			if(str[i] == '/') num = front / end;
			st[++ tt] = num;

		}
	}
	cout << st[tt] << endl;
	return 0;
}