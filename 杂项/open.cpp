/*
* @Author: Yanpb
* @Date:   2025-01-13 15:23:47
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-13 18:06:49
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <fstream>

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


void solved() {
	/* your code */
	ifstream in;
	in.open("test.txt");
	if(in.is_open()) {
		string line;
		while(getline(in, line)) {
			cout << line << endl;
		}
		in.close();
	} else {
		cout << "funt" << endl;
	}
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}