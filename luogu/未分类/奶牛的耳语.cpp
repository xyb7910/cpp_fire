#include<iostream>
#include<algorithm>
using namespace std;
int main(){
   int n,d,count=0;
   cin>>n>>d;
   int p[n];
   for(int i=0;i<n;i++){
		cin>>p[i];
   }
   sort(p,p+n);
   
   for(int i=0;i<n;i++){
   		for(int j=i+1;j<n;j++){
   			if(p[j]-p[i]<=d){
   				count++;
			   }else{
			   	break;
			   }
	    }
   }
   	cout<<count;
	return 0;
}

