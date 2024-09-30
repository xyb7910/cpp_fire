#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;
typedef long long LL;
int n, sum;

struct Person{
	int num;
	string name;
	int score1;
	int score2;
	char cl;
	char pr;
	int ms;

	int sum() {
		int res = 0;
		if(score1 > 80 && ms >= 1) res += 8000;
		if(score1 > 85 && score2 > 80) res += 4000;
		if(score1 > 90) res += 2000;
		if(score1 > 85 && pr == 'Y') res += 1000;
		if(score2 > 80 && cl == 'Y') res += 850;

		return res;
	}

	bool operator<(Person& t) {
		return sum() < t.sum();
	}
};



Person p[N];

int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i ++) {
		p[i].num = i;
		cin >> p[i].name >> p[i].score1 >> p[i].score2 >> p[i].cl >> p[i].pr >> p[i].ms;
	}
	sort(p, p + n);
	for (int i = 0; i < n; i ++) {
		sum += p[i].sum();
	}
	cout << p[n - 1].name << endl;
	cout << p[n - 1].sum() << endl;
	cout << sum << endl;
	return 0;
}