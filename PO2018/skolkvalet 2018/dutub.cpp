#include <bits/stdc++.h>
#define print(xxxx) {cout<<#xxxx<<'='<<xxxx<<endl;}
#define printv(xxxxx) {cout<<#xxxxx<<'=';for(int xushu=0;xushu<xxxxx.size();++xushu){cout<<xxxxx[xushu]<<' ';}cout<<endl;}
using namespace std;
typedef vector<int> vint;
typedef pair<int,int> pii;
typedef long long ll;

vint sett;
vector<vint> k(11,vint(31,0));
vector<vint> vk;
vint la;
int mintid=INT_MAX;
int antalk;
void f(int c, int tid);

int main()
{

    //freopen("dutub2.in","r",stdin);
    int n;
    cin>>n;
    vector<string> vc(n);
    vk.resize(n);
    la.resize(n);
    for(int i=0;i<n;i++)cin>>la[i]>>vc[i];
    antalk=0;
    map<char,int> kt;
    for(int i=0;i<n;i++){
        int vcis=vc[i].size();
        for(int j=0;j<vcis;j++){
            if(kt[vc[i][j]]==0){
                antalk++;
                kt[vc[i][j]]=antalk;
             //   print(vc[i][j])print(kt[vc[i][j]])
            }
            int a=kt[vc[i][j]];
            k[a][++k[a][0]]=i;
        }
    }
    for(int i=0;i<n;i++){
        int vcis=vc[i].size();
        vk[i].resize(vcis);
        for(int j=0;j<vcis;j++){
            vk[i][j]=kt[vc[i][j]];
        }
    }
    sett.assign(antalk+1,0);
    f(1,0);
    //printv(la)
  //  print(antalk)
  //  for(int i=0;i<=antalk;i++){printv(k[i]);}
    //for(int i=0;i<n;i++)printv(vk[i])
    cout<<mintid;
    return 0;
}

void f(int c, int tid)
{
    if(c>antalk){
           // print(tid)printv(sett)
        mintid=min(mintid,tid);
        return;
    }
    if(sett[c])f(c+1,tid);

    for(int i=1;i<=k[c][0];++i){

        int vkis=vk[k[c][i]].size();
        for(int j=0;j<vkis;++j)sett[vk[k[c][i]][j]]++;
        f(c+1,tid+la[k[c][i]]);
        for(int j=0;j<vkis;++j)sett[vk[k[c][i]][j]]--;
    }


}

