#include <bits/stdc++.h>
#define visall(xxxxx) {cout<<#xxxxx<<":{";for(int aaaaa=0;aaaaa<xxxxx.size();aaaaa++)if(xxxxx[aaaaa])cout<<aaaaa<<' ';cout<<"}\n";}
#define visa(xxxxx) cout<<#xxxxx<<':'<<xxxxx<<endl;
#define mif (meet[i].first)
#define mis (meet[i].second)
using namespace std;
int main()
{
//    freopen("kin.txt","r",stdin);
    int n,k,m,in;
    scanf("%d%d",&n,&k);
    vector<vector<int>> v(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++)v[i][i]=1;
    vector<pair<int,int>> meet(k);
    for(int i=0;i<k;i++)scanf("%d%d",&(meet[i].first),&(meet[i].second));
    scanf("%d",&m);
    vector<int> s(n+1,0);
    for(int i=0;i<m;i++){
        scanf("%d",&in);
        s[in]=1;
    }
    int as=0;
    vector<int> svar(n+1,0);
    for(int i=k-1;i>=0;--i){
        int ak=0;
        for(int j=1;j<=n;j++){
            v[mif][j]=v[mif][j]|v[mis][j];
            v[mis][j]=v[mif][j];
            if(v[mif][j])++ak;
        }
   //     visa(mif)visall(v[mif])
     //   visa(mis)visall(v[mis])
        if(ak==m){
            if(v[mif]==s){svar[mif]=1;svar[mis]=1;}
        }
    }
    for(int i=1;i<=n;++i)if(svar[i])cout<<i<<' ';
    return 0;
}
