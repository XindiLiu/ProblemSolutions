#include <bits/stdc++.h>
#define visall(x) {cout<<#x<<' ';for(auto iiii : x)cout<<iiii<<' ';cout<<endl;}
#define visa(x) cout<<#x<<':'<<x<<endl;
#define asiv(x) cout<<#x<<':'<<x<<' ';
#define vipa(x) cout<<'('<<x.first<<','<<x.second<<')'<<endl;
using namespace std;
bool jamforberg(pair<double,double> b1,pair<double,double> b2);
double area(vector<pair<double,double>> bergen,int ab);
int main()
{
    int n;
    cin>>n;
    vector<pair<double,double>> berg(n);
    int bx,by;
    for(int i=0;i<n;i++){
//        visa(i)
        cin>>bx>>by;
        if(by){
        berg[i].first=bx-by;
        berg[i].second=bx+by;
        }
        else{
            i-=1;
            n-=1;
        }

    }
    berg.resize(n);
    sort(berg.begin(),berg.end(),jamforberg);
//    for(auto i : berg)vipa(i)
    vector<pair<double,double>> nyberg(n);
    int bi=1,nbi=0;
    nyberg[0]=berg[0];
    while(bi<n){
//        asiv(bi)asiv(nyberg[nbi].second)visa(nbi)
        if(!(nyberg[nbi].second>=berg[bi].first&&nyberg[nbi].second>=berg[bi].second)){
//            vipa(berg[bi])
            nbi++;
            nyberg[nbi]=berg[bi];
        }
        bi++;
    }
    nyberg.resize(nbi+1);
//    visa(nbi+1)
//    for(auto i : nyberg)vipa(i)
    cout.setf(ios::showpoint);
    cout.precision(6);
    cout.setf(ios::fixed);
    cout<<area(nyberg,nbi+1);
    return 0;
}
bool jamforberg(pair<double,double> b1,pair<double,double> b2)
{
    if(b1.first!=b2.first)return b1.first<b2.first;
    else return b1.second>b2.second;
}
double area(vector<pair<double,double>> bergen,int ab)
{
//    visa(ab)
//    for(auto i : bergen)vipa(i)
    double anb=0;
    for(auto i: bergen)anb+=pow((i.second-i.first)/2,2);
    vector<pair<double,double>> nyberg(ab);
    int nyab=0;
    for(int i=0;i<ab-1;i++){
        if(bergen[i+1].first<bergen[i].second){
//            asiv(i)visa(nyab)
            nyberg[nyab].first=bergen[i+1].first;
            nyberg[nyab].second=bergen[i].second;
//            vipa(nyberg[nyab])
            nyab+=1;
        }
    }
//    visa(nyab)
//    for(auto i : nyberg)vipa(i)
    if(nyab==0)return anb;
    else{
        nyberg.resize(nyab);
//        for(auto i : nyberg)vipa(i)
        for(auto i: nyberg)anb-=pow((i.second-i.first)/2,2);
        return anb;
    }
}
