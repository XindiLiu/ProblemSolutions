#include <bits/stdc++.h>
using namespace std;
int main()
{
    //ios::synt_with_stdio
    vector<int> start(5),slut(5),ls(5);
    cin>>start[0]>>start[1]>>start[2]>>start[3]>>start[4];
    cin>>slut[0]>>slut[1]>>slut[2]>>slut[3]>>slut[4];
    queue<vector<int>> a;
    int svar;
    int c=0,sc;
    if(start==slut){svar=0;goto svara;}
    for(int i=0;i<5;++i){
        if(start[i]){
            int si=start[i];
            ls=start;
            ls[i]=0;
            for(int j=0;j<si;++j){
                ls[(i+j)%5]++;
            }
            if(ls==slut){svar=1;goto svara;}
            else a.push(ls);
            c++;

            ls=start;
            ls[i]=0;
            for(int j=0;j<si;++j){
                ls[(50+i-j)%5]++;
            }
            if(ls==slut){svar=1;goto svara;}
            else a.push(ls);
            c++;
        }
    }

    for(int k=2;;++k){
        sc=c;
        c=0;
        for(int h=0;h<sc;++h){
            for(int i=0;i<5;++i){
                if(a.front()[i]){
                    int si=a.front()[i];
                    ls=a.front();
                    ls[i]=0;
                    for(int j=0;j<si;++j){
                        ls[(i+j)%5]++;
                    }
                    if(ls==slut){svar=k;goto svara;}
                    else a.push(ls);
                    c++;

                    ls=a.front();
                    ls[i]=0;
                    for(int j=0;j<si;++j){
                        ls[(50+i-j)%5]++;
                    }
                    if(ls==slut){svar=k;goto svara;}
                    else a.push(ls);
                    c++;
                }
            }
            a.pop();
        }
    }
    svara:
        cout<<svar;
        return 0;
}
