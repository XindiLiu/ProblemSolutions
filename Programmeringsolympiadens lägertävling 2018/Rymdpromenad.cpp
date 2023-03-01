#include <bits/stdc++.h>
#define print(xxxx) {cout<<#xxxx<<'='<<xxxx<<endl;}
#define printv(xxxxx) {cout<<#xxxxx<<'=';for(int xushu=0;xushu<xxxxx.size();++xushu){cout<<xxxxx[xushu]<<' ';}cout<<endl;}

using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main()
{
    int n,m,ls;
    ll s=0;
    cin>>n>>m;
    vi a(m+2);
    a[0]=1;
    a[m+1]=1;
    for(int i=1;i<=m;i++)cin>>a[i];
    vector<int> ms(n);
    vi p(n);
  //  printv(a)
    for(int i=1;i<m+2;i++){
        ls=a[i]-a[i-1];
        if(ls<0)ls+=n;
        ms[ls]++;
    }
 //   printv(ms)
    for(int i=1;i<n;i++){
        s+=ll(i)*ll(ms[i]);
    }
//    print(s)
    for(int i=1;i<n;i++){
        p[i]=i-(n-i);
    }
 //   printv(p)
    int kv=s/n;
 //   print(kv)
    for(int i=n-1;i>0;i--){
        if(kv>ms[i]){
            kv-=ms[i];
            s-=ll(ms[i])*ll(p[i]);
        }
        else{
            s-=ll(p[i])*ll(kv);
            break;
        }

    }
    cout<<s;
    return 0;
}
