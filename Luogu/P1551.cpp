#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m,p;
vi parent;
vi setsize;

int find(int x) {
    if (parent[x] == x) {
        return x;
    }
    else {
        int p = find(parent[x]);
        parent[x] = p;
        return p;
    }
};

void setunion(int x, int y) {
    if (parent[x] == parent[y]) {
        return;
    }

    int xp = find(x);
    int yp = find(y);
    if (setsize[xp] > setsize[yp]) {
        parent[yp] = xp;
        setsize[xp] += setsize[yp];
    }
    else {
        parent[xp] = yp;
        setsize[yp] += setsize[xp];
    }
};

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n>> m>>p;
    

    parent = vi(n + 1);
    setsize = vi(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        setunion(x, y);
    }

    for (int i = 1; i <= n; i++) {
        find(i);
    }

    for (int i = 0; i < p; i++) {
        int x, y;
        cin >> x >> y;
        if (parent[x] == parent[y])
        {
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
        
    }
        


}
