#include <bits/stdc++.h>
#define visall(xxxxx) {cout<<#xxxxx<<":{";for(int aaaaa=0;aaaaa<xxxxx.size();aaaaa++)cout<<xxxxx[aaaaa]<<' ';cout<<"}\n";}
#define visa(xxxxx) cout<<#xxxxx<<':'<<xxxxx<<endl;
#define ll long long
using namespace std;
vector<ll> f;
vector<ll> sk;
vector<int> s;
bool bj(int a,int b);
int mnn(int a,int b,int t);
int main()
{
    int n,k;
    cin>>n>>k;
    f.resize(n);
    sk.resize(n-1);
    s.resize(n-1);
    vector<int> c(2);
    c[0]=-1;
    c[1]=n-1;
    for(int i=0;i<n;i++)cin>>f[i];
    sort(f.begin(),f.end());
    for(int i=0;i<n-1;i++){
        sk[i]=f[i+1]-f[i];
        s[i]=i;
    }
    sort(s.begin(),s.end(),bj);
    /*
    visall(f)
    visall(sk)
    visall(s)
    */
    int v=n>>1,i=-1;
    while(v>=k){
        i++;
        auto iter=lower_bound(c.begin(),c.end(),s[i]);
        v-=mnn(*(iter-1),*iter,s[i]);
        c.insert(iter,s[i]);
   //     visa(v)
     //   visall(c)
    }
    cout<<sk[s[i]]+1;
    return 0;

}
bool bj(int a,int b){return sk[a]>sk[b];}
int mnn(int a,int b,int t)
{
    if((b-a-1)%2==0)return 0;
    else{
        if((t-a-1)%2==0)return 1;
        else return 0;
    }
}
/*
n=12
k=3
1 2 5 6 12 15 21 23 67 72 73 78
 1 2 1 6  3  6  2 44  5  1  5
*/
