#include <bits/stdc++.h>
#define visall(xxxxx) {cout<<#xxxxx<<":{";for(int aaaaa=0;aaaaa<xxxxx.size();aaaaa++)cout<<xxxxx[aaaaa]<<' ';cout<<"}\n";}
#define visa(xxxxx) cout<<#xxxxx<<':'<<xxxxx<<endl;
using namespace std;
typedef long long ll;
int main()
{
    ll n,l,s=0,sr=0;
    int hn=n/2;
    scanf("%lld",&l);
    scanf("%lld",&n);
    vector<ll> x(n);
    vector<ll> r(n);
    vector<ll> sri(n);
    scanf("%lld",&x[0]);
    scanf("%lld",&r[0]);
    sri[0]=r[0];
    sr=r[0];
    for(int i=1;i<n;i++){
        scanf("%lld",&x[i]);
        scanf("%lld",&r[i]);
        sri[i]=sri[i-1]+r[i];
        sr+=r[i];
    }
    sr=(sr%2)?(sr/2+1):(sr/2);
    ll p=x[lower_bound(sri.begin(),sri.end(),sr)-sri.begin()];
    for(int i=0;i<n;i++){
        s+=abs(x[i]-p)*r[i];
    }
    cout<<s;
    return 0;
}