#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
string s, back_up;


int main() {
	cin >> s;
	back_up = s;
	reverse(s.begin(), s.end());
	if (s == back_up) puts("yes");
	else puts("no");
	return 0;
}