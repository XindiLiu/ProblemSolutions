#include <bits/stdc++.h>
#define print(xxxx) {cout<<#xxxx<<'='<<xxxx<<endl;}
#define printv(xxxxx) {cout<<#xxxxx<<'=';for(int xushu=0;xushu<xxxxx.size();++xushu){cout<<xxxxx[xushu]<<' ';}cout<<endl;}


using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main()
{
    int n,m,q;
    cin>>n>>m>>q;
    vector<ll> t(n+1,ll(0));
    vector<int> cf(n+1,0);
    vi a(q);
    vi b(q);
    vi ib;
    vi is;
    for(int i=1;i<=n;i++){
        cin>>t[i-cf[i-1]];
        if(t[i-cf[i-1]]==t[i-1-cf[i-1]]){
            cf[i]=cf[i-1]+1;
        }
        else cf[i]=cf[i-1];
    }
    for(int i=0;i<q;i++){
        cin>>a[i]>>b[i];
        a[i]-=cf[a[i]];
        b[i]-=cf[b[i]];
    }
    n-=cf[n];
  /*  print(n)
    printv(cf)
    printv(t)*/
    int v=1,jz=1;//jz=0: >, jz=1: <
    for(int i=2;i<=n;i++){
        if(jz){
            if(t[i]<t[i-1]){
                jz=0;
                if(i-v>m){
                    ib.push_back(v);
                    is.push_back(i);
                }
                v=i-1;

            }
            //else if(t[i]>t[i-1])zh++;
        }
        else{
            if(t[i]>t[i-1]){
                jz=1;
                if(i-v>m){
                    ib.push_back(v);
                    is.push_back(i);
                }
                v=i-1;

            }
           // else if(t[i]<t[i-1])zh++;
        }
    }
    if(n-v+1>m){
        ib.push_back(v);
        is.push_back(n+1);
    }
    //printv(ib);
    //printv(is);
    int si=is.size();
    for(int i=0;i<q;i++){
        if(b[i]-a[i]+1<=m){

            cout<<"ja"<<endl;
            continue;
        }
        int al=lower_bound(ib.begin(),ib.end(),a[i])-ib.begin();
        if(al>0)if(is[al-1]>a[i]){
            if(is[al-1]-a[i]>m){
          //      cout<<1;
                cout<<"nej"<<endl;
                continue;
            }
        }
        if(al!=si)if(b[i]+1-ib[al]>m){
         //  cout<<2;
            cout<<"nej"<<endl;
            continue;
        }

        cout<<"ja"<<endl;

    }

    return 0;
}


/*
8 3 5
1 9 1 6 7 8 9 6
1 1
8 8
4 6
8 8
1 1

*/
