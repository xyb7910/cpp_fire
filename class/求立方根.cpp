#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	double x;
	cin >> x;
	double l = 0, r = x;
	while(r - l > 0.0000001) {
		double mid = (l + r) / 2;
		if(mid * mid * mid < x) {
			l = mid;
		} else {
			r = mid;
		}
	}
	cout << l << endl;
	return 0;
}