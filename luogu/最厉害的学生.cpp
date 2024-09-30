#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;
typedef long long LL;

int n;

struct Stu{
	string name;
	int id;
	int sc1;
	int sc2;
	int sc3;

	int sum() {
		return sc1 + sc2 + sc3;
	}

	bool operator<(Stu& t) {
		if(sum() != t.sum()) return sum() < t.sum();
		return id > t.id;
	}
};

Stu s[N];

int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i ++) {
		s[i].id = i;
		cin >> s[i].name >> s[i].sc1 >> s[i].sc2 >> s[i].sc3;
	}
	sort(s, s + n);
	cout << s[n - 1].name << " " << s[n - 1].sc1 << " " << s[n - 1].sc2 << " " << s[n - 1].sc3;	
	return 0;
}