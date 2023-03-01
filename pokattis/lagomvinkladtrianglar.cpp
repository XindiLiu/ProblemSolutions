#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,svar=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            double c=sqrt((pow(i,2)+pow(j,2)-i*j));
            if(c-int(c)==0&&i+j>c&&i+c>j&&j+c>i){
                //cout<<i<<' '<<j<<' '<<c<<endl;
                svar+=1;
            }
        }
    }
    cout<<svar;
    return 0;
}
