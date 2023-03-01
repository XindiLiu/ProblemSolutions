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
	node * left = NULL;
	node * right = NULL;

	char c;
};
int n;
int abc = 0; // index of teams for filling the leaves.
vector<node> treearr;
string pre, in;

node * build(string pre, string in){
	if (pre.size() == 0){
		return NULL;
	}

	char root = pre[0];
	int rootin = find(in.begin(), in.end(), root) - in.begin();
	node * p = new node;
	p->c = root;

	if (rootin > 0){ // has left child
		string leftin = string(in, 0, rootin); 
		string leftpre = string(pre, 1, leftin.size());
		p->left = build(leftpre, leftin);
	}

	if (rootin < pre.size() - 1){ // has left child
		string rightin = string(in, rootin+1, in.size()-rootin-1);
		string rightpre = string(pre, rootin+1, rightin.size());
		p->right = build(rightpre, rightin);
	}
	return p;
};

string postoder(node * p){
	string s = "";
	if (p->left != NULL) {
		s += postoder(p->left);
	}

	if (p->right != NULL) {
		s += postoder(p->right);
	}

	s+=p->c;
	return s;
	// return postoder(p->left) + postoder(p->right) + (p->c);
};

int main() {
	ios_base::sync_with_stdio(false);
	cin>>in>>pre;
	n = in.size();
	node * root = build(pre, in);
	
	string post = postoder(root);
	cout<<post;

	return 0;
}

