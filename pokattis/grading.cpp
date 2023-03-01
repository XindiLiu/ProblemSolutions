#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    vector<int> b(5);
    for(int i=0;i<5;i++)cin>>b[i];
    int p;
    cin>>p;
    cout<<char('F'-(upper_bound(b.rbegin(),b.rend(),p)-b.rbegin()));
    return 0;
}
