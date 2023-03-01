#include <bits/stdc++.h>
#define print(xxxx) {cout<<#xxxx<<'='<<xxxx<<endl;}
#define printv(xxxxx) {cout<<#xxxxx<<'=';for(int xushu=0;xushu<xxxxx.size();++xushu){cout<<xxxxx[xushu]<<' ';}cout<<endl;}
using namespace std;
typedef vector<int> vi;
int main()
{
    int n,n1i,maxmin;
    scanf("%d",&n);
    vi a(n);
    for(int i=0;i<n;++i)scanf("%d",&a[i]);
    vi f(n);
    vi b(n);
    f[0]=a[0];
    b[n-1]=a[n-1];
    for(int i=1;i<n;++i){
        f[i]=((f[i-1]>0)?(a[i]+f[i-1]):a[i]);
        b[n1i=n-1-i]=((b[n-i]>0)?(a[n1i]+b[n-i]):a[n1i]);
    }
    maxmin=a[0];
    for(int i=0;i<n;++i){
        maxmin=max(maxmin,min(f[i],b[i]));
    }
    printf("%d",maxmin);

    return 0;
}
