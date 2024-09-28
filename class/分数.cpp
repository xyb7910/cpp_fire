#include <iostream>
#include <cstring>
#include <algorithm>
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
	cout << average << endl;

	for (int i = n - 2; i > 0; i -- ) 
		cout << score[i] << " ";
	return 0;
}





