#include <bits/stdc++.h>
using namespace std;
#define ruta pair<int,int>
#define visa(a) cout<<'('<<a.first<<','<<a.second<<')'<<endl;
map<ruta,int> rutor;
vector<ruta> hestar;
map<ruta,int> vag;
int n,m;
string hopp(ruta p);
//med 2 inte blockera, 3 är blockerad, 4 är häst
int main()
{
    cin>>n>>m;
    char * tecken=new char;
    ruta linshi;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>*tecken;
            linshi.first=i;
            linshi.second=j;
            if(*tecken=='H'){
                hestar.push_back(linshi);
                rutor[linshi]=4;
            }
            else if(*tecken=='#')rutor[linshi]=3;
            else
                rutor[linshi]=2;
        }
    }
    vag[hestar[0]]=1;
    cout<<hopp(hestar[0]);
    return 0;
}
string hopp(ruta p){
    ruta ho1(p.first+1,p.second+2);
    ruta ho2(p.first+1,p.second-2);
    ruta ho3(p.first-1,p.second+2);
    ruta ho4(p.first-1,p.second-2);
    ruta ho5(p.first+2,p.second+1);
    ruta ho6(p.first+2,p.second-1);
    ruta ho7(p.first-2,p.second+1);
    ruta ho8(p.first-2,p.second-1);
    vector<ruta> hoppruta{ho1,ho2,ho3,ho4,ho5,ho6,ho7,ho8};
    for(auto i : hoppruta){
        if(rutor[i]==2||rutor[i]==4){
            if(vag[i]==1)continue;
            vag[i]=1;
            if(rutor[i]==4)return "JA";
            if(hopp(i)=="JA")return "JA";

        }
    }
    return "NEJ";

}
