#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int m;
    int s=0;
    for(int i=1;i<=n;i++){
        cin>>m;
        if(m>7)m=7;
        if(i%2==0){
            s+=(m-3);
        }
        else s+=(m-2);
    }
    cout<<s;
    return 0;
}
