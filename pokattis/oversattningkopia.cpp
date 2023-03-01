#include <bits/stdc++.h>
#define visall(xxxxx) {cout<<#xxxxx<<":{";for(int aaaaa=0;aaaaa<xxxxx.size();aaaaa++)cout<<xxxxx[aaaaa]<<',';cout<<"}\n";}
#define visa(xxxxx) cout<<#xxxxx<<':'<<xxxxx<<endl;
using namespace std;
const string tom="";
int main()
{
    std::ios_base::sync_with_stdio(false);
    int n,m,a=0,b=0,o1,o2;
    cin>>n;
    map<string,int> oa;
    map<string,int> ob;
    vector<string> oaa(n+1);
    vector<int> ola(n+1,0);
    vector<int> olb(n+1,0);
    vector<int> fo(n+1,0);
    string ina,inb;
    for(int i=0;i<n;i++){
        cin>>ina>>inb;
        if(oa[ina]==0){
            ++a;
            oa[ina]=a;
            oaa[a]=ina;
        }
        if(ob[inb]==0){++b;ob[inb]=b;}
        if(ola[oa[ina]]==0)ola[oa[ina]]=ob[inb];
        if(olb[ob[inb]]==0)olb[ob[inb]]=oa[ina];
    }

    cin>>m;
    vector<int> text(m);
    for(int i=0;i<m;++i){
        cin>>ina;
        text[i]=oa[ina];
    }
    for(int i=1;i<=n;++i){
        o1=i;
        o2=olb[ola[i]];
        while(o1!=o2){
            o1=o2;
            o2=olb[ola[o1]];
        }
        fo[i]=o2;
    }
 //   for(auto it=fo.begin();it!=fo.end();++it)cout<<it->first<<' '<<it->second<<endl;


    for(int i=0;i<m;++i)cout<<oaa[fo[text[i]]]<<' ';
    return 0;
}
/*
8
programmering programming
ar is
valdigt very
kul fun
skoj fun
mycket very
skoj amusing
roligt amusing
4
programmering ar mycket roligt
*/
