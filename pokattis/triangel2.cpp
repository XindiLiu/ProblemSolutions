#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    double n;
    cin>>n;
    long long pn[100000];
    int tn=0;
    pn[0]=0;
    int i=1;
    while(tn<=n){
        tn+=i;
        pn[i]=pn[i-1]+tn;
        ++i;
    }
  //  for(int j=0;j<i;j++)cout<<pn[j]<<' ';cout<<endl;
    for(int j=i-1;pn[j]>=n;--j){
        long long d=pn[j]-n;
       // cout<<pn[j]<<' '<<d<<' ';
        if(d==0){cout<<1<<' '<<j;return 0;}
        int m=ceil(pow(d*6.0,1.0/3.0));
        //cout<<m<<' '<<(m-ll(1))*m*(m+ll(1))<<endl;
        if((m-ll(1))*m*(m+ll(1))==d*ll(6)){
            cout<<m<<' '<<j;
            return 0;
        }
    }
    cout<<"NEJ";
    return 0;
}
