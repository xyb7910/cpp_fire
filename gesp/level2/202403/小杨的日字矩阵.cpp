#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			if(j == 1 || j == n) {
				cout << "|";
			} else {
				if(i == 1 || i == n || i == (n / 2 + 1)) {
					cout << "-";
				} else {
					cout << "x";
				}
			}
		}
		cout << endl;
	}
	return 0;
}