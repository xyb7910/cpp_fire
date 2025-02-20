#include <iostream>
#include <cstring>
#include <algorithm>

#define x first
#define y second

using namespace std;
const int N = 1010;
typedef pair<int, int> PII;
int n;
PII p[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> p[i].x;
        p[i].y = i;
    }
    sort(p + 1, p + n + 1);
    double wait_time = 0, cur_time = 0;
    for (int i = 1; i <= n; i ++) {
        wait_time += cur_time;
        cur_time += p[i].x;
        cout << p[i].y << " ";
    }
    cout << endl;
    printf("%.2lf\n", wait_time / n);
    return 0;
}

