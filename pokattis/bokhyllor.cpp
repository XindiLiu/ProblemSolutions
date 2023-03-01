#include <bits/stdc++.h>
#define visall(x) {cout<<#x<<' ';for(auto iiii : x)cout<<iiii<<' ';cout<<endl;}
#define visa(x) cout<<#x<<':'<<x<<endl;
#define asiv(x) cout<<#x<<':'<<x<<' ';
using namespace std;
int main()
{
    vector<int> ab(3);
    int s;
    cin>>ab[0]>>ab[1]>>ab[2]>>s;
    for(int i=0;true;i++){
        int k=0;
        int rest=s;
        if(ab[2]>0&&ab[2]!=0){
            int ab2=s/3;
            if(ab[2]<ab2){
                rest-=ab[2]*3;
                ab[2]=0;
            }
            else{
                ab[2]-=ab2;
                rest-=ab2*3;
            }

        }
        else k+=1;
        int ab1=rest/2;
        if(ab1>0&&ab[1]!=0){
            if(ab[1]<ab1){
                rest=rest-ab[1]*2;
                ab[1]=0;
            }
            else{
                ab[1]-=ab1;
                rest=rest-ab1*2;
            }

        }
        else k+=1;
        if(rest>0&&ab[0]!=0){
            if(ab[0]<rest){
                ab[0]=0;
            }
            else{
                ab[0]-=rest;
            }

        }
        else k+=1;
        if(k==3){
            cout<<i;
            return 0;
        }
    }
}
