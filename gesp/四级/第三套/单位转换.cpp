/*
* @Author: Yanpb
* @Date:   2025-01-16 17:17:18
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-16 17:57:08
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

string t1, t2; // 单位1， 单位2
int a; // 转换前的数字
int res; // result

int main() {
	int T; cin >> T;
	while(T --) {
		char eq, qu;
		cin >> a >> t1 >> eq >> qu >> t2; 
		if(t1 == "km") {
			if(t2 == "m") {
				res = a * 1e3;
			} else {
				res = a * 1e6;
			}
		} else if(t1 == "kg") {
			if(t2 == "g") {
				res = a * 1e3;
			} else {
				res = a * 1e6;
			}
		} else {
			res = a * 1e3;
		}
		cout << a << " " << t1 << " = " <<  res << " " << t2 << endl; 
	}
	return 0;
}