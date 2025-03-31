/*
* @Author: Yanpb
* @Date:   2025-03-28 15:09:19
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-03-28 15:31:23
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
string s;
int main() {
	cin >> s; 
	int n = s.size();
	stack<char> st;
	for (int i = 0; i < n; i ++) {
		
		if(st.size() && st.top() == '(' && s[i] == ')' || st.top() == '[' && s[i] == ']') {
			cout << st.top() << s[i];
			st.pop();
		}
		st.push(s[i]);
	}
	cout << st.size() << endl;
	while(st.size()) {
		if(st.top() == '(' || st.top() == ')') cout << "()";
		if(st.top() == '[' || st.top() == ']') cout << "[]";
		st.pop();
	}
	return 0;
}