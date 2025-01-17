/*
* @Author: Yanpb
* @Date:   2025-01-17 14:37:22
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-17 15:17:33
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int a[30][30], x, ans;
int main(){

    for(int i = 1; i <= 5; i++)
        for(int j = 1; j <= 5; j++)
            cin >> a[i][j];

    for(int k = 1; k <= 25; k++){
        cin >> x;

        for(int i = 1; i <= 5; i++)
            for(int j = 1; j <= 5; j++)
                if(a[i][j] == x) a[i][j] = -1;

        ans = 0;
        for(int i = 1; i <= 5; i++){
            int sum = 0;
            for(int j = 1; j <= 5; j++){
                if(a[i][j] == -1) sum++;
            }
            if(sum == 5) ans++;
        }
        for(int i = 1; i <= 5; i++){
            int sum = 0;
            for(int j = 1; j <= 5; j++){
                if(a[j][i] == -1) sum++;
            }
            if(sum == 5) ans++;
        }
        int sum = 0;
        for(int i = 1; i <= 5; i++){
            for(int j = 1; j <= 5; j++){
                if(i + j == 6 && a[i][j] == -1) sum++;
            }
        }
        if(sum == 5) ans++;

        sum = 0;
        for(int i = 1; i <= 5; i++){
            for(int j = 1; j <= 5; j++){
                if(i == j && a[i][j] == -1) sum++;
            }
        }
        if(sum == 5) ans++;

        if(ans >= 3){
            cout << k;
            return 0;
        }
    }
    return 0;
}