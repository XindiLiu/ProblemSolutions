#include <bits/stdc++.h>
#define visall(xxxxx) {cout<<#xxxxx<<":{";for(int aaaaa=0;aaaaa<xxxxx.size();aaaaa++)cout<<xxxxx[aaaaa]<<' ';cout<<"}\n";}
#define visa(xxxxx) cout<<#xxxxx<<':'<<xxxxx<<endl;
using namespace std;
const int inf=999999999;
int main()
{
    int pa,ka,pb,kb,n;
    cin>>pa>>ka>>pb>>kb>>n;
    vector<int> f(n+1,inf);
    vector<pair<int,int>> a(n+1);
    for(int i=1;i<=n;i++){
        if(ka>=i){
            f[i]=pa;
            a[i].first=1;
            a[i].second=0;
        }
        else if(f[i-ka]+pa<f[i]){
            f[i]=f[i-ka]+pa;
            a[i].first=a[i-ka].first+1;
            a[i].second=a[i-ka].second;
        }
        //visa(i)
        //visa(f[i])visa(a[i].first)visa(a[i].second)
    }
    for(int i=1;i<=n;i++){
        if(ka>=i){
            if(f[i]>pa){
                f[i]=pa;
                a[i].first=0;
                a[i].second=1;
            }
        }
        else if(f[i-kb]+pb<f[i]){
            f[i]=f[i-kb]+pb;
            a[i].first=a[i-kb].first;
            a[i].second=a[i-kb].second+1;
        }
      //  visa(i)
       // visa(f[i])visa(a[i].first)visa(a[i].second)
    }
    cout<<a[n].first<<' '<<a[n].second<<' '<<f[n];
    return 0;
}
//960 13 995 14 150
