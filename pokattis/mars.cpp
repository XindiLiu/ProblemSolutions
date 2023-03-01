#include <bits/stdc++.h>
using namespace std;
char kodning(float v1,float v2);
int main()
{
    int n;
    cin>>n;
    vector<char> kod;
    for(int i=0;i<n;i+=2)
    {
        float vinkel1;
        float vinkel2;
        cin>>vinkel1;
        cin>>vinkel2;
        kod.push_back(kodning(vinkel1,vinkel2));
    }

    for(auto i : kod)cout<<i;

    return 0;
}
char kodning(float v1,float v2)
{
    int v1_=v1/22.5;
    int v2_=v2/22.5;
    int d;
    d=v1_*16+v2_;
    return char(d);
}
