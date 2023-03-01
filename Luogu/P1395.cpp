#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<ll> vll;

struct edge {
    int to;
    int next;
    edge(int t1, int n1) : to(t1), next(n1) {}
    edge() {}
};

struct node {
    int nsub = 0; // number of nodes in the subtree
    int dis = 0; // sum of distance in the subtree
};
vector<edge> edges;
vector<node> tree;
vi sumdis;
vi head;
int numedges;
int n;
void add(int a, int b) {
    numedges++;
    edges[numedges].to = b;
    edges[numedges].next = head[a];
    head[a] = numedges;
}
void build(int p, int x) {
    for (int e = head[x]; e != 0; e = edges[e].next) {
        int child = edges[e].to;
        if (child != p) {
            build(x, child);
            tree[x].nsub += tree[child].nsub;
            tree[x].dis += tree[child].dis + tree[child].nsub;
        }
    }
    tree[x].nsub += 1; //x itself
}
void dfs(int p, int x) {
    if (p == 0) {
        sumdis[x] = tree[x].dis;
    }
    else {
        sumdis[x] = sumdis[p] + n - 2 * tree[x].nsub;
    }

    for (int e = head[x]; e != 0; e = edges[e].next) {
        int child = edges[e].to;
        if (child != p) {
            dfs(x, child);
        }
    }

}
int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;
    edges = vector<edge>(n * 2);
    head = vi(n + 1, 0);
    tree = vector<node>(n + 1);
    sumdis = vi(n + 1, 0);
    numedges = 0;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    int root = 1;
    build(0, root);
    dfs(0, root);
    int ans1;
    int ans2 = sumdis[root];
    for (int i = 1; i < n; ++i) {
        if (sumdis[i] < ans2) {
            ans1 = i;
            ans2 = sumdis[i];
        }
    }
    cout << ans1 << ' ' << ans2;
    return 0;
}