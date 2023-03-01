#include <bits/stdc++.h>
using namespace std;
long long cookies(int n,int a[]);

long long cookies(int n,int a[]){
    long long r=0;
    for(int i=0;i<n;i++)r+=a[i];
    return r;
}
