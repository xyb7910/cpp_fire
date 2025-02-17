#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>

using namespace std;

const int N = 110;

int n;
double t;
struct  w{
  double m, v;
  double p; // 每个金币的质量，总价值，单价
  bool operator<(const w t) {
      return t.p < p;
  }
}a[N];

int main() {
    cin >> n >> t;
    for (int i = 0; i < n; i ++) {
        cin >> a[i].m >> a[i].v;
        a[i].p = a[i].v / a[i].m; 
    }
    sort(a, a + n);
    int i = 0;
    double sum = 0;
    while(t) {
        if(t >= a[i].m) {
            t -= a[i].m;
            sum += a[i].v;
        } else  {
            sum += t * a[i].p;
            break;
        }
        i ++;
    }
    printf("%.2lf\n", sum);
    return 0;
}