#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,svar=0;
    scanf("%d",&n);
    int h,b,k;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d",&h,&b,&k);
        if(b>h)svar+=(b-h)*k;
    }
    printf("%d",svar);
    return 0;
}
