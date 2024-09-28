#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
string s;
string str, num;
int main()
{
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; i ++) {
		if(s[i] >= '0' && s[i] <= '9') {
			num += s[i];
		} else {
			str += s[i];
		}
	}
	sort(str.begin(), str.end());
	sort(num.begin(), num.end());
	cout << str << num << endl;
	return 0;
}