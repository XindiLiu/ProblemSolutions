#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    if(a<b)swap(a,b);

    int aa=a;
    vector<int> as(1000000,-1);
    as[a]=0;
    int i=0;
    while(aa!=1){
        if(aa%6==4){as[aa]=i;aa/=2;}
        else{
            if(aa%2==0)aa/=2;
            else aa=aa*3+1;
        }
        i+=1;
    }
    as[1]=i;
    int ba=b;
    i=0;
    while(as[ba]==-1){
        if(ba%2==0)ba/=2;
        else ba=ba*3+1;
        i+=1;
    }
    int svar=i+as[ba];
    cout<<svar;
    return 0;

}

