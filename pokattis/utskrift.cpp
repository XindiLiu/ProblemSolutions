#include <bits/stdc++.h>
#define visall(xxxxx) {cout<<#xxxxx<<":{";for(int aaaaa=0;aaaaa<xxxxx.size();aaaaa++)cout<<aaaaa<<'['<<xxxxx[aaaaa]<<']'<<' ';cout<<"}\n";}
#define visa(xxxxx) cout<<#xxxxx<<':'<<xxxxx<<endl;
using namespace std;
void utskrift(int r,int sw);
vector<string> w;
int v[1001][1001];
int main()
{
    //std::ios::sync_with_stdio(false);
   // freopen("utskrift.txt","r",stdin);
    int n,k;
    cin>>n>>k;
    w.resize(k);
    vector<int> c(k);
    vector<int> s(k+1);
    s[0]=0;
    for(int i=0;i<k;i++){
        cin>>w[i];
        c[i]=w[i].size();
        s[i+1]+=c[i]+s[i];
    }
    int f[k+1][k];
    for(int i=0;i<k;i++)f[1][i]=abs(s[i+1]+i-n);
 /*   visall(s)visall(c)
    for(int i=0;i<k;i++)cout<<f[1][i]<<' ';
    cout<<endl;
    //freopen("utskrif.txt","w",stdout);*/
    for(int i=2;i<=k;i++){//varje rad
          // visa(i)
        for(int j=i-1;j<k;j++){//varje ord raden slutar med
        //7    visa(j)
            f[i][j]=INT_MAX;
            for(int l=i-2;l<j;l++){
                if(f[i][j]>max(f[i-1][l],abs(s[j+1]-s[l+1]+j-l-1-n))){
                    f[i][j]=max(f[i-1][l],abs(s[j+1]-s[l+1]+j-l-1-n));
                    v[i][j]=l;
                }
                //cout<<i-1<<' '<<l;visa(f[i][j])visa(v[i][j])
            }
        }
    }
    int ma=INT_MAX,mr;
    for(int i=1;i<=k;i++)
        if(ma>f[i][k-1]){
        ma=f[i][k-1];
        mr=i;
        }
    utskrift(mr,k-1);

    return 0;
}
void utskrift(int r,int sw)
{
    //visa(r)visa(sw)
    if(r>1){
        utskrift(r-1,v[r][sw]);
        for(int i=v[r][sw]+1;i<sw;i++){
            cout<<w[i]<<' ';
        }
        cout<<w[sw]<<endl;
    }
    else{
        for(int i=0;i<sw;i++)cout<<w[i]<<' ';
        cout<<w[sw]<<endl;
    }
}
