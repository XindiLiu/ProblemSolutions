#include <bits/stdc++.h>
#define print(xxxx) {cout<<#xxxx<<'='<<xxxx<<endl;}
#define printv(xxxxx) {cout<<#xxxxx<<'=';for(int xushu=0;xushu<xxxxx.size();++xushu){cout<<xxxxx[xushu]<<' ';}cout<<endl;}

using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main()
{
    ll n,maxai,ais=0;
    cin>>n;

    vector<ll> a(n);
    for(int i=1;i<n;i++){
        cin>>a[i];
        if(a[i]==0)i--;
    }
    //printv(a)
    vector<ll> sa(n);
    for(int i=1;i<n;i++){
        sa[1]+=a[i];
        ais+=a[i]*i;
    }
    for(int i=2;i<n;i++){
        sa[i]=sa[i-1]-a[i-1];
    }
   // printv(sa)
    maxai=ais;
    for(int i=1;i<n;i++){
       // cout<<ais+sa[i];
        maxai=max(maxai,ais+sa[i]);
    }
    cout<<maxai;

    return 0;
}
