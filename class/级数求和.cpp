#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;
typedef long long LL;

int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int k;
	int n = 0;
	cin >> k;  
	double s = 0;  
	while(s <= k){
		n += 1; 
		s += double(1) / n; 
	}
	cout << n; 
	return 0;
}