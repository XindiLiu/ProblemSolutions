#include <bits/stdc++.h>
#define ruta pair<int,int>
#define visa(a) cout<<'('<<a.first<<','<<a.second<<')'<<endl;
#define show(a) cout<<'('<<a.plats.first<<','<<a.plats.second<<')'<<' '<<a.rik<<' '<<a.steg<<endl;
using namespace std;
struct vand{
    ruta plats;
    char rik;
    int steg;
};
deque<vand> vag;
int r,c;
map<ruta,char> rutor;
map<pair<ruta,char>,int> besokt;
int go();
int main()
{
    cin>>r>>c;
    ruta linshi;
    char * p=new char;
    for(int i=0;i<r;i++){
        linshi.first=i;
        for(int j=0;j<c;j++){
            linshi.second=j;
            cin>>*p;
            rutor[linshi]=*p;
        }
    }
    vand k;
    ruta kj(0,0);
    k.plats=kj;
    k.rik='h';
    k.steg=0;
    vag.push_back(k);
    pair<ruta,char> kk(kj,'h');
    besokt[kk]=0;
    cout<<go();
    return 0;
}
int go(){
    vand q;
    vand va;
    pair<ruta,char> pa;
    while(true){
        va=vag.front();
        if(va.rik=='h'){
            pa.first=va.plats;
            pa.second=va.rik;
            if(besokt[pa]==0||besokt[pa]>va.steg){//platsen har man inte besökt eller det tar mindre steg.
                besokt[pa]=va.steg;
                for(ruta i=va.plats;i.second<=c;i.second+=1){
                    if(rutor[i]=='#'){

                        q.plats.first=i.first;
                        q.plats.second=i.second-1;
                        q.steg=va.steg+1;
                        q.rik='u';
                        vag.push_back(q);
                        q.rik='n';
                        vag.push_back(q);
                        break;
                    }
                    if(rutor[i]==0)return va.steg;
                }
            }
        }
        else if(va.rik=='v'){
            pa.first=va.plats;
            pa.second=va.rik;
            if(besokt[pa]==0||besokt[pa]>va.steg){//platsen har man inte besökt eller det tar mindre steg.
                besokt[pa]=va.steg;
                for(ruta i=va.plats;i.second>=0;i.second-=1){
                    if(rutor[i]=='#'){

                        q.plats.first=i.first;
                        q.plats.second=i.second+1;
                        q.steg=va.steg+1;
                        q.rik='u';
                        vag.push_back(q);
                        q.rik='n';
                        vag.push_back(q);
                        break;
                    }
                }
            }
        }
        else if(va.rik=='n'){
            pa.first=va.plats;
            pa.second=va.rik;
            if(besokt[pa]==0||besokt[pa]>va.steg){//platsen har man inte besökt eller det tar mindre steg.
                besokt[pa]=va.steg;
                for(ruta i=va.plats;i.first<r;i.first+=1){
                    if(rutor[i]=='#'){

                        q.plats.first=i.first-1;
                        q.plats.second=i.second;
                        q.steg=va.steg+1;
                        q.rik='v';
                        vag.push_back(q);
                        q.rik='h';
                        vag.push_back(q);
                        break;
                    }
                    if(rutor[i]==0)return va.steg;
                }
            }
        }
        else if(va.rik=='u'){
            pa.first=va.plats;
            pa.second=va.rik;
            if(besokt[pa]==0||besokt[pa]>va.steg){//platsen har man inte besökt eller det tar mindre steg.
                besokt[pa]=va.steg;
                for(ruta i=va.plats;i.first>=0;i.first-=1){
                    if(rutor[i]=='#'){

                        q.plats.first=i.first+1;
                        q.plats.second=i.second;
                        q.steg=va.steg+1;
                        q.rik='v';
                        vag.push_back(q);
                        q.rik='h';
                        vag.push_back(q);
                        break;
                    }
                    if(rutor[i]==0)return va.steg;
                }
            }
        }
        vag.pop_front();
    }
}
