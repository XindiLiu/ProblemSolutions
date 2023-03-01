#include <bits/stdc++.h>
using namespace std;
const int inf=999999;
int n,v;
int minx=0,miny=0,mina=0;
vector<vector<int>> vagmatris;
vector<bool> gatt;
vector<vector<int>> d;
void dijkstra();
int main()
{
    cin>>n>>v;
    vagmatris.assign(n+1,vector<int>(n+1,inf));

    d.assign(n+1,vector<int>(n+1,inf));
    int ins,ine,inl;
    for(int i=0;i<v;i++){
        cin>>ins>>ine>>inl;
        vagmatris[ins][ine]=inl;
        vagmatris[ine][ins]=inl;
    }
    dijkstra();
    /*
    cout<<"  ";
    for(int i=1;i<=n;i++)cout<<i<<' ';
    cout<<endl;
    for(int i=1;i<=n;i++){
        cout<<i<<' ';
        for(int j=1;j<=n;j++){
            cout<<d[i][j]<<' ';
        }
        cout<<endl;
    }
    */
    if(minx>miny)swap(minx,miny);
    cout<<minx<<' '<<miny<<' '<<mina*100;
    return 0;
}
void dijkstra()
{
    for(int k=1;k<n;k++){
        d[k][k]=0;
        gatt.assign(n+1,0);
        for(int i=1;i<=n;i++){
            int x,m=inf;
            for(int j=1;j<=n;j++)if(!gatt[j]&&d[k][j]<=m){m=d[k][j];x=j;}
            gatt[x]=1;
            for(int j=1;j<=n;j++)d[k][j]=min(d[k][j],d[k][x]+vagmatris[x][j]);
        }
        for(int i=1;i<=n;i++)d[i][k]=d[k][i];
        vector<int>::iterator mak=max_element(d[k].begin()+1,d[k].end());
        if(*mak>mina){mina=*mak;minx=k;miny=mak-d[k].begin();}
    }
//    for(int i=1;i<=n;i++)cout<<d[i]<<' ';
    return;
}
/*
int minvag(int x,int y)
{
    if(x==y)return 0;
    if(x>y)swap(x,y);
    cout<<x<<'-'<<y<<'{'<<endl;
    if(vagmatris[x][y]>=0){cout<<vagmatris[x][y]<<'}'<<endl;return vagmatris[x][y];}
    int minvxi=500000000;
    for(int i=1;i<=n;i++){
        if(vagmatris[x][i]>=0&&!gatt[i]){
            gatt[i]=1;
            minvxi=min(minvxi,vagmatris[x][i]+minvag(i,y));
            gatt[i]=0;
        }
    }
    vagmatris[x][y]=minvxi;
    vagmatris[y][x]=minvxi;
    cout<<x<<'-'<<y;
    cout<<minvxi<<'}'<<endl;
    return minvxi;
}
*/
