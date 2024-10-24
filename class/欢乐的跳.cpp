#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int N;
	std::cin >> N;
	std::vector<int> v(N);
	for (auto& i : v) cin >> i;
	for (int i = 0; i < v.size() - 1; i ++) {
		if(abs(v[i] - v[i + 1]) > v.size() - 1) {
				puts("Not jolly");
				return 0;
			}
	}
	puts("Jolly");
    return 0;
}