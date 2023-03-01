#include <bits/stdc++.h>
#define print(xxxx) {cout<<#xxxx<<'='<<xxxx<<endl;}
#define printv(xxxxx) {cout<<#xxxxx<<'=';for(int xushu=0;xushu<xxxxx.size();++xushu){cout<<xxxxx[xushu]<<' ';}cout<<endl;}
using namespace std;
typedef long long ll;

int main()
{
    int a,b,dag=1440,v=1,s=0;
    cin>>a>>b;
    if(a>b)swap(a,b);
    vector<int> tid(1500,0);
    for(int k=a;k<1440;k+=a)tid[k]+=1;
    for(int k=b;k<1440;k+=b)tid[k]+=2;
    for(int i=0;i<dag;++i){
        if(tid[i]==1){
            if(v==2){
               ++s;
               v=1;
            }
        }
        else if(tid[i]==2){
            if(v==1){
               ++s;
               v=2;
            }
        }
        else if(tid[i]==3){
            ++s;
            v=(v==1?2:1);
        }
    }
    cout<<s;
}
