#include <bits/stdc++.h>
#define  visa(x) cout<<#x<<':'<<x<<endl;
using namespace std;
const string mal="123456780";
struct steg
{
    string r;
//    int nollf;
    int nolln;
    steg(string ir="          ",int inn=0)
    {
        r=ir;
//        nollf=inf;
        nolln=inn;
    }
};
steg upp(steg u);
steg ner(steg u);
steg van(steg u);
steg hog(steg u);
int main()
{
    string plan;
    for(int i=0;i<3;i++)for(int j=0;j<3;j++){
        char a;
        cin>>a;
        plan+=a;
    }
    int nollan=find(plan.begin(),plan.end(),'0')-plan.begin();
    vector<steg> stegs(1000000);
    vector<steg> er(1000000);
    stegs[0]=steg(plan,nollan);
    int kf=1;
    int kn=0;
    int svar;
    map<string,bool> tagen;
    for(int i=1;i<33;i++)
    {
//        cout<<i<<"---------------";
//        visa(kf)
        for(int j=0;j<kf;j++){
            if(stegs[j].nolln>2){
                steg na=upp(stegs[j]);
                if(!tagen[na.r]){
                    if(na.r==mal){svar=i;goto svara;}
                    er[kn]=na;
                    tagen[na.r]=1;
//                cout<<er[kn].r<<endl;
                    kn+=1;
                }
            }
            if(stegs[j].nolln<6){
                steg na=ner(stegs[j]);
                if(!tagen[na.r]){
                    if(na.r==mal){svar=i;goto svara;}
                    er[kn]=na;
                    tagen[na.r]=1;
//                cout<<er[kn].r<<endl;
                    kn+=1;
                }
            }
            if(stegs[j].nolln%3!=0){
                steg na=van(stegs[j]);
                if(!tagen[na.r]){
                    if(na.r==mal){svar=i;goto svara;}
                    er[kn]=na;
                    tagen[na.r]=1;
//                cout<<er[kn].r<<endl;
                    kn+=1;
                }
            }
            if(stegs[j].nolln%3!=2){
                steg na=hog(stegs[j]);
                if(!tagen[na.r]){
                    if(na.r==mal){svar=i;goto svara;}
                    er[kn]=na;
                    tagen[na.r]=1;
//                cout<<er[kn].r<<endl;
                    kn+=1;
                }
            }
        }
        stegs=er;
        er.assign(1000000,steg());
        kf=kn;
        kn=0;
    }
    svara:
        cout<<svar;
    return 0;
}
steg upp(steg u)
{
    swap(u.r[u.nolln],u.r[u.nolln-3]);
//    u.nollf=u.nolln;
    u.nolln-=3;
    return u;
}
steg ner(steg u)
{
    swap(u.r[u.nolln],u.r[u.nolln+3]);
//    u.nollf=u.nolln;
    u.nolln+=3;
    return u;
}
steg van(steg u)
{
    swap(u.r[u.nolln],u.r[u.nolln-1]);
//    u.nollf=u.nolln;
    u.nolln-=1;
    return u;
}
steg hog(steg u)
{
    swap(u.r[u.nolln],u.r[u.nolln+1]);
//    u.nollf=u.nolln;
    u.nolln+=1;
    return u;
}
