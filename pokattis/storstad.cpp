#include <bits/stdc++.h>
#define visall(x) {cout<<#x<<' ';for(auto iiii : x)cout<<iiii<<' ';cout<<endl;}
#define visa(x) cout<<#x<<':'<<x<<endl;
#define asiv(x) cout<<#x<<':'<<x<<' ';
using namespace std;
vector<int> vannerx;
vector<int> vannery;
vector<int> avx;
vector<int> avy;
int sumx,sumy;
int n,m;
int64_t avstand(int x,int y);
int main()
{
    cin>>n>>m;
    vannerx.resize(n);
    vannery.resize(n);
    avx.resize(n+1);
    avy.resize(n+1);
    vector<pair<int,int>> lgh(m);
    for(int i=0;i<n;i++)cin>>vannerx[i]>>vannery[i];
    for(int i=0;i<m;i++)cin>>lgh[i].first>>lgh[i].second;
    sort(vannerx.begin(),vannerx.end());
    sort(vannery.begin(),vannery.end());
    avx[0]=0;
    avy[0]=0;
    for(int i=0;i<n;i++){
        avx[i+1]=avx[i]+vannerx[i];
        avy[i+1]=avy[i]+vannery[i];
    }
    sumx=avx[n];
    sumy=avy[n];
//    visall(vannerx)
//    visall(vannery)
//    visall(avx)
//    visall(avy)
    int64_t minas=9223372036854775807;
    for(int i=0;i<m;i++){
        minas=min(minas,avstand(lgh[i].first,lgh[i].second));
    }
    cout<<minas;
    return 0;
}
int64_t avstand(int x,int y)
{
//    asiv(x)asiv(y)
    int64_t svar=0;
    int uppx=upper_bound(vannerx.begin(),vannerx.end(),x)-vannerx.begin();
    int uppy=upper_bound(vannery.begin(),vannery.end(),y)-vannery.begin();
//    asiv(uppx)visa(uppy)
    svar+=-avx[uppx]+(sumx-avx[uppx])+x*(uppx-(n-uppx));
    svar+=-avy[uppy]+(sumy-avy[uppy])+y*(uppy-(n-uppy));
//    asiv(avx[uppx])asiv(sumx-avx[uppx])asiv(uppx-(n-uppx))
//    asiv(avy[uppy])asiv(sumy-avy[uppy])asiv(uppy-(n-uppy))
//    visa(svar)
    return svar;

}
