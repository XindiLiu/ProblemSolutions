#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct node {
    node* left = NULL;
    node* right = NULL;

    char c;
};
int m=4, n=0;
int maxbreadth, maxheight; // breadth and height for the figure.
int maxnodeslayer; // max number of nodes in one layer
const char o = 'o';
const char l = '/';
const char r = '\\';
vector<vector<char>> tree;
vector<vector<int>> removed;
// draw a node and its subtree. a = layer, b = number in the layer.
void draw(int a, int b) {
    if (removed[a][b]) {
        return;
    }

    if (a == m) {
        int i = maxheight - 1;
        int j = ((b % 2 == 0) ? -2 : 0) + 6 * floor(b / 2);
        tree[i][j] = o;
        return;
    }
    // node's index in the char array
    int i = maxheight - floor((6 * pow(2, m - a - 1) - 1) / 2) - 1;
    int j = 3 * pow(2, m - a - 1) + (b - 1) * 6 * pow(2, m - a - 1) - 1;
    tree[i][j] = o;

    int edgelen;
    if (a == m - 1) {
        edgelen = 1;
    }
    else {
        edgelen = 3 * pow(2, m - a - 2) - 1;
    }
    // a+1, b*2-1 = left child
    // a+1, b*2 = right child
    if (!removed[a + 1][b * 2 - 1]) { // left not removed
        for (int ii = 1; ii <= edgelen; ii++) { // left edge
            tree[i + ii][j - ii] = l;
        }
        draw(a + 1, b * 2 - 1);
    }

    if (!removed[a + 1][b * 2]) { // right not removed
        for (int ii = 1; ii <= edgelen; ii++) { // right edge
            tree[i + ii][j + ii] = r;
        }
        draw(a + 1, b * 2);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin >> m >> n;
    maxnodeslayer = pow(2, m-1);
    removed = vector<vi>(m + 1, vi(maxnodeslayer + 1, 0));
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        removed[a][b] = 1;
    }
    maxbreadth = (maxnodeslayer / 2) * 6 - 1;
    maxheight = (maxbreadth + 1) / 2; // half of maxbreadth + root in layer 1.
    tree = vector<vector<char>>(maxheight, vector<char>(maxbreadth, ' '));
    for (int i = 1; i < m-1; i++) {
        int r = (6 * pow(2, m - i - 1) - 1) / 2 ;
        int q = maxheight - r - 1;
        int p = q+1;
    }
    
    
    draw(1,1);
    for (int i = 0; i < maxheight; i++) {
        for (int j = 0; j < maxbreadth; j++) {
            cout<<tree[i][j];
        }
        cout<<endl;
    }
    
    return 0;
}

