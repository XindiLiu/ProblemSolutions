#include <bits/stdc++.h>
#define print(xxxx) {cout<<#xxxx<<'='<<xxxx<<endl;}
#define printv(xxxxx) {cout<<#xxxxx<<'=';for(int xushu=0;xushu<xxxxx.size();++xushu){cout<<xxxxx[xushu]<<' ';}cout<<endl;}
using namespace std;
typedef vector<int> vint;
typedef pair<int,int> pii;
typedef long long ll;



int main()
{
    //freopen("kopamatta3.in","r",stdin);
    ll n,m;
    cin>>m>>n;

    double b1,b2;
    for(ll i=0;i<m;i++){
        b1=(-i+sqrt(i*i+4*m))/2;
        b2=(-i+sqrt(i*i+4*n))/2;
        if(ceil(b1)==floor(b2)){cout<<ceil(b1)<<' '<<ceil(b1)+i;return 0;}
    }

    return 0;
}
