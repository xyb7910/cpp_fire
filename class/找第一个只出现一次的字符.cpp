#include<iostream>
#include<string>
using namespace std;

string s1,s2;
string tolower_string(string s) {
	for(int i = 0; i < s.size(); i++) {
		s[i] = tolower(s[i]);
	}
	return s;
}
int main() {
	cin >> s1;
	int cnt=0;
	int flag = 0;
	cout << tolower_string(s1) << endl;
	// while(cin >> s2) {
	// 	s1 = tolower_string(s1);
	// 	s2 = tolower_string(s2);
	// 	if(s1 == s2) {
	// 		cnt++;

	// 	}
	// }
	return 0;
}