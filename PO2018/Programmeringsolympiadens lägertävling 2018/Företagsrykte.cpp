#include <bits/stdc++.h>
#define print(xxxx) {cout<<#xxxx<<'='<<xxxx<<endl;}
#define printv(xxxxx) {cout<<#xxxxx<<'=';for(int xushu=0;xushu<xxxxx.size();++xushu){cout<<xxxxx[xushu]<<' ';}cout<<endl;}

using namespace std;
typedef long long ll;
typedef vector<int> vi;
void f(int x,ll s,int fg);
ll n,k,svar=0,summa=0;
vi r;
int main()
{

    cin>>n>>k;
    r.resize(n);
    for(int i=0;i<n;i++){
        cin>>r[i];
        summa+=r[i]*(n-i);
    }
    f(1,0,0);
    cout<<summa-svar;

    return 0;
}
void f(int x,ll s,int fg)
{
    if(x==n){
        svar=max(svar,s);
        return;
    }
    ll ls=-k;
    for(int i=fg;i<x;i++){
        ls+=ll(n-x)*ll(r[i]);
    }
    f(x+1,s+ls,x);
    f(x+1,s,fg);
}
