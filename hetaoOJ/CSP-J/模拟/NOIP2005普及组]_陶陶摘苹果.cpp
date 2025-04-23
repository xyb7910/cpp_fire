/*
* @Author: Yanpb
* @Date:   2025-04-22 23:11:40
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-22 23:23:26
*/
#include <iostream>

using namespace std;
int h[20], cnt;
int main() {
	for (auto &a : h) cin >> a;
	h[10] += 30;
	for (int i = 0; i < 10; i ++) if(h[10] >= h[i]) cnt ++;
	cout << cnt;
	return 0;
}