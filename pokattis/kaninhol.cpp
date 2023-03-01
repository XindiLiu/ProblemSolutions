#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> bak(const vector<int> a, int n);
vector<int> fram(const vector<int> a, int n);
vector<int> svar(vector<vector<int>> f, vector<vector<int>> e, int n);
int main()
{
    int n;
    cin>>n;
    vector<int> start(n);
    for(int i=n;i>0;i--)
        start[n-i]=i;
    vector<int> slut(n);
    for(int i=0;i<n;i++)
        cin>>slut[i];
    int s1=0;
    int s2=0;
    int s3=0;
    vector<int> sv1(n);
    vector<int> sv2(n);
    vector<vector<int>> svs2;
    vector<vector<int>> svs1;
    for(int i=1;i<n;i++)
    {

        svs1.push_back(fram(start,i));
    }

    for(int i=1;i<n;i++)
    {


        svs2.push_back(bak(slut,i));
    }
    vector<int> ans=svar(svs1,svs2,n);
    cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2];
    return 0;
}

vector<int> bak(const vector<int> a, int n)
{
    vector<int> fore(a.size());
    for(int i=0;i<n;i++)
        fore[a.size()-i-1]=a[i];
    for(int i=n;i<a.size();i++)
        fore[i-n]=a[i];
    return fore;
}
vector<int> fram(const vector<int> a, int n)
{
    vector<int> efter(a.size());
    for(int i=0;i<a.size()-n;i++)
        efter[i+n]=a[i];
    for(int i=a.size()-n;i<a.size();i++)
        efter[a.size()-i-1]=a[i];
    return efter;
}
vector<int> svar(vector<vector<int>> f, vector<vector<int>> e, int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=1;j<n;j++)
        {
            vector<int> x=fram(f[i],j);
            for(int k=0;k<n-1;k++)
            {


                if(x==e[k])
                {
                    vector<int> m={i+1,j,k+1};
                    return m;
                }

            }
        }
    }
    vector<int> fel={0,0,0,0,0};
    return fel;
}
