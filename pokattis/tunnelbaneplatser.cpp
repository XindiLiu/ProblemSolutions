#include <bits/stdc++.h>
#define print(xxxx) {cout<<#xxxx<<'='<<xxxx<<endl;}
#define printv(xxxxx) {cout<<#xxxxx<<'=';for(int xushu=0;xushu<xxxxx.size();++xushu){cout<<xxxxx[xushu]<<' ';}cout<<endl;}
using namespace std;
typedef vector<int> vint;
typedef pair<int,int> pii;
typedef long long ll;



int main()
{

    int svar=0;
    int a1,a2,a3,a4;
    cin>>a1>>a2>>a3>>a4;
    svar=a4;
    svar+=a3;
    a1-=a3;
    if(a1<0)a1=0;
    int a22=ceil(double(a2)/2.0);
    svar+=a22;
    if(a22*2-a2==1)a1-=2;
    if(a1>0){
        svar+=ceil(double(a1)/4.0);
    }
    cout<<svar;

    return 0;
}
