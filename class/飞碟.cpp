#include<iostream>
#include<string>
using namespace std;

string a, b;
long long aSum = 1, bSum = 1;
int main() {
	cin >> a >> b;
	for(int i = 0; i < a.size(); i++) {
		aSum *= a[i] - 'A' + 1;
	}
	for(int i = 0; i < b.size(); i++) {
		bSum *= b[i] - 'A' + 1;
	}
	if(aSum % 47 == bSum % 47) {
		cout << "GO";
	} else {
		cout << "STAY";
	}
	return 0;
}