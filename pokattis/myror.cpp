#include <bits/stdc++.h>
#define fel {cout<<"FEL";return 0;}
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n<252 || n>336 || n%2)fel;
    cout<<(336-n)/2;
    return 0;
}
