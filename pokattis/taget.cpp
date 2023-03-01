#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int f(int a);
int main()
{
    int n,ans=0;
    scanf("%d",&n);
    v.assign(n+1,0);
    v[1]=1;v[2]=1;v[3]=2;
    vector<int> gm{1,2,3,3,2,1};
    for(int i=(n>5?n-5:1); i<=n; ++i){
        ans+=f(i)*gm[n-i];
        //cout<<i<<' '<<f(i)*gm[n-i]<<endl;
    }
    printf("%d",ans);
    return 0;
}
int f(int a)
{
    if(v[a]==0)v[a]=f(a-1)+f(a-2);
    return v[a];
}
