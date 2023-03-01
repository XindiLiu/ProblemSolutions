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
string post, in;

node * build(string post, string in){
	if (post.size() == 0){
		return NULL;
	}

	char root = post[post.size() - 1];
	int rootin = find(in.begin(), in.end(), root) - in.begin(); // index of root in inorder + 1
	node * p = new node;
	p->c = root;

	if (rootin > 0){ // has left child
		string leftin = string(in, 0, rootin); 
		string leftpost = string(post, 0, rootin);
		p->left = build(leftpost, leftin);
	}

	if (rootin < in.size()){ // has right child
		string rightin = string(in, rootin+1, in.size()-rootin-1);
		string rightpost = string(post, rootin, rightin.size());
		p->right = build(rightpost, rightin);
	}
	return p;
};

string preoder(node * p){
	string s = "";
	s+=p->c;
	if (p->left != NULL) {
		s += preoder(p->left);
	}

	if (p->right != NULL) {
		s += preoder(p->right);
	}

	return s;
	// return postoder(p->left) + postoder(p->right) + (p->c);
};

int main() {
	ios_base::sync_with_stdio(false);
	cin>>in>>post;
	n = in.size();
	node * root = build(post, in);
	
	string post = preoder(root);
	cout<<post;

	return 0;
}

