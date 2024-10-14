#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;
typedef long long LL;
int n;
struct Person {
	string name;
	int year;
	int month;
	int day;
	int num;

	bool operator<(const Person& t) {
		if(year != t.year) return year < t.year;
		if(month != t.month) return month < t.month;
		if(day != t.day) return day < t.day;
		else return num > t.num;
	}
};

Person p[N];
int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i ++) {
		p[i].num = i;
		cin >> p[i].name >> p[i].year >> p[i].month >> p[i].day;
	}
	sort(p, p + n);
	for (int i = 0; i < n; i ++) {
		cout << p[i].name << endl;
	}
	return 0;
}
