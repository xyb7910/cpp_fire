#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N = 1e6 + 10;
char x[N],y[N];
int a[N],b[N],c[N],temp[N];

void init(int *x){
    char s[N];
    scanf("%s",s);
    x[0] = strlen(s);//int型数组的下标为0的地方存的是当前数组的长度

    //开始反转特长数据存放到当前的int型数组里面
    for(int i = 0;i < x[0];++i){
        x[x[0] - i] = s[i] - '0';//传进来的int型数组是从1开始的，然后注意是倒着存的
    }
}

void numcpy(int p[],int q[],int n){//用q去接收新的q，同时q要扩增0
    for(int i  = 1;i <= p[0];++i)q[i+n-1] = p[i];
    /*
    1.i表示移动的次数，最多的次数是原数据的长度p[0]
    2.n-1是枚举当前答案添加0的个数
    3.加i是数组从1开始
    */
    q[0] = p[0] + n - 1;//n-1就是需要加的0的个数，具体加多少个0是看当前枚举到哪一位了
}

int compare(int a[],int b[]){//0代表相等，1代表a大，-1代表b大
    if(a[0]<b[0])return -1;//下标存的是数组的位数，b的位数大，那么b数组大
    if(a[0]>b[0])return 1;//a的位数多，a大
    //位数一样多，倒着逐位比较
    for(int i = a[0];i > 0;--i){
        if(a[i] > b[i])return 1;
        if(a[i] < b[i])return -1;
    }
    return 0;
}

void minu(int a[],int b[]){//a和b做减法，做完减法的结果写回a数组里
    for(int i = 1;i <= a[0];++i){
        if(a[i] < b[i]){
            a[i + 1]--;
            a[i] = a[i] + 10;
        }
        a[i] = a[i] - b[i];
    }
    while(a[a[0]]==0&&a[0]>0)a[0]--;
}
void print(int a[]){

    if(a[0]==0){
        cout<<"0";
        return ;
    }

    for(int i = a[0];i >= 1;--i){
        cout<<a[i];
    }
    return;
}
int main(){
    //写一个init函数方便我们在数组a和b里倒着存储特长数据
    init(a);
    init(b);//每次调用init都会要输入大精度的数据

    c[0] = a[0] - b[0] + 1;//c数组放的是运算结果，运算结果最多是这么些个位数

    for(int i = c[0];i >= 1;--i){//为什么结果c非得倒着存？
        memset(temp,0,sizeof temp);//将temp清零
        numcpy(b,temp,i);//将b后面追加上0放到temp里面和a做差，看看能减几次
        /*
        结果c是倒着存的，结果c的当前位数i和在除数后面添0的个数之间关系是i-1同时也揭示了为什么要声明temp数组，temp数组的作用就是答案给c数组的每一位算能减多少次用的

        */
        while(compare(a,temp)>=0){
            c[i]++;
            minu(a,temp);
        }
    }

    while(c[c[0]]==0&&c[0]>0)c[0]--;
    print(c);
    cout<<endl;
    // while(a[a[0]]==0&&a[0] > 1)a[0]--;
    // for(int i = a[0];i >= 1;--i){
    //     cout<<a[i];//输出余数
    // }

    return 0;
}
