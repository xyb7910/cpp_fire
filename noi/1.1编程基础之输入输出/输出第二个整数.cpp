#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	int n = 1;
	while(n < 3) {
		int num; cin >> num;
		if(n == 2) {
			cout << num << endl;
			break;
		}
		n ++;
	}
	return 0;
}