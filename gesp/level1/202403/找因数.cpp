#include <iostream>
#include <cstring>
#include <algorithm>


using namespace std;

int main() {
	int m;
	cin >> m;
	for (int i = 1; i <= m; i ++) {
		if(m % i == 0) cout << i << endl;
	}
	return 0;
}