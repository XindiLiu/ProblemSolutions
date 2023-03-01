#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n=0,s=0;
    scanf("%d",&n);
    vector<int> a(n);
    for(int i=0;i<n;++i)scanf("%d",&a[i]);
    for(int i=n-2;i>=0;--i){
        for(int j=i+1;j<n;++j){
            if(a[i]>a[j])++s;
        }
    }
    printf("%d",s);
    return 0;

}
