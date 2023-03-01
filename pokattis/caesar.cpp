#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int k,n;
    string a;
    cin>>k;
    cin>>a;
    n=a.size();
    for(int i=0;i<n;i++){
        a[i]-=k;
        if(a[i]<97)a[i]+=26;
    }
    cout<<a;
    return 0;
}
