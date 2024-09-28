#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;
int n;
int num[N];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i ++) cin >> num[i];
	sort(num, num + n, cmp);
	for (int i = 0; i < n; i ++) cout << num[i] << " ";
	return 0;
}