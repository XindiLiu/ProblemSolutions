#include <bits/stdc++.h>
#include <bits/stdc++.h>
#define visall(x) {cout<<#x<<' ';for(auto iiii : x)cout<<iiii<<' ';cout<<endl;}
#define visa(x) cout<<#x<<':'<<x<<endl;
#define asiv(x) cout<<#x<<':'<<x<<' ';
#define vipa(x) cout<<'('<<x.first<<','<<x.second<<')'<<endl;
#define double long double
using namespace std;
vector<pair<double,double>> stenar;
int n;
bool lessp(pair<double,double> a,pair<double,double> b);
double dydx(double x);
double sumdis(double x);
int main()
{
    cin>>n;
    stenar.resize(n);
    for(int i=0;i<n;i++)cin>>stenar[i].first>>stenar[i].second;
    sort(stenar.begin(),stenar.end(),lessp);
    double uppg=stenar[n-1].first,nedg=stenar[0].first;
    double mx;
    for(int i=0;i<100;i++){
        mx=(uppg+nedg)/2;
        double dm=dydx(mx);
//        asiv(mx)visa(dm)
        if(dm==0)break;
        else if(dm>0)uppg=mx;
        else nedg=mx;
    }
    double svar=sumdis(mx);
    cout.setf(ios::showpoint);
    cout.precision(10);
    cout.setf(ios::fixed);
    cout<<svar;
    return 0;
}
bool lessp(pair<double,double> a,pair<double,double> b)
{
    if(a.first==b.first)return a.second<b.second;
    else return a.first<b.first;
}
double dydx(double x)
{
    double svar=0;
    for(int i=0;i<n;i++){
        svar+=(x-stenar[i].first)/sqrt(pow((stenar[i].first-x),2)+pow(stenar[i].second,2));
    }
    return svar;
}
double sumdis(double x)
{
    double svar=0;
    for(int i=0;i<n;i++){
        svar+=sqrt(pow((stenar[i].first-x),2)+pow(stenar[i].second,2));
    }
    return svar*2;
}
