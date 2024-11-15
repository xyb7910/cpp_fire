#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int a, b, cnt;

bool is_prime(int x) {
	if(x < 2) return false;
	for (int i = 2; i <= x / i; i ++)
		if(x % i == 0) return false;
	return true;
}

int main() {
	cin >> a >> b;
	for (int i = a; i <= b; i ++)
		if(is_prime(i)) cnt ++;
	cout << cnt << endl;
	return 0;
}