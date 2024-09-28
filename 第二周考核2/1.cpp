#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 110;
int n, num;
int s[N];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> s[i];
	}
	cin >> num;

	for (int i = 1; i <= n; i ++) {
		if(s[i] == num) {
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}