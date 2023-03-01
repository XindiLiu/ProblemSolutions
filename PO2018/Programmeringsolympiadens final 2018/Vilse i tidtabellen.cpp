#include <bits/stdc++.h>
#define print(xxxx) {cout<<#xxxx<<'='<<xxxx<<endl;}
#define printv(xxxxx) {cout<<#xxxxx<<'=';for(int xushu=0;xushu<xxxxx.size();++xushu){cout<<xxxxx[xushu]<<' ';}cout<<endl;}
#define fel {cout<<"fel";return 0;}

using namespace std;
typedef long long ll;
typedef vector<int> vi;
const ll sd=60*60*24;
int main()
{
    int n,m,as=0;
    cin>>n>>m;
    vector<ll> t(n);
    vector<ll> tabel(m);
  /*  vector<ll> st(n);
    vector<ll> stabel(m);*/
    vector<ll> svar(m);
    for(int i=0;i<n;i++){
        cin>>t[i];

    }
    int hh,mm,ss;
    char mh;
    for(int i=0;i<m;i++){
        cin>>hh>>mh>>mm>>mh>>ss;
        tabel[i]=ss+mm*60+hh*3600;
    }/*
    for(int i=0;i<n-1;i++){
        st[i]=t[i+1]-t[i];
    }*/
    for(int i=0;i<n;i++){if(i>0)if(t[i]-t[i-1]>sd)fel
            }/*
    for(int i=0;i<m-1;i++){
        stabel[i]=tabel[i+1]-tabel[i];
    }
    stabel[m-1]=sd+tabel[0]-tabel[m-1];
    printv(st)
    printv(stabel)
    int j;
    if(t[0]==0){

    }

    else{
        for(int i=0;i<m;i++){
            if(stabel[i]==st[0]){
                for(j=1;j<n-1;j++){
                    print(st[j])print(stabel[(i+j)%m])
                    if(st[j]!=stabel[(i+j)%m])break;
                }

                if(j==n-1){
                    print(i)
                    svar[as]=tabel[i]-t[0];
                    if(svar[as]<0)svar[as]+=sd;
                    as++;
                }
            }
        }

    }
  */
    ll tnu,tnutj,j;
    for(int i=0;i<m;i++){
        //cout<<endl;
        //print(i)
        tnu=tabel[i]-t[0];
        if(tnu<0)tnu+=sd;
      //  print(tnu)

        if((i==0?(tabel[i]+sd-tabel[m-1]):(tabel[i]-tabel[i-1]))<=t[0])continue;
        for(j=1;j<n;j++){
            tnutj=tnu+t[j];
           // if(tnutj>sd)tnutj-=sd;
          //  print(tnutj%sd)
        //    print(tabel[(i+j)%m])
            if(tnutj%sd!=tabel[(i+j)%m])break;
        }
    //print(j)
        if(j==n){
            svar[as]=tabel[i]-t[0];
            if(svar[as]<0)svar[as]+=sd;
            as++;
        }

    }


  //  printv(svar)
    if(as==0)cout<<"fel";
    else{
        sort(svar.begin(),svar.begin()+as);
        for(int i=0;i<as;i++){
            hh=svar[i]/3600;
            svar[i]=svar[i]%3600;
            mm=svar[i]/60;
            ss=svar[i]%60;
            if(hh<10)cout<<'0';
            cout<<hh<<':';
            if(mm<10)cout<<'0';
            cout<<mm<<':';
            if(ss<10)cout<<'0';
            cout<<ss<<' ';
        }
    }
    return 0;
}
