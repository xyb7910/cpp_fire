#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
 
int main() {
	vector<int> v;
	int number;
    while(cin >> number) {
        for (int i = 0; i < number; i++) {
			int temp;
			cin >> temp;
			v.push_back(temp);
	 	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	int s = v.size();
	cout << s << endl;
	for (int i = 0; i < s; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	v.clear();
    }
	return 0;
}