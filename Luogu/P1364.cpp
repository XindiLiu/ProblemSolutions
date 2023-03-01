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
    ll w = 0; // number of people
    ll distforw = 0; // distance from all subnodes to this node
    ll distback = 0; // distance from all non subnodes to this node
    ll pplforw = 0; // sum of people in the subtree
    ll pplback = 0; // sum of people in the non subnodes
	int depth = 0;
};
int n;
int root;
vector<node> treearr;
vector<ll> ans;
void forward(int i, int depth){
	if  (i == 0){
		return;
	}
    node *p = &treearr[i];
    forward(p->l, depth+1);
    forward(p->r, depth+1);

    node lc = treearr[p->l];
    node rc = treearr[p->r];

    p->distforw = lc.distforw + rc.distforw + lc.pplforw + rc.pplforw;
    p->pplforw = lc.pplforw + rc.pplforw + p->w;
    p->depth = depth;
};

void backward(int i){

    node p = treearr[i];
    node *lc = &treearr[p.l];
    node *rc = &treearr[p.r];
    if  (p.l != 0){
		
        lc->pplback = rc->pplforw + p.pplback + p.w;
        lc->distback = rc->distforw + rc->pplforw * ll(2) + p.distback + p.pplback + p.w;
        backward(p.l);
	}

    if  (p.r != 0){
		
        rc->pplback = lc->pplforw + p.pplback + p.w;
        rc->distback = lc->distforw + lc->pplforw * ll(2) + p.distback + p.pplback + p.w;
        backward(p.r);
	}
    
};


int main() {
	ios_base::sync_with_stdio(false);
	cin>>n;
	treearr = vector<node>(n+1);
    ans = vector<ll>(n+1);
	for (int i = 1; i <= n; i++) {
		int w,l,r;
		cin>>w>>l>>r;
        treearr[i].w = w; 
		treearr[i].l = l;
		treearr[i].r = r;
        treearr[r].parent = i;
        treearr[l].parent = i;
	}

	for (int i = 1; i <= n; i++) {
        if (treearr[i].parent == 0){
            root = i;
            break;
        }
    }

    forward(root, 0);
    backward(root);
    for (int i = 1; i <= n; i++) {
        ans[i] = treearr[i].distforw + treearr[i].distback;
    }

    ll a = *min_element(ans.begin()+1, ans.end());
    cout<<a;
	return 0;
}
