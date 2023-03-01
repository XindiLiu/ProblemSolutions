#include<bits/stdc++.h>
#define visall(xxxxx) {cout<<#xxxxx<<":{";for(int aaaaa=0;aaaaa<xxxxx.size();aaaaa++)cout<<xxxxx[aaaaa]<<',';cout<<"}\n";}
#define visa(xxxxx) cout<<#xxxxx<<':'<<xxxxx<<endl;
using namespace std;
int main()
{
    int m,n;
    cin>>m;
    m*=1000;
    vector<int> a{1,2,5,10,18,31,52,86,141,230,374,607,984,1594,2581,4178,6762,10943,17708,28654,46365,75022,121390,196415,317808,514226,832037,1346266};
    cout<<upper_bound(a.begin(),a.end(),m)-a.begin()+1;

    return 0;
/*
    int i=1,j=1,v=0,ij;
    vector<int> a{1};
    while(v<1000000){
        ij=i+j;
        i=j;j=ij;
        v+=j;
        a.push_back(v);
    }
    visall(a);
    return 0;
    */
}
