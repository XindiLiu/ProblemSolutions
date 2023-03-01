#include <bits/stdc++.h>
#define print(xxxx) {cout<<#xxxx<<'='<<xxxx<<endl;}
#define printv(xxxxx) {cout<<#xxxxx<<'=';for(int xushu=0;xushu<xxxxx.size();++xushu){cout<<xxxxx[xushu]<<' ';}cout<<endl;}

using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main()
{
    double m,s,g,l,r;
    double a,b;
    cin>>m>>s>>g>>a>>b>>l>>r;
    double vt=l/a,rt=r/b;
 //   print(vt)print(rt)
    vt+=m/g;
    rt+=m/s;
   // print(vt)print(rt)
    if(vt<rt)cout<<"friskus";
    else cout<<"latmask";
    return 0;
}
