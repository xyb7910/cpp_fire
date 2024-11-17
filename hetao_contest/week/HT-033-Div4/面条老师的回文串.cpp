#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

#define x first
#define y second

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int N = 1e5 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};


// 检查是否是传统标准下的回文串
bool isTraditionalPalindrome(const string& s) {
    string reversed = s;
    reverse(reversed.begin(), reversed.end());
    return s == reversed;
}

// 检查是否是面条老师标准下的回文串
bool isNoodleTeacherPalindrome(const string& s) {
    int n = s.length();
    for (int i = 0; i < n / 2; ++i) {
        char leftChar = s[i];
        char rightChar = s[n - 1 - i];

        if (leftChar == rightChar) {
            continue;
        } else if ((leftChar == 'p' && rightChar == 'q') || (leftChar == 'q' && rightChar == 'p') ||
                   (leftChar == 'b' && rightChar == 'd') || (leftChar == 'd' && rightChar == 'b') ||
                   (leftChar == '(' && rightChar == ')') || (leftChar == ')' && rightChar == '(') ||
                   (leftChar == '{' && rightChar == '}') || (leftChar == '}' && rightChar == '{') ||
                   (leftChar == '[' && rightChar == ']') || (leftChar == ']' && rightChar == '[') ||
                   (leftChar == '<' && rightChar == '>') || (leftChar == '>' && rightChar == '<')) {
            continue;
        } else {
            return false;
        }
    }
    return true;
}

void solved() {
	/* your code */
	string s;
	cin >> s;
	int n = s.size();
	bool a = isTraditionalPalindrome(s);
	bool b = isNoodleTeacherPalindrome(s);
	cout << (a ? "yes" : "no") << endl;
	cout << (b ? "yes" : "no") << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}