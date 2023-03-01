#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int np=0,nm=0;
    int svar=0;
    vector<int> pbocker(n,0);
    vector<int> mbocker(n,0);
    int input;
    for(int i=0;i<n;i++){
        cin>>input;
        if(input==0)continue;
        if(input<0){mbocker[nm]=-input;nm++;}
        else{pbocker[np]=input;np++;}
    }
    int gp=np%k;
    int gm=nm%k;
    pbocker.resize(np);
    mbocker.resize(nm);
    sort(pbocker.begin(),pbocker.end());
    sort(mbocker.begin(),mbocker.end());

    for(int i=gp-1;i<np;i+=k){
        svar+=pbocker[i]*2;
    }
    for(int i=gm-1;i<nm;i+=k){
        svar+=mbocker[i]*2;
    }
    svar-=max(pbocker[np-1],mbocker[nm-1]);
    cout<<svar;
    return 0;
}
