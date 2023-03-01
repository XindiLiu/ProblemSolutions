#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int n;
    int m;
    cin>>n;
    cin>>m;
    vector<int> ms;
    int svar=0;
    ms.push_back(1);
    int x;
    for(int i=0;i<m;i++)
    {
        cin>>x;
        ms.push_back(x);
    }
    for(int i=0;i<m;i++)
    {

        int p=(ms[i+1])-(ms[i]);
        if (p<0)
            p=-p;
        int q=n-p;
        if(p<q)
            svar+=p;
        else
            svar+=q;
    }
    cout<<svar;
    return 0;

}
