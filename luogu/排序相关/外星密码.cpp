/*
* @Author: Yanpb
* @Date:   2025-03-14 13:07:05
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-03-14 13:56:20
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
string psw;

string decode(string& s, int& idx) {
	string res;
	while(idx < s.size()) {
		if(s[idx] == '[') {
			idx ++;
			int d = 0;
			while(isdigit(s[idx])) {
				d = d * 10 + (s[idx] - '0');
				idx ++;
			}	
			string in = decode(s, idx);
			for (int i = 0; i < d; i ++) res += in;
		} else if(s[idx] == ']') {
			idx ++;
			return res;
		} else {
			res += s[idx];
			idx ++;
		}
	}
	return res;
}

void solved() {
	/* your code */
	std::cin >> psw;
	int i = 0;
	cout << decode(psw, i);	
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}