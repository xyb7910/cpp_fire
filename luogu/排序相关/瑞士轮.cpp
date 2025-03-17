#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2e5 + 10;
int n, m, k;
int s[N], w[N], q[N], q0[N], q1[N];

bool cmp(int a, int b) {
    if(s[a] != s[b]) return s[a] > s[b];
    return a < b;
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < 2 * n; i ++) scanf("%d", s + i);
    for (int i = 0; i < 2 * n; i ++) scanf("%d", w + i);
    for (int i = 0; i < 2 * n; i ++) q[i] = i;
    
    sort(q, q + n * 2, cmp);
    
    while(m --) {
        int t0 = 0, t1 = 0;
        for (int i = 0; i < 2 * n; i += 2) {
            int a = q[i], b = q[i + 1];
            if(w[a] < w[b]) {
                s[b] ++;
                q0[t0 ++] = a;
                q1[t1 ++] = b;
            }
            else 
            {
                s[a] ++;
                q0[t0 ++] = b;
                q1[t1 ++] = a;
            }
        }
        
        int i = 0, j = 0, t = 0;
        while(i < t0 && j < t1) {
            if(cmp(q0[i], q1[j])) {
                q[t ++] = q0[i ++];
            } else {
                q[t ++] = q1[j ++];
            }
        }
        
        while(i < t0) q[t ++] = q0[i ++];
        while(j < t1) q[t ++] = q1[j ++];
    }
    printf("%d", q[k - 1] + 1);
    return 0;
}