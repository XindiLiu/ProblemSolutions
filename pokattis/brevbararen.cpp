#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    cin>>a;
    int n=a.size();
    vector<int> f(n,0);
    vector<int> b(n);
    f[0]=1;
    for(int i=0;i<n;i++)b[i]=i;
    int sv=1;
    int sx=0;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[i]>a[j]){
                if(f[j]>f[i]){
                    f[i]=f[j];
                    b[i]=j;
                }
            }
        }
        f[i]+=1;
        if(f[i]>sv){
            sv=f[i];
            sx=i;
        }
    }
    string svar=a.substr(sx,1);
    while(f[sx]>1){
        sx=b[sx];
        svar+=a[sx];
    }
    reverse(svar.begin(),svar.end());
    cout<<svar;
    return 0;
}
//KBWZSROCFUJDEILANTMYGVXHPQ
