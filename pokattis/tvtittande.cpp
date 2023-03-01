#include <bits/stdc++.h>
#define visall(x) {cout<<#x<<' ';for(auto iiii : x)cout<<iiii<<' ';cout<<endl;}
#define visa(x) cout<<#x<<':'<<x<<endl;
#define asiv(x) cout<<#x<<':'<<x<<' ';
#define vipa(x) cout<<'('<<x.first<<','<<x.second<<')'<<endl;
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<vector<pair<int,int>>> reklamer(n,vector<pair<int,int>>(1440,pair<int,int>(-1,-1)));
    string in;
    int inin;
    for(int i=0;i<n;i++){
        cin>>reklamer[i][0].first;
        for(int j=1;j<=reklamer[i][0].first;j++){
            cin>>in;
            reklamer[i][j].first=(int(in[0])-48)*600+(int(in[1])-48)*60+(int(in[3])-48)*10+(int(in[4])-48);
            reklamer[i][j].second=(int(in[6])-48)*600+(int(in[7])-48)*60+(int(in[9])-48)*10+(int(in[10])-48);
        }
    }
    int kanal=0,tid=0;
    vector<int> tvtid(n,0);
    int sluttid;
    loop:
        for(int j=1;j<=reklamer[kanal][0].first;j++){
            if(reklamer[kanal][j].second>=tid){
                if(reklamer[kanal][j].first<=tid){
                    tid+=1;
                    kanal=(kanal+1)%n;
                    goto loop;
                }
                else{
                    tvtid[kanal]+=reklamer[kanal][j].first-tid;
                    tid=reklamer[kanal][j].first+1;
                    kanal=(kanal+1)%n;
                    goto loop;
                }
            }
        }
    tvtid[kanal]+=1440-tid;
    for(auto i : tvtid)cout<<i<<endl;
    return 0;
}
