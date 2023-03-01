#include <bits/stdc++.h>
using namespace std;
const int inf=1000000000;
int main()
{
    int n,t;
    cin>>n>>t;
    int maxt=t+60000;
    vector<int> banor(n*2);
    vector<int> beibao(maxt+1,inf);
    vector<int> sp(maxt+1,inf);
    beibao[0]=0;
    for(int i=0;i<n;i++){cin>>banor[i];banor[i+n]=banor[i]*1.5;}
    int mintid=inf;
    for(int i=0;i<n*2;i++){
        int k=(i<n)?1:2;
//        cout<<i<<'{'<<endl;
        int it=min(t,mintid-banor[i]);
        int banorij=banor[i];
        for(int j=0;j<=it;j++,banorij++){
            if(beibao[j]+k<beibao[banorij]){
//                cout<<j<<' ';
                beibao[banorij]=beibao[j]+k;
                sp[banorij]=i;
                if(banorij>=t)mintid=min(banorij,mintid);
//                cout<<banorij<<' '<<beibao[banorij]<<endl;
            }
        }
//        cout<<'}'<<endl;
    }
    vector<int> springa(n,0);
    cout<<mintid<<' '<<beibao[mintid]<<endl;
    int i=mintid;
    while(i>0){
        springa[sp[i]%n]+=banor[sp[i]];
        i-=banor[sp[i]];
    }
    for(int j=0;j<n;j++)cout<<springa[j]<<' ';
    return 0;
}
