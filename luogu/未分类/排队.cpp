#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
const int N = 1e5 + 10;
typedef long long LL;
int T;
int n;
int f[N];

int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> T;

	while(T --) {
		cin >> n;
		std::vector<double> boy, girl;
		for (int i = 0; i < n; i ++) cin >> f[i];
		for (int i = 0; i < n; i ++) {
			double h;
			cin >> h;
			if(f[i]) boy.push_back(h);
			else girl.push_back(h);
		}

		sort(boy.begin(), boy.end());
		sort(girl.begin(), girl.end());

		for (int i = 0; i < girl.size(); i ++) cout << girl[i] << " ";
		cout << endl;
		for (int i = 0; i < boy.size(); i ++) cout << boy[i] << " ";	
	}
	return 0;
}