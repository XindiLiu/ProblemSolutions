#include <bits/stdc++.h>
#define visall(xxxxx) {cout<<#xxxxx<<":{";for(int aaaaa=0;aaaaa<xxxxx.size();aaaaa++)cout<<xxxxx[aaaaa]<<' ';cout<<"}\n";}
#define visa(xxxxx) cout<<#xxxxx<<':'<<xxxxx<<endl;
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int n,nq;
    int svar=INT_MAX;
    cin>>n;
    nq=ceil(sqrt(n));
    for(double i=1;i<=nq;i++){
        svar=min(svar,int((ceil(n/i)+1)*(i+1)));
       // svar=min(svar,ceil(n/i));
    }
    cout<<svar;
    return 0;
}
//((i+2)*ceil(n/i)+i*2)
