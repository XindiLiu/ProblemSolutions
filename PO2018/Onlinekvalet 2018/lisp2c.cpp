#include <bits/stdc++.h>
#define print(xxxx) {cout<<#xxxx<<'='<<xxxx<<endl;}
#define printv(xxxxx) {cout<<#xxxxx<<'=';for(int xushu=0;xushu<xxxxx.size();++xushu){cout<<xxxxx[xushu]<<' ';}cout<<endl;}
using namespace std;
int n,i=1;
string lisp;
string c();
int main()
{
    getline(cin,lisp);
    n=lisp.size();
    cout<<c();
    return 0;
}
string c()
{
    int s=i;
    string r="";
    for(;i<n;i++){
        if(lisp[i]==' '){
            r+=lisp.substr(s,i-s)+"(";
            i++;
            s=i;
            break;
        }
        else if(lisp[i]==')'){
            r+=lisp.substr(s,i-s)+"()";
            i++;

            return r;
        }
    }
    s=i;
    for(;i<n;i++){
        if(lisp[i]=='('){
            ++i;
            r+=c();
            s=i;
            break;
        }
        else if(lisp[i]==' '){
            r+=lisp.substr(s,i-s);
            ++i;
            break;
        }
        else if(lisp[i]==')'){
            r+=lisp.substr(s,i-s)+")";
            i++;
            return r;
        }
    }
    s=i;
    for(;i<n;i++){
        if(lisp[i]=='('){
            i++;
            r+=", "+c();
            s=i;
        }
        else if(lisp[i]==' '){
            r+=((i-s==0)?"":(", "+lisp.substr(s,i-s)));

            s=i+1;
        }
        if(lisp[i]==')'){
            r+=((i-s==0)?"":(", "+lisp.substr(s,i-s)))+")";
            i++;

            return r;
        }
    }
}
