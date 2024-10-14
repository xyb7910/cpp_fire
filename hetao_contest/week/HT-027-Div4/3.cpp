#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
const int N = 1e5 + 10;
typedef long long LL;

int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	string a, b;
	cin >> a >> b;

	size_t pos = a.find(b);
	std::vector<int> positions;

	while(pos != string::npos) {	
		positions.push_back(pos + 1);
		pos = a.find(b, pos + 1);
	}

	// cout << positions.size() << endl;
	if(!positions.empty()) {
		cout << "YE5" << endl;
		for (int i = 0; i < positions.size(); i ++) {
			cout << positions[i] << " ";
		}
	} else {
		cout << "N0" << endl;
	}
	return 0;
}