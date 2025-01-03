/*
* @Author: Yanpb
* @Date:   2025-01-03 15:33:18
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-03 15:35:04
*/
#include<cstdio>
#include<cstring>
#include<cmath>
#define inline __inline__ __attribute__((always_inline))
#define L 524288
#define mod 998244353
typedef long long LL;

int rev[L<<1];

namespace NTT //为了输出而写的NTT……
{
	int W[2][L],_i[20],invtmp[L],x[L],y[L];
	inline int invx(int x){int r=1;for(x%=mod;x>1;x=mod%x)r=LL(mod-mod/x)*r%mod;return r;}
	inline int ksm(LL a,LL b){int r=1;for(;b;a=a*a%mod,b>>=1)if(b&1)r=r*a%mod;return r;}
	void NTT_Init()
	{
		int i,t;
		const int G = 3,Gi = invx(G),i2 = invx(2),l = L>>1;
		t = ksm(G,mod/L), W[0][l] = 1;
		for(i=1;i<l;i++)W[0][i+l] = (LL)W[0][i+l-1]*t%mod;
		for(i=l-1;i;i--)W[0][i] = W[0][i<<1];
		t = ksm(Gi,mod/L), W[1][l] = 1;
		for(i=1;i<l;i++)W[1][i+l] = (LL)W[1][i+l-1]*t%mod;
		for(i=l-1;i;i--)W[1][i] = W[1][i<<1];
		for(_i[0]=i=1;i<20;i++)_i[i] = (LL)_i[i-1]*i2%mod;
	}
	void NTT(int *f,int len,int sign)
	{
		int i = 1,j,k,*w,*p,*q,t; sign = (sign < 0);
		for(int *r=rev+len+1;i<len;i++,r++)if(i<(k=*r))t=f[i],f[i]=f[k],f[k]=t;
		for(i=1;i<len;i<<=1)for(j=0;j<len;j+=i<<1)for(w=W[sign]+i,q=(p=f+j)+i,k=0;k<i;k++)
			{t=*q*LL(*w++)%mod;if((*q=*p-t)<0){*q+=mod;}if((*p+=t)>=mod){*p-=mod;}p++,q++;}
		if(sign)for(k=_i[__builtin_ctz(len)],i=0;i<len;i++)f[i] = (LL)k*f[i]%mod;
	}
	void poly_inv(int *a,int len,int *f)
	{
		int l,l2,i;len <<= 1;
		memset(f,0,len<<2), memset(invtmp,0,len<<2);
		for(f[0]=invx(a[0]),l=2,l2=4;l<len;l<<=1,l2<<=1)
		{
			memcpy(invtmp,a,l<<2), NTT(invtmp,l2,1), NTT(f,l2,1);
			for(i=0;i<l2;i++)f[i] = f[i]*(2-(LL)invtmp[i]*f[i]%mod+mod)%mod;
			NTT(f,l2,-1), memset(f+l,0,l<<2);
		}
	}
	void getout(char *s,int d)
	{
		int i,l;
		NTT_Init();
		for(i=0;i<d;i++)x[i] = s[i];
		for(l=1;l<d;l<<=1);
		poly_inv(x,l,y);
		for(i=0;i<d;i++)printf("%d ",y[i]);
	}
}

struct complex
{
	double a,b;
	inline void operator+=(const complex &z){a += z.a, b += z.b;}
	inline complex operator-(const complex &z){return {a-z.a,b-z.b};}
	inline complex operator*(const complex &z){return {a*z.a-b*z.b,a*z.b+b*z.a};}
}W[2][L];
void FFT_Init()
{
	int i,j; const int l = L>>1;
	const double pi = acos(-1);
	for(i=j=1;j<L;j<<=1)for(;i<j<<1;i++)rev[i<<1]=rev[i],rev[i<<1|1]=rev[i]+j;
	for(i=0;i<l;i++)W[0][i+l] = {cos(pi*i/l),sin(pi*i/l)};
	for(i=l-1;i;i--)W[0][i] = W[0][i<<1];
	memcpy(W[1],W[0],sizeof W[1]);
	for(i=1;i<L;i++)W[1][i].b *= -1;
}
void FFT(complex *f,int len,int sign)
{
	int i = 1,j,k; complex *p,*q,*w,t; sign = (sign < 0);
	for(int *r=rev+len+1;i<len;i++,r++)if(i<(k=*r))t=f[i],f[i]=f[k],f[k]=t;
	for(i=1;i<len;i<<=1)for(j=0;j<len;j+=i,j+=i)
		for(q=(p=f+j)+i,w=W[sign]+i,k=0;k<i;k++,p++,q++)t=*q**w++,*q=*p-t,*p+=t;
	if(sign){double p=1./len;for(i=0;i<len;i++,f++)f->a *= p, f->b *= p;}
}
int get(char *s)
{
	int c,l = 0;
	do c = getchar(); while(c < '1' || c > '9');
	do *s++ = char(c^48), l++, c = getchar(); while(c >= '0' && c <= '9');
	return l;
}
char a[L],b[L],bi[L],x[L],y[L];
complex t1[L],t2[L]; LL t3[L+1];
void majutsu(int len) //计算b的倒数，有效位数为len，结果存进bi里
{
	bool g = 1;
	int l = 16,l2 = 32,l4 = 64,i;
	long double d = 0,e = 1;
	for(i=0;i<20;i++)d = d+e*b[i], e *= 0.1;
	d = 10./d;
	if(d < 10)
	{
		for(i=0;i<=l;i++)bi[i] = d, d = (d-bi[i])*10;
		bi[l-1] += (bi[l] > 4);
	}
	else bi[0] = 10;
	while(l < len)
	{p:
		memset(t1,0,sizeof(complex)*l4);
		memset(t2,0,sizeof(complex)*l4);
		for(i=0;i<l2;i++)t1[i].a = b[i];
		for(i=0;i<l;i++)t2[i].a = bi[i];
		FFT(t1,l4,1), FFT(t2,l4,1);
		for(i=0;i<l4;i++)
		{
			t1[i] = t1[i]*t2[i];
			t1[i].a = 20-t1[i].a, t1[i].b = -t1[i].b;
			t2[i] = t1[i]*t2[i];
		}
		FFT(t2,l4,-1); t3[l4] = 0;
		for(i=l4-1;i>=0;i--)
		{
			t3[i] = LL(floor(t2[i].a+0.5))+t3[i+1]/10, t3[i+1] %= 10;
			if(t3[i+1] < 0)t3[i+1] += 10, t3[i]--;
		}
		if(t3[0] > 9)
		{
			bi[0] = t3[0]/10, t3[0] %= 10;
			for(i=1;i<l2;i++)bi[i] = t3[i-1];
			bi[l2-1] += (t3[l2-1] > 4);
		}
		else
		{
			for(i=0;i<l2;i++)bi[i] = t3[i];
			bi[l2-1] += (t3[l2] > 4);
		}
		l <<= 1, l2 <<= 1, l4 <<= 1;
	}
	if(g){g = 0, l >>= 1, l2 >>= 1, l4 >>= 1; goto p;} //迭代过程结束后末几位仍会有偏差，于是再单独迭代一次
}
int divide(int n,int m) //计算a/b，整数部分存进x里
{
	int p = n-m+16,l,i;
	majutsu(p);
	for(l=1;l<n+p;l<<=1);
	memset(t1,0,sizeof(complex)*l);
	memset(t2,0,sizeof(complex)*l);
	for(i=0;i<n;i++)t1[i].a = a[i];
	for(i=0;i<p;i++)t2[i].a = bi[i];
	FFT(t1,l,1), FFT(t2,l,1);
	for(i=0;i<l;i++)t1[i] = t1[i]*t2[i];
	FFT(t1,l,-1); t3[l] = 0;
	for(i=l-1;i>=0;i--)t3[i] = LL(t1[i].a+0.5)+t3[i+1]/10, t3[i+1] %= 10;
	if(t3[0] > 9)
	{
		x[0] = t3[0]/10, t3[0] %= 10, l = n-m+1;
		for(i=0;i<n-m;i++)x[i+1] = t3[i];
	}
	else for(l=n-m,i=0;i<n-m;i++)x[i] = t3[i];
	return l;
}
void lack(int n,int m,int &d) //微调
{
	int l,i,j; char t; LL tl = 0;
	for(i=0,j=n-1;i<j;i++,j--)t = a[i], a[i] = a[j], a[j] = t;
	for(i=0,j=m-1;i<j;i++,j--)t = b[i], b[i] = b[j], b[j] = t;
	for(i=0,j=d-1;i<j;i++,j--)t = x[i], x[i] = x[j], x[j] = t;
	for(l=1;l<n;l<<=1);
	memset(t1,0,sizeof(complex)*l);
	memset(t2,0,sizeof(complex)*l);
	for(i=0;i<m;i++)t1[i].a = b[i];
	for(i=0;i<d;i++)t2[i].a = x[i];
	t2[0].a += 1.;
	FFT(t1,l,1), FFT(t2,l,1);
	for(i=0;i<l;i++)t1[i] = t1[i]*t2[i];
	FFT(t1,l,-1);
	for(i=0;i<=n;i++)tl += LL(t1[i].a+0.5), y[i] = tl%10, tl /= 10;
	for(i=n;i>=0;i--){if(y[i] > a[i])return;else if(y[i] < a[i])break;}
	for(x[0]++,i=0;x[i]>9;i++)x[i+1] += x[i]/10, x[i] %= 10;
	if(x[d])d++;
}
int main()
{
	int n,m,d;
	FFT_Init();
	n = get(a), m = get(b);
	d = divide(n,m);
	lack(n,m,d);
	NTT::getout(x,d);
	return 0;
}