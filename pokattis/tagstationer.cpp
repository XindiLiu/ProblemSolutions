#include <bits/stdc++.h>
#define visall(xxxxx) {cout<<#xxxxx<<":{";for(int aaaaa=0;aaaaa<xxxxx.size();aaaaa++)cout<<xxxxx[aaaaa]<<' ';cout<<"}\n";}
#define visa(xxxxx) cout<<#xxxxx<<':'<<xxxxx<<endl;
#define fel {cout<<"NEJ";return 0;}
using namespace std;
vector<pair<int,int>> s;
bool j(int a,int b);
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int start=1,slut=n;
    s.resize(n+1);
    vector<int> od(n+1);
    for(int i=1;i<=n;i++)od[i]=i;
    for(int i=1;i<=n;i++)cin>>s[i].first>>s[i].second;
    for(int i=1;i<=slut;i++){
        if(s[i].first==0){
            swap(od[slut],od[i]);
         //   swap(s[i],s[slut]);
            slut-=1;
        }
        else if(s[i].second==0){
            swap(od[start],od[i]);
       //     swap(s[i],s[start]);
            start+=1;
        }
    }
    if(start==1||slut==n)fel
    sort(od.begin()+start,od.begin()+slut+1,j);
    int p=0;
    for(int i=1;i<=n;i++){
        if(s[od[i]].second>p)fel
        else p+=-s[od[i]].second+s[od[i]].first;
    }
    cout<<"JA\n";
    for(int i=1;i<=n;i++)cout<<od[i]<<' ';
    return 0;
}
bool j(int a,int b){
    if(s[a].first-s[a].second>0){
        if(s[b].first-s[b].second>0)return s[a].second<s[b].second;
        else return true;
    }
    else{
        if(s[b].first-s[b].second>0)return false;
        else return s[a].second>s[b].second;
    }
}
