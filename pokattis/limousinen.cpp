#include <bits/stdc++.h>
using namespace std;
#define alla(i,v) for(auto i : v)
int main()
{
    int n;
    int t;
    cin>>n;
    cin>>t;
    int x;
    int y;
    int r=t;
    int svar=0;
    vector<int> elev;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        cin>>y;
        int len=(abs(x)+abs(y))*2;
        if(len<=t)
            elev.push_back(len);
    }
    sort(elev.begin(),elev.end());
    alla(i,elev)
    {
        if(i<=r)
        {
            r-=i;
            svar+=1;
        }
        else
            break;

    }
    cout<<svar;
    return 0;
}
