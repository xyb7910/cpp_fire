#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int num[5][5];

int main()
{
	for (int i = 0; i < 3; i ++) {
		for (int j = 0; j < 4; j ++) {
			cin >> num[i][j];
		}
	}

	int res = num[0][0], c = 0, r = 0;

	for (int i = 0; i < 3; i ++) {
		for (int j = 0; j < 4; j ++) {
			if(num[i][j] > res) {
				res = num[i][j];
				r = i + 1;
				c = j + 1;
			}
		}
	}

	cout << res << endl << r << endl << c << endl;
	return 0;
}