#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int a=0;
    int b=0;
    int n;
    cin>>n;
    for(int i=0;n>0;i++)
    {
        int h1=n/2;
        int h2=n-h1;
        if(i%2==0)
            b+=h2;
        else
            a+=h2;
        n=h1;


    }
    cout<<a<<" "<<b;
    return 0;
}
