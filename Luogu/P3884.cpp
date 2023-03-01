#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct node{
	int l = 0;
	int r = 0;
	int parent = 0;
	int depth;
	int conncects [3] = {0,0,0};
	int arsize = 0;
	int distx = -1;
	int disty = -1;
};
int n,x,y;
int abc = 0; // index of teams for filling the leaves.
vector<node> treearr;
string pre, in;
vi bredd = vi (100,0);
int maxdepth  = 0;

void build(int i, int depth){
	if (i == 0) return;
	node * p = &treearr[i];
	for (int j = 0; j < 3; j++) {
		if (p->parent != p->conncects[j]){
			if (p->l == 0){
				p->l = p->conncects[j];
				treearr[(p->l)].parent = i;
			}
			else if (p->r == 0){
				p->r = p->conncects[j];
				treearr[(p->r)].parent = i;
			}
			build(p->conncects[j], depth+1);
		}
	}

	p->depth = depth;
	bredd[depth]++;
	maxdepth = max(maxdepth, depth);
};

int find_lca (int root, int x, int y){
	if (root == 0){
		return 0;
	}

	if (root == x || root == y){
		return root;
	}

	int left = find_lca(treearr[root].l, x, y);
	int right = find_lca(treearr[root].r, x, y);

	if (left != 0 && right != 0 ){
		return root;
	}
	else if (left != 0) {
		return left;
	}
	else if (right != 0) {
		return right;
	}
	else 
		return 0;
};
int main() {
	ios_base::sync_with_stdio(false);
	cin>>n;
	treearr = vector<node>(n+1);
	for (int i = 1; i < n; i++) {
		int u,v;
		cin>>u>>v;
		treearr[u].conncects[treearr[u].arsize++] = v;
		treearr[v].conncects[treearr[v].arsize++] = u;
	}
	cin>>x>>y;

	build(1,0);
	cout<<maxdepth+1<<endl;
	cout<<*max_element(bredd.begin(), bredd.begin() + maxdepth + 1) <<endl;
	int lca = find_lca(1, x, y);
	int distance = (treearr[x].depth - treearr[lca].depth) * 2 + (treearr[y].depth - treearr[lca].depth);
	cout<<distance<<endl;

	return 0;
}

