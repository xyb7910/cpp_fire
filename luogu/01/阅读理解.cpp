#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 3e6 + 10;
int n, m, idx;	
int son[N][26], pos[N][10];
char s[30];

inline void insert(char str[], int id) {
	int p = 0;
	for (int i = 0; str[i]; i ++) {
		int u = str[i] - 'a';
		if(!son[p][u]) son[p][u] = ++ idx;
		p = son[p][u];
	}
	pos[p][id] = 1;
}	

inline void query(char str[]) {
    int p = 0;
    for (int i = 0; str[i]; i++) {
        int u = str[i] - 'a';
        if (!son[p][u]) {
            cout << endl; // 如果在某一步没有子节点，直接返回
            return ;
        }
        p = son[p][u];
    }

    bool has_output = false; // 标记是否有输出
    for (int i = 1; i <= n; i++) {
        if (pos[p][i]) {
            if (has_output) {
                cout << " "; // 在数字之间输出空格
            }
            cout << i;
            has_output = true;
        }
    }
    cout << endl;
}

int main() {
    cin >> n;
	for (int i = 1; i <= n; i ++) {
		int cnt;
		cin >> cnt;
		while(cnt --) {
			cin >> s;
			insert(s, i);
		}
	}
	cin >> m;
	while(m --) {
		cin >> s;
		query(s);
	}
    return 0;
}