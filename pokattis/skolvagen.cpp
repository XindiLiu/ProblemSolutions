    #include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<char> vagen(1001,'-');
    int len=0;
    int svar=0;
    char x;
    while(cin.get(x)){
        if(x!='B'){
            vagen[len]=x;
            len+=1;
        }
        else svar+=1;
    }
    int ns=0;
    int i=0;
    while(vagen[i]!='\n')
    {
        if(ns==0){
            if(vagen[i]=='N'&&vagen[i+1]=='N'){
                svar+=1;
                ns=1;

            }
            else if(vagen[i]=='N')svar+=1;

        }
        else{
            if((vagen[i]=='S'&&vagen[i+1]=='S')){
                svar+=1;
                ns=0;
            }
            else if(vagen[i]=='S')svar+=1;
        }
        i++;
    }
    if(ns==1&&vagen[i-1]=='N')svar+=1;
    cout<<svar;
    return 0;
}
