#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

string s;
int b, l, cnt, len1, len2, len_s;
int A[N], B[N], ans[N];

void multiply(int x) {
    len1 = cnt, len2 = cnt;
    for (int k = 1; k < x; k ++) {
        memset(ans, 0, sizeof ans);

        for (int i = 0; i < len1; i ++)
            for (int j = 0; j < len2; j ++)
                ans[i + j] += A[i] * B[j];
        
        len_s = len1 + len2;
        for (int i = 0; i < len_s; i ++) {
            ans[i + 1] += ans[i] / 10;
			ans[i] %= 10;
        }

        for (int i = 0; i < len_s; i ++) A[i] = ans[i];
        len1 = len_s; 
    }
}

int main() {
    while(cin >> s >> b) {
        // 先存
        memset(A, 0, sizeof A);
        memset(B, 0, sizeof B);
        bool flag = 0;
        l = 0, cnt = 0; // l 表示小数点后有多少位， cnt 表示数字的位数
        for (int i = s.size() - 1; ~i; i --) {
            if(s[i] == '.') flag = 1;
            else {
                A[cnt ++] = s[i] - '0';
                B[cnt - 1] = A[cnt - 1];   
            }
            if(!flag) l ++;
        }
        
        int i = 0;
        while(A[i] == 0 && i <= l) {
            i ++, l --;
        } 
        
        l *= b;
        multiply(b);
        while(A[len_s - 1] == 0) len_s --;
        i = 0;
        while(A[i] == 0) i ++;
        string s1;
        while((len_s - 1) >= i || l > 0) {
            s1 = char(A[i] + '0') + s1;
            i ++, l --;
            if(!l) s1 = '.' + s1;
        }
        cout << s1 << endl;
    }
    return 0;
}