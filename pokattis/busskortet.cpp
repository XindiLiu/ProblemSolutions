#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,svar=0;
    cin>>n;
    svar+=n/500;
    n-=500*svar;
    if(n>400)svar+=1;
    else if(n>100)svar+=2;
    else svar+=1;
    cout<<svar;
    return 0;
}
