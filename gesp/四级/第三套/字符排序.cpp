/*
* @Author: Yanpb
* @Date:   2025-01-16 17:02:34
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-16 17:57:10
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;

string str[N];

int main(int argc, char const *argv[])
{
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		for (int i = 0; i < n; i ++) cin >> str[i];
		sort(str, str + n);
		string backup = "", result = "";
		for (int i = 0; i < n; i ++) backup += str[i];
		result = backup;
		sort(backup.begin(), backup.end());
		puts(result == backup ? "1" : "0");
	}
	return 0;
}