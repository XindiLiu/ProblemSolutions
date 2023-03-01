#include <bits/stdc++.h>
#define visa(x) cout<<#x<<':'<<x<<endl;
#define asiv(x) cout<<#x<<':'<<x<<' ';
#define visall(x) cout<<#x<<' ';for(auto i : x)cout<<i<<' ';cout<<endl;
using namespace std;
struct resenar
{
    int s;
    int e;
    int t;
};
int main()
{
    int n,p;
    cin>>n>>p;
    vector<int> stationer(n+1);
    for(int i=1;i<n;i++)cin>>stationer[i];
    vector<resenar> resenarer(p);
    vector<int> resetider(p);
    for(int i=0;i<p;i++){
        cin>>resenarer[i].s;
        cin>>resenarer[i].e;
        cin>>resenarer[i].t;
        int rt=0;
        for(int j=resenarer[i].s;j<resenarer[i].e;j++)rt+=stationer[j]/2;
        resetider[i]=(resenarer[i].t-rt-2)/2;
    }
//    visall(stationer)
//    visall(resetider)
    int testtal=pow(2,(n-2));
    vector<bool> ststop(n+1,1);
    vector<int> mesttid{0,0,0};
    for(int i=0;i<testtal;i++){
        int bi=1;
        for(int j=2;j<n;j++){
            ststop[j]=i&bi;
            bi=bi<<1;
        }
//        visall(ststop)
        int sumres=0;
        for(int j=0;j<p;j++){
//            cout<<j<<' ';
            int mest=count(ststop.begin()+resenarer[j].s+1,ststop.begin()+resenarer[j].e,1);
//            visa(mest)
            if(ststop[resenarer[j].s]&&ststop[resenarer[j].e]&&mest<=resetider[j]){
                for(int k=resenarer[j].s;k<resenarer[j].e;k++)sumres+=stationer[k];
            }
        }
//        visa(sumres)
        if(mesttid[0]<sumres||(mesttid[0]==sumres&&mesttid[1]>count(ststop.begin(),ststop.end(),1))){
                mesttid[0]=sumres;
                mesttid[1]=count(ststop.begin(),ststop.end(),1);
                mesttid[2]=i;
        }
    }
    cout<<mesttid[0]<<endl;
    int bi=1;
    for(int j=2;j<n;j++){
        ststop[j]=mesttid[2]&bi;
        bi=bi<<1;
    }
    int tabeltid=0;
    for(int i=1;i<=n;i++){
        if(ststop[i]){
            cout<<i<<' '<<tabeltid<<endl;
            tabeltid+=2;
        }
        tabeltid+=stationer[i]/2;
    }
    return 0;
}
