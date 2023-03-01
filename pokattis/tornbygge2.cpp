#include <bits/stdc++.h>
#define print(xxxx) {cout<<#xxxx<<'='<<xxxx<<endl;}
#define printv(xxxxx) {cout<<#xxxxx<<'=';for(int xushu=0;xushu<xxxxx.size();++xushu){cout<<xxxxx[xushu]<<' ';}cout<<endl;}

using namespace std;
typedef long long ll;
const int MAXN=100000+5;



int n;
ll w[MAXN];
ll h[MAXN];
ll bredd[MAXN];
ll  a[MAXN];
ll  x[MAXN];
ll dp[MAXN];
ll bit[MAXN];

bool cw(ll a,ll b);
ll sum(int x){
    ll ans=0;
    while(x>0){
        ans=max(ans,bit[x]);
        x-=x&-x;
    }
    return ans;
}

void add(int x,ll p){
    while(x<=n){
        bit[x]=max(bit[x],p);
        x+=x&-x;
    }
}
int main()
{
    scanf("%d",&n);
   // print(n)
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",w+i,h+i);
        bredd[i]=i;

    }

    sort(bredd+1,bredd+n+1,cw);

    bredd[0]=0;h[0]=0;w[0]=0;
    int fi=0;
    for(int i=1;i<=n;i++){
       // print(bredd[i])
        if(h[bredd[i]]==h[bredd[i-1]]&&w[bredd[i]]==w[bredd[i-1]]){
            fi++;
            continue;
        }
        a[i-fi]=h[bredd[i]];
        x[i-1-fi]=a[i-fi];
    }
    n-=fi;
    ll ans=0;
    sort(x,x+n);
 /*   print(n)
    for(int i=1;i<=n;i++)cout<<x[i]<<' ';
        cout<<endl;*/
    for(int i=1;i<=n;i++){
        dp[i]=a[i];
        int tmp=upper_bound( x,x+n,a[i]  )-x-1;
        dp[i]=max( dp[i], dp[i]+sum(tmp)  );
        tmp=lower_bound( x,x+n,a[i]  )-x;
        add(tmp+1,dp[i]);/*
        cout<<i<<' '<<tmp<<endl;
        for(int i=1;i<=n;i++)cout<<bit[i]<<' ';
        cout<<endl;

        for(int i=1;i<=n;i++)cout<<dp[i]<<' ';


        cout<<endl<<endl;
*/
        ans=max(ans,dp[i]);
    }
    printf("%lld",ans);

    return 0;
}

bool cw(ll a,ll b){return w[a]==w[b]?h[a]>h[b]:w[a]>w[b];}
