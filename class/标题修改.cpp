#include<iostream>
#include<string>
using namespace std;

string s;
int main() {
	while(cin >> s) {
		for(int i = 0; i < s.size();i++) {
		if((i + 1) % 2 == 0) {
			s[i] = tolower(s[i]);
		} else {
			s[i] = toupper(s[i]);
		}
		}
		cout << s << " ";
	}
	// getline(cin,s);
	return 0;
}