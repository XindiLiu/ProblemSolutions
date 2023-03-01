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
string pre, post;

node * build(string pre, string post){
	if (pre.size() == 0){
		return NULL;
	}
	char r = pre[0];
	node *p = new node;
	p->c = r;
	if (pre.size() == 1){
		return p;
	}

	
	char lroot = pre[1];
	int lrootpost = find(post.begin(), post.end(), lroot) - post.begin();

	string leftpost = post.substr(0, lrootpost+1); 
	string leftpre = pre.substr(1, lrootpost+1); 
	p->left = build(leftpre, leftpost);

	if (lrootpost + 1 < pre.size() - 1){ // has left child
		string rightpost = post.substr(lrootpost+1, post.size()-lrootpost-2); 
		string rightpre = pre.substr(lrootpost+2, lrootpost+1); 
		p->right = build(rightpre, rightpost);
	}
	return p;
};

int find_single(node *p){
	if (p->left == NULL && p->right == NULL){
		return 0;
	}
	else if (p->left != NULL && p->right == NULL){
		return find_single(p->left)+1;
	}
	else{
		return find_single(p->left)+find_single(p->right);
	}
};



int main() {
	ios_base::sync_with_stdio(false);
	cin>>pre>>post;
	n = pre.size();
	node * root = build(pre, post);

	int exp = find_single(root);
	int ans=1;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (pre[i] ==post[j] && pre[i+1] == post[j-1] ){
				ans *= 2;
			}
		}
		
	}
	
	cout<<ans;
	return 0;
}

