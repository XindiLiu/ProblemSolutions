#include <bits/stdc++.h>
#define print(xxxx) {cout<<#xxxx<<'='<<xxxx<<endl;}
#define printv(xxxxx) {cout<<#xxxxx<<'=';for(int xushu=0;xushu<xxxxx.size();++xushu){cout<<xxxxx[xushu]<<' ';}cout<<endl;}
using namespace std;
typedef vector<int> vi;
vi f;
vi d;
vi old;
vi tal;
bool older(int a,int b);
int main()
{
    int n,ar=0,oldi;
    cin>>n;
    f.resize(n);
    d.resize(n);
    old.resize(n);
    tal.resize(n);
    for(int i=0;i<n;++i){
        cin>>f[i]>>d[i];
        old[i]=i;
        tal[i]=0;
    }
    sort(old.begin(),old.end(),older);
    for(int i=0;i<n;i++){
        oldi=old[i];
        if(ar>=d[oldi])continue;
        tal[oldi]=d[oldi]-max(ar,f[oldi]);
        ar=d[oldi];
    }
    for(int i=0;i<n;++i)cout<<tal[i]<<endl;
    return 0;
}
bool older(int a,int b){return f[a]<f[b];}

