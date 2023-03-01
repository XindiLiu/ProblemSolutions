#include <bits/stdc++.h>
#define visak(a) cout<<a.komando<<' '<<a.x<<' '<<a.y<<endl;

using namespace std;
struct dspkod
{
    int komando;
    int x=0;
    int y=0;
};
vector<int> minne(256,0);
int main()
{
    int n;
    cin>>n;
    vector<dspkod> koder(n);
    vector<int> input;
    string k;
    int inp;
    for(int i=0;i<n;i++){
        cin>>k;
        if(k[0]=='C'){koder[i].komando=0;cin>>koder[i].x>>koder[i].y;}
        else if(k[0]=='A'){koder[i].komando=1;cin>>koder[i].x>>koder[i].y;}
        else if(k[0]=='S'){koder[i].komando=2;cin>>koder[i].x>>koder[i].y;}
        else if(k[0]=='J'){koder[i].komando=3;cin>>koder[i].x>>koder[i].y;}
        else if(k[0]=='I'){koder[i].komando=4;cin>>koder[i].x;}
        else if(k[0]=='O'){koder[i].komando=5;cin>>koder[i].x;}
        else if(k[0]=='H'){koder[i].komando=6;}
//        cout<<i<<' ';
    }
    while(cin>>inp)input.push_back(inp);
    int inpi=0;
    int i=0;
    while(koder[i].komando!=6){
//        cout<<"i:"<<i<<endl;
        switch(koder[i].komando){
            case 0:{minne[koder[i].y]=koder[i].x;i++;break;}
    //        cout<<"0?"<<endl;
            case 1:{minne[koder[i].y]+=minne[koder[i].x];i++;break;}
    //        cout<<"1?"<<endl;
            case 2:{minne[koder[i].y]-=minne[koder[i].x];i++;break;}
    //        cout<<"2?"<<endl;
            case 3:{if(minne[koder[i].x]){i=koder[i].y;break;}i++;break;}
    //        cout<<"3?"<<endl;
            case 4:{minne[koder[i].x]=input[inpi];inpi++;i++;break;}
    //        cout<<"4?"<<endl;
            case 5:{cout<<minne[koder[i].x]<<endl;i++;break;}
    //        cout<<"5?"<<endl;
        }
    }
    return 0;
}
