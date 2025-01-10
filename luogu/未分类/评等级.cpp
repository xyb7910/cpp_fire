#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;
typedef long long LL;

struct Stu {
	int id;
	int score1;
	int score2;

	bool check_exec() {
		return score1 + score2 > 140 && score1 * 0.7 + score2 * 0.3 >= 80;
	}
};

int n;
Stu s[N];

int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n;
	for (int i = 0; i < n;i ++) {
		cin >> s[i].id >> s[i].score1 >> s[i].score2;
		if(s[i].check_exec()) puts("Excellent");
		else puts("Not excellent");
	}
	return 0;
}