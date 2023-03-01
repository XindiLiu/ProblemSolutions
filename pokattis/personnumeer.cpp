#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[9];
    int s=0;
    for(int i=0;i<9;i++)scanf("%d",a+i);
    for(int i=0;i<9;i++){
        s+=a[i]*(i%2?7:3);
    }
    s=s%10;
    printf("%d",s);
    return 0;
}
