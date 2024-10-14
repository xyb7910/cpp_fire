#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int num[20];
int p;

int main()
{
    int n = 50;
    for (int i = 0; i < n; i ++ ) {
        cin >> p;
        num[p] ++;
    }
    
    int cnt = -1;
    
    for (int i = 0; i < 20; i ++ ) {
        if(cnt <= num[i]) {
            cnt = num[i];
        }
    }
    cout << cnt << endl;
    return 0;
}