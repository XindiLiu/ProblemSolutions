#include <bits/stdc++.h>
using namespace std;

int main()
{
    int svar=0;
    int n;
    cin>>n;
    map<string, int> names;
    string name;
    for(int i=0;i<n;i++){
        cin>>name;
        names[name]+=1;
    }
    for(auto i : names){
        if(i.second>1)svar+=1;
    }
    cout<<svar;
    return 0;
}
