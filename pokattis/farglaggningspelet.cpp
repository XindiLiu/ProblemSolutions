#include <bits/stdc++.h>
#define visall(xxxxx) {cout<<#xxxxx<<":{";for(int aaaaa=0;aaaaa<xxxxx.size();aaaaa++)cout<<xxxxx[aaaaa]<<' ';cout<<"}\n";}
#define visallc(xxxxx) {cout<<#xxxxx<<":{";for(int aaaaa=1;aaaaa<xxxxx.size()-1;aaaaa++)cout<<xxxxx[aaaaa]<<' ';cout<<"}\n";}
#define visa(xxxxx) cout<<#xxxxx<<':'<<xxxxx<<endl;
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int n,m,s,o;
    cin>>n>>m>>s;
    vector<int> c(n+2,0);
    if(n%2==0){
        if(m==1){
            while(s>0){
                cout<<(s+n/2)%n<<endl;
                cin>>s;
            }
        }
        else{
            while(s>0){
                cout<<n-s+1<<endl;
                cin>>s;
            }
        }
    }
    else{
        if(m==2){
            vector<int> l(n,0);
            int mg=n/2+1;
            for(int i=0;i<=mg;i+=2){
                l[i]=i+1;
                l[i+1]=n-i;
            }
            int k=0;
            while(s>0&&k<mg){
                c[s]=1;
                while(c[l[k]]!=0&&k<mg){
                    k++;
                }
                if(k>=mg){goto r2;}
                cout<<l[k]<<endl;
                c[l[k]]=2;
                if(c[l[k]-1]==0)c[l[k]-1]=-2;
                if(c[l[k]+1]==0)c[l[k]+1]=-2;
                cin>>s;
            }
            r2:
            k=2;
            while(s>0){
                c[s]=1;
                while(c[k]!=0)k+=2;
                cout<<k<<endl;
                c[k]=2;
                cin>>s;
            }
        }
        else{
            vector<int> l(n,0);
            int mg=n/2+1;
            for(int i=0;i<mg;i+=2){
                l[i+1]=(i+s)%n+1;
                l[i]=(n-i-1+s)%n+1;
            }
            int k=1;
            while(s>0&&k<mg){
                c[s]=1;
                while(c[l[k]]!=0&&k<mg){
                    k++;
                }
                if(k>=mg){goto r;}
                cout<<l[k]<<endl;
                c[l[k]]=2;
                if(l[k]>1){if(c[l[k]-1]==0)c[l[k]-1]=-2;}
                else {if(c[n]==0)c[n]=-2;}
                if(l[k]<n){if(c[l[k]+1]==0)c[l[k]+1]=-2;}
                else {if(c[1]==0)c[1]=-2;}
                cin>>s;
            }
            r:
            k=l[1]+1;
            if(k==n+1)k=1;
            while(s>0){
                c[s]=1;
                while(c[k]!=0)k=(k+1)%n+1;
                cout<<k<<endl;
                c[k]=2;
                cin>>s;
            }
        }
    }
    return 0;
}
