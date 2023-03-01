#include <bits/stdc++.h>
#define visall(xxxxx) {cout<<#xxxxx<<":{";for(int aaaaa=0;aaaaa<sizeof(xxxxx) / sizeof(xxxxx[0]);aaaaa++)cout<<xxxxx[aaaaa]<<' ';cout<<"}\n";}
#define visa(xxxxx) cout<<#xxxxx<<':'<<xxxxx<<endl;
using namespace std;
const int inf=999999999;
int n,k,s=1,s2;
vector<int> a;
vector<int> tid;
struct bt
{
    int m=inf;
    bt * v;
    bt * h;
};
vector<bt> tr;
int bildatrad(int x);
int ps(int r,bt * t);
void gx(int x);
int main()
{
    scanf("%d%d",&n,&k);
    if(n==1){cout<<0;return 0;}
    a.resize(n);
    tid.resize(n);
    tr.resize(2*n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    while(s<n)s<<=1;
    s2=s;
    s>>=1;
    int i=0;
    int n2s2=(n<<1)-s2;
    while(i<n2s2){
        tr[i+s2].m=a[i];
        i++;
    }
    int j2=s2-n;
    for(int j=n-1;j>=i;j--){
        tr[j+j2].m=a[j];
    }
    bildatrad(1);
    int p=0,q=0;
    while(q<n&&p<n){
//        visa(p)
        int r=k;
        int z=ps(r,&tr[1]);
//        visa(z)
//        cout<<"-----------------------\n";
        while(z!=-1){
            r-=a[z];
            tid[z]=p;
            q++;
            z=ps(r,&tr[1]);
/*            visa(z)
            cout<<"-----------------------\n";
            visa(q)*/
        }
        p++;
    }
    for(int i=0;i<n;i++)cout<<tid[i]<<' ';
    return 0;
}
int ps(int r,bt * t)
{
  //  cout<<t-&tr[0]<<' '<<t->m<<endl;
    if(t-&tr[0]<n){
        if((t->v)->m<=r)ps(r,t->v);
        else if((t->h)->m<=r)ps(r,t->h);
        else return -1;
    }
    else {
        int nummer=t-&tr[0];
        t->m=inf;
        gx(nummer>>1);
        return nummer>=s2?nummer-s2:n-(s2-nummer);
    }
}
void gx(int x)
{
    tr[x].m=min((tr[x].v)->m,(tr[x].h)->m);
    if(x!=1)gx(x>>1);
}
int bildatrad(int x)
{
    if(tr[x].m<inf)return tr[x].m;
    tr[x].v=&tr[x<<1];
    tr[x].h=&tr[(x<<1)+1];
    tr[x].m=min(bildatrad(x<<1),bildatrad((x<<1)+1));
    return tr[x].m;
}
