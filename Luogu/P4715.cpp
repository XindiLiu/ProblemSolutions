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
	node * parent;
	node * left;
	node * right;
	int data;
	int depth;
};
int n;
int abc = 0; // index of teams for filling the leaves.
vi powerarr;
node * buildtree(int depth, node * p){
	node * a  = new node();
	a->parent = p;
	a->depth = depth;
	if (depth == 0){
		cin>>(a->data);
		powerarr[abc++] = a->data;
	}
	else{
		a->left = buildtree(depth - 1, a);
		a->right = buildtree(depth - 1, a);
	}
	return a;
};

int second(node * p){
	if (p->depth == n) {
		return min(second(p->left), second(p->right));
	}
	else if ((p->depth == 0)){
		return p->data;
	}
	else{
		return max(second(p->left), second(p->right));
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin>>n;
	powerarr = vi(pow(2,n));

	node *tree = buildtree(n, NULL); 

	int anspower = second(tree);

	int ansindex = find(powerarr.begin(), powerarr.end(), anspower) - powerarr.begin() + 1;
	cout<<ansindex;
	return 0;
}

