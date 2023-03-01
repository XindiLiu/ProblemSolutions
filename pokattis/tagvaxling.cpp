#include <bits/stdc++.h>
#define print(xxxx) {cout<<#xxxx<<'='<<xxxx<<endl;}
#define printv(xxxxx) {cout<<#xxxxx<<'=';for(int xushu=0;xushu<xxxxx.size();++xushu){cout<<xxxxx[xushu]<<' ';}cout<<endl;}
#define nej {cout<<"NEJ";return 0;}
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin>>n;
    vector<int> ut(n);
    stack<int> st;
    for(int i=0;i<n;i++)cin>>ut[i];
   // reverse(ut.begin(),ut.end());
    int ii=1;
    for(int i=0;i<n;i++){
        if(ii<=n&&ii<=ut[i]){
            for(int j=ii;j<ut[i];j++){
                st.push(j);
            }
            ii=ut[i]+1;
        }
        else if(ut[i]==st.top()){
            st.pop();
        }
        else nej
    }
    cout<<"JA";
    return 0;
}
