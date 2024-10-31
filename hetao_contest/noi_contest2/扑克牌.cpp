#include<bits/stdc++.h>
using namespace std;
int poker[4][13];
/*
×Ö·û D ´ú±í·½Æ¬
×Ö·û C ´ú±í²Ý»¨
×Ö·û H ´ú±íºìÌÒ
×Ö·û S ´ú±íºÚÌÒ
*/
int n;
int main(){
	cout.tie(0);
	cin.tie(0);
	cin>>n;
	while(n--){
		int x,y;
		char a,b;
		cin>>a>>b;
		if(a=='D') x=0;
		else if(a=='C') x=1;
		else if(a=='H') x=2;
		else if(a=='S') x=3;
		if(b=='A') y=0;
		else if(b=='2') y=1;
		else if(b=='3') y=2;
		else if(b=='4') y=3;
		else if(b=='5') y=4;
		else if(b=='6') y=5;
		else if(b=='7') y=6;
		else if(b=='8') y=7;
		else if(b=='9') y=8;
		else if(b=='T') y=9;
		else if(b=='J') y=10;
		else if(b=='Q') y=11;
		else if(b=='K') y=12;
		poker[x][y]++;
	}
	int cnt = 0;
	for(int i=0;i<4;i++){
		for(int j=0;j<13;j++){
			if(poker[i][j]==0) cnt++;
		}
	}
	cout<<cnt;
	return 0;
}