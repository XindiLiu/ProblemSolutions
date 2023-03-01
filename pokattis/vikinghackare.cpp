#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    map<string,char> d;
    char ch;
    string nummer("    ");
    for(int i=0;i<n;i++){
        cin>>ch>>nummer;

        d[nummer]=ch;

    }
    string kod;
    cin>>kod;
    int len=kod.size();
    string oversattning(len/4,'?');
    for(int i=0;i<len/4;i++){

        if(d[kod.substr(4*i,4)]!=0)oversattning[i]=d[kod.substr(4*i,4)];
    }
    cout<<oversattning;
    return 0;

}
