#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

string s;
int cnt;

int main()
{
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; i ++)
		if(s[i] == '1')
			cnt ++;
	cout << cnt;
	return 0;
}