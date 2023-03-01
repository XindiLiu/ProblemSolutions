#include <bits/stdc++.h>
using namespace std;
vector<vector<double>> vin11(1024,vector<double>(1024,0));
vector<vector<double>> vin(11,vector<double>(1024,0));
vector<double> formaga;
double san(int xi,int xj);//i besegra j.
int main()
{
    int n;
    cin>>n;
    int an=pow(2,n);
    formaga.resize(an);
    for(int i=0;i<an;i++)cin>>formaga[i];
    for(int i=0;i<an;i++)vin[0][i]=1;
    int anrq=2;
    int anrp=1;
    for(int r=1;r<=n;r++){//varje runda

        for(int s=0;s<an;s++){//varje spelare
            double ms=0;
            int q=s/anrq;//大区
            int p=s/anrp;//小区
            if(p-q*2==0){

                for(int mi=(p+1)*anrp;mi<(q+1)*anrq;mi++){
                    ms+=san(s,mi)*vin[r-1][mi];//sannolikhet att s vinner mi gånger mi går till matchen
                }
            }
            else{
                for(int mi=(p-1)*anrp;mi<p*anrp;mi++){

                    ms+=san(s,mi)*vin[r-1][mi];
                }
            }
            vin[r][s]=ms*vin[r-1][s];//sannolikhet för s går til matchen gånger summa av sannolikhet att vinna för varje möjliga motståndare.
        }
        anrq*=2;
        anrp*=2;


    }
    int svar1=0;
    double svar2=0;
    for(int i=0;i<an;i++){
        if(svar2<vin[n][i]){
            svar2=vin[n][i];
            svar1=i;
        }

    }
    cout<<svar1+1<<' '<<svar2;
    return 0;

}

double san(int xi,int xj)
{



    if(vin11[xi][xj]==0){

        vin11[xi][xj]=1/(1+exp(formaga[xj]-formaga[xi]));
        vin11[xj][xi]=1-vin11[xi][xj];
        return vin11[xi][xj];
    }
    else {return vin11[xi][xj];}
}
