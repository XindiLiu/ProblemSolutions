#include <bits/stdc++.h>
using namespace std;
bool b(pair<int,int> a,pair<int,int> b);
int main()
{
    int n,m,svar=0;
    scanf("%d%d",&n,&m);
    vector<pair<int,int>> p(m);
    for(int i=0;i<m;i++)scanf("%d%d",&p[i].first,&p[i].second);
    sort(p.begin(),p.end(),b);
    for(int i=0;i<m;i++){
        if(n>p[i].second){
            n-=p[i].second;
            svar+=p[i].first*p[i].second;
        }
        else{
            svar+=p[i].first*n;
            break;
        }
    }
    cout<<svar;
}
bool b(pair<int,int> a,pair<int,int> b){return a.first<b.first;}
