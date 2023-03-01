#include <bits/stdc++.h>
using namespace std;
typedef pair<char,int> pci;
bool vin(pci a,pci b);
int main()
{
    vector<pci> A(5);
    vector<pci> B(5);
    for(int i=0;i<5;++i)cin>>A[i].first>>A[i].second;
    for(int i=0;i<5;++i)cin>>B[i].first>>B[i].second;
    int af=0,bf=0,v=0,r;
    for(int i=0;i<5;++i){
        if(!v){
            r=vin(A[i],B[i]);
            v=!r;
            if(A[i].first!=B[i].first){
                for(int j=i;j<5;++j){
                    if(B[j].first==A[i].first)bf=1;
                }
            }
        }
        else{
            r=vin(B[i],A[i]);
            v=r;
            if(A[i].first!=B[i].first){
                for(int j=i;j<5;++j){
                    if(A[j].first==B[i].first)af=1;
                }
            }
        }
    }
    cout<<(v?'B':'A');
    if(af||bf){
        if(af&&bf)cout<<"\nA och B fuskar";
        else if(af&&!bf)cout<<"\nA fuskar";
        else if(!af&&bf)cout<<"\nB fuskar";
    }





    return 0;
}
bool vin(pci a,pci b)
{
    return (a.first==b.first)?(a.second>b.second):1;
}
