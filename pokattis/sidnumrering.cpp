#include <bits/stdc++.h>
#define visa     for(auto iiiii : svar)cout<<iiiii<<' ';cout<<endl;
using namespace std;
int main()
{
    string sn;
    cin>>sn;
    int64_t n=0;
    int len=sn.size();
    for(int i=0;i<len;i++){
        double w=pow(10,len-i-1);
        n+=(int(sn[i])-48)*w;
    }
    vector<int64_t> svar(10,0);
    for(int i=0;i<len;i++){
        double wp=pow(10,i);
        int64_t sg=(n/wp-1)/10;
        int ti=n/wp-sg*10;
        int64_t mg=(n%int64_t(wp)+1)/2;
        double mp;
        if(i==0){
            for(int j=1;j<10;j+=2)svar[j]+=sg;
            for(int j=1;j<=ti;j+=2)svar[j]+=1;
        }
        else{
            mp=pow(10,i-1)*5;
            for(int j=0;j<10;j++)svar[j]+=sg*mp;

            int j=1;
            while(j<ti){
                svar[j]+=mp;
                j++;
            }
            svar[ti%10]+=mg;
        }
    }
    visa
    return 0;
}
