#include <bits/stdc++.h>
#define print(xxxx) {cout<<#xxxx<<'='<<xxxx<<endl;}
#define printv(xxxxx) {cout<<#xxxxx<<'=';for(int xushu=0;xushu<xxxxx.size();++xushu){cout<<xxxxx[xushu]<<' ';}cout<<endl;}
using namespace std;
typedef vector<int> vint;
typedef pair<int,int> pii;
typedef long long ll;



int main()
{
   // freopen("flyttkartonger1.in","r",stdin);
    int n;
    cin>>n;
    vector<ll> s(n);
    for(int i=0;i<n;++i)cin>>s[i];
    ll b=0,b1;
    ll s1=s[0];
    for(int i=n-2;i>=0;--i){
        if(s[i]-b<s[i+1]){
            b1=s[i+1]+b-s[i];
            s[i]=s[i+1]+b;
            b=b1;
        }
    }
    cout<<s[0]-s1;
    return 0;
}
