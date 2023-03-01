#include <bits/stdc++.h>
#define ld long double
#define smg cout<<'?'<<endl;
using namespace std;
const ld pi=3.141592653589793238462643383279502884197169399375105820974;
const ld inf=4;
int main()
{
    int n,r;
    int64_t m;
    cin>>n>>m>>r;
    ld ra=m*2/pow(r,2);
//    ld minvinkel=(m/(pow(r,2)*pi))*(2*pi);
    vector<ld> stolpar(n);
    ld degs;
    for(int i=0;i<n;i++){cin>>degs;stolpar[i]=degs*pi/180;}
    sort(stolpar.begin(),stolpar.end());
    vector<vector<ld>> area(n,vector<ld>(n,0));
    ld areaspara;
    for(int i=0;i<n-1;i++){
        for(int j=i;j<n;j++){
            areaspara=sin(stolpar[j]-stolpar[i]);
            area[i][j]=areaspara;
            area[j][i]=-areaspara;
        }
    }
    ld minarea=inf;
    vector<ld> areasu(n);
    for(int h=0;h<n-3;h++){//h:1st point
        for(int i=h+2;i<n-1;i++){//i:3rd point
            if(i-h>(n-h)/2){
                ld mittvinkel=(stolpar[i]+stolpar[h])/2;
                int vl=n-i-1;
                for(int j=i+1;j<n;j++){//j:4th point
                    areasu[j-i-1]=area[i][j]+area[j][h];
                }
                sort(areasu.begin(),areasu.begin()+vl);
                int k=h+1;
                while(stolpar[k]<=mittvinkel){//k:2nd point
                    ld areakvar=ra-area[h][k]-area[k][i];
                    k++;
                    if(areakvar>areasu[vl-1])continue;
                    int minv4=lower_bound(areasu.begin(),areasu.begin()+vl,areakvar)-areasu.begin();
                    minarea=min(minarea,areasu[minv4]-areakvar);
                    if(!minv4)break;
                }
                k=i-1;
                while(stolpar[k]>mittvinkel){//k:2nd point
                    ld areakvar=ra-area[h][k]-area[k][i];
                    k--;
                    if(areakvar>areasu[vl-1])continue;
                    int minv4=lower_bound(areasu.begin(),areasu.begin()+vl,areakvar)-areasu.begin();
                    minarea=min(minarea,areasu[minv4]-areakvar);
                    if(!minv4)break;
                }

            }
            else {
                int vl=i-h-1;
                ld mittvinkel=stolpar[i]/2+pi;
                for(int j=h+1;j<i;j++){//j:2th point
                    areasu[j-h-1]=area[h][j]+area[j][i];
                }
                sort(areasu.begin(),areasu.begin()+vl);
                int k=i+1;
                while(stolpar[k]<=mittvinkel){//k:2nd point
                    ld areakvar=ra-area[i][k]-area[k][h];
                    k++;
                    if(areakvar>areasu[vl-1])continue;
                    int minv4=lower_bound(areasu.begin(),areasu.begin()+vl,areakvar)-areasu.begin();
                    minarea=min(minarea,areasu[minv4]-areakvar);
                    if(!minv4)break;
                }
                k=n-1;
                while(stolpar[k]>mittvinkel){//k:2nd point
                    ld areakvar=ra-area[i][k]-area[k][h];
                    k--;
                    if(areakvar>areasu[vl-1])continue;
                    int minv4=lower_bound(areasu.begin(),areasu.begin()+vl,areakvar)-areasu.begin();
                    minarea=min(minarea,areasu[minv4]-areakvar);
                    if(!minv4)break;
                }
            }
        }
    }
    ld svar;
    if(minarea==inf){cout<<-1;return 0;}
    else svar=(minarea+ra)*pow(r,2)/2;
    cout.setf(ios::showpoint);
    cout.precision(15);
    cout.setf(ios::fixed);
    cout<<svar;

    return 0;
}
