#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,s,svar=0;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>s;
        if(n<s)svar++;
        else n-=s;
    }
    cout<<svar;
    return 0;
}
