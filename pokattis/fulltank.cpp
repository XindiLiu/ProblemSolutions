#include <bits/stdc++.h>
#define visall(xxxxx) {cout<<#xxxxx<<":{";for(int aaaaa=0;aaaaa<xxxxx.size();aaaaa++)cout<<xxxxx[aaaaa]<<' ';cout<<"}\n";}
#define visa(xxxxx) cout<<#xxxxx<<':'<<xxxxx<<endl;
using namespace std;
int main()
{
    int n;
    double s=INFINITY,x=0,sp,xp,l;
    cin>>n;
    double v[n],p[n];
    for(int i=0;i<n;i++)cin>>v[i]>>p[i];
    cin>>l;
    for(int i=0;i<n;i++){
        sp=p[i]+4.99;
        sp/=v[i];
        s=min(s,sp);
        xp=p[i]-5;
        xp/=v[i];
        x=max(x,xp);
    }
    l*=x;
    l/=10;
    cout<<int(round(l)*10);
    return 0;
}
