#include <bits/stdc++.h>
#define visall(xxxxx) {cout<<#xxxxx<<":{";for(int aaaaa=0;aaaaa<xxxxx.size();aaaaa++)cout<<xxxxx[aaaaa]<<' ';cout<<"}\n";}
#define visa(xxxxx) cout<<#xxxxx<<':'<<xxxxx<<endl;
#define int64_t long long
using namespace std;
const long long no=0;
int64_t sabs(int64_t n);
int main()
{
    int n;
    int64_t svar,s;
    cin>>n;
    vector<int64_t> a(n);
    vector<int64_t> b(n);
    for(int i=0;i<n;i++)scanf("%lld",&a[i]);
    for(int i=0;i<n;i++)scanf("%lld",&b[i]);
    s=accumulate(a.begin(),a.end(),no)-accumulate(b.begin(),b.end(),no);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    auto t=b.begin();
    svar=sabs(s-(a[0]-b[0])*2);
    for(int i=0;i<n;i++){
        int64_t fj=a[i]-s/2+1;
//        cout<<a[i]<<' '<<fj<<endl;
        t=lower_bound(b.begin(),b.end(),fj);
        if(t!=b.end()){
            svar=min(svar,sabs(s-(a[i]-*t)*2));
//            cout<<*t<<' '<<svar<<endl;
        }
        if(t!=b.begin()){
            svar=min(svar,sabs(s-(a[i]-*(t-1))*2));
//            cout<<*(t-1)<<' '<<svar<<endl;
        }
//        cout<<endl;
    }
    cout<<svar;
    return 0;
}
int64_t sabs(int64_t n)
{
    return n>=0?n:-n;
}
