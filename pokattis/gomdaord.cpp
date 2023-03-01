#include <iostream>
#include <string>
using namespace std;
const string bokstaver="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main()
{
    string text;
    cin>>text;
    string out;
    int i=0;
    while(i<text.length()-1)
    {
        int n=bokstaver.find(text[i])+1;
        out+=text[i];
        i+=n;
    }
    out+=text[text.length()-1];
    cout<<out;
    return 0;
}
