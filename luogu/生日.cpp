#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
const int N = 110;
typedef long long LL;
int n;

struct Person{
	string name;
	int  year;
	int month;
	int day;
	int num;
	bool operator<(const Person& other) const {
       if (year!= other.year) return year < other.year;
       else if (month!= other.month) return month < other.month;
       else if (day!= other.day) return day < other.day;
       else return num > other.num;
    }
};



int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n;
	std::vector<Person> s(n);
	for (int i = 0; i < n; i ++) {
		cin >> s[i].name >> s[i].year >> s[i].month >> s[i].day;
		s[i].num = i;
	}
	sort(s.begin(), s.end());
	for (int i = 0; i < n; i ++) {
		cout << s[i].name << endl;
	}
	return 0;
}