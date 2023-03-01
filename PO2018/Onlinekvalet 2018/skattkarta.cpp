#include <bits/stdc++.h>
using namespace std;
void f(int x,int y);
int r,c;
vector<string> k,a;
string svar;
int main()
{

    cin>>r>>c;
    k.resize(r);

    for(int i=0;i<r;i++){cin>>k[i];}
    a.assign(r,string(c,0));

    f(0,0);
    cout<<svar;
    return 0;
}
void f(int x,int y)
{
    if(a[x][y]){svar="cykel";return;}
    else a[x][y]=1;
    switch(k[x][y]){
        case('<'):{f(x,y-1);break;}
        case('>'):{f(x,y+1);break;}
        case('v'):{f(x+1,y);break;}
        case('^'):{f(x-1,y);break;}
        case('A'):{svar="sushi";return;break;}
        case('B'):{svar="samuraj";return;break;}
    }
}
