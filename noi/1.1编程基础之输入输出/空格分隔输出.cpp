#include <iostream>
using namespace std;
int main() {
	char c;
	int n;
	float f;
	double d;
	cin >> c >> n >> f >> d;
	cout << c << " " << n << " ";
	printf("%.6f %.6lf\n", f, d);
	return 0;
}