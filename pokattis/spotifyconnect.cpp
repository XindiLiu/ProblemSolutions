#include <bits/stdc++.h>
using namespace std;
vector<int> play;
vector<int> paus;
int tidrakning(int t,bool p);
int main()
{
    int n;
    cin>>n;
    int svar=0;
    int tid;
    string enhet;
    string kommando;
    for(int i=0;i<n;i++){
        cin>>tid>>enhet>>kommando;
        if(enhet=="mobile")tid+=100;
        if(kommando=="play")play.push_back(tid);
        else if(kommando=="paus")paus.push_back(tid);
    }
    sort(play.begin(),play.end(),less<int>());
    sort(paus.begin(),paus.end(),less<int>());
    bool pl=false;
    int x=-1;
    int y;
    do{
        if(pl==false){
            y=tidrakning(x,pl);
            svar+=-y;
            pl=true;
        }
        else{
            y=tidrakning(x,pl);
            svar+=y;
            pl=false;
        }
        x=y;
    }while(x!=0);




    cout<<svar;
    return 0;
}
int tidrakning(int t,bool p){
    if(p==false){
        for(auto i : play){
            if(i>t)return i;
        }
        return 0;
    }
    else{
        for(auto i: paus){
            if(i>t)return i;
        }
    }
}
