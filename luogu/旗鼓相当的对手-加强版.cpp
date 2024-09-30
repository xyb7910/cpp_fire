#include <bits/stdc++.h>
using namespace std;
struct student {
    string name;
    int yu,shu,ying,zong;
};
int main()
{
    student s[1005];
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> s[i].name >> s[i].yu >> s[i].shu >> s[i].ying;
        s[i].zong = s[i].yu + s[i].shu + s[i].ying;
    }
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            if (abs(s[i].yu-s[j].yu)<=5 && abs(s[i].shu-s[j].shu)<=5 && abs(s[i].ying-s[j].ying)<=5 && abs(s[i].zong-s[j].zong)<=10) {
                cout << s[i].name << " " << s[j].name << endl;
            }
        }
    }
    return 0;
}