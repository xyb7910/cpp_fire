#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>
using namespace std;

const int N = 110;
int n;
double score[N];
double sum, average;

bool cmp(double a, double b) {
	return a > b;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i ++) 
		cin >> score[i];

	sort(score, score + n, cmp);
	for (int i = 1; i < n - 1; i ++) {
		sum += score[i];
	}
	average = sum / (n - 2);
	cout << fixed << setprecision(2) << average << endl;

	return 0;
}







