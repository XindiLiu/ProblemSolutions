#include <bits/stdc++.h>
#define visall(xxxxx) {cout<<#xxxxx<<":{";for(int aaaaa=0;aaaaa<xxxxx.size();aaaaa++)cout<<xxxxx[aaaaa]<<' ';cout<<"}\n";}
#define visa(xxxxx) cout<<#xxxxx<<':'<<xxxxx<<endl;
using namespace std;
int per(int n,int k);
int com(int n,int k);
int main()
{
    std::ios::sync_with_stdio(false);
    map<char,int> a;
    string w;
    int n,len,svar=1;
    cin>>w;
    cin>>n;
    len=w.size();
    vector<string> fel(n);
    for(int i=0;i<n;i++)cin>>fel[i];
    for(int i=0;i<len;i++)a[w[i]]+=1;
    for(int i=0;i<n;i++){//vaje grupp
        int fi=fel[i].size();
        for(int j=0;j<fi;j++){//varje bokstav
            if(a[fel[i][j]]){
                int g=1;
                for(int h=1;h<=min(a[fel[i][j]],fi-1);h++){
                    g+=per(fi-1,h)*com(a[fel[i][j]],h);
                }
                svar*=g;
            }
        }
    }
    cout<<svar-1;
    return 0;
}
int per(int n,int k)
{
    int r=1;
    for(int i=n;i>n-k;i--)r*=i;
    return r;
}
int com(int n,int k)
{
    int r=1;
    for(int i=n;i>n-k;i--)r*=i;
    int d=1;
    for(int i=k;i>1;i--)d*=i;
    return r/d;
}
