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
	int left;
	int right;

	int depth;
};
int n;
int abc = 0; // index of teams for filling the leaves.
vector<node> treearr;
int searchdepth(int nodeindex){
	if  (nodeindex == 0){
		return 0;
	}

	return max(searchdepth(treearr[nodeindex].left), searchdepth(treearr[nodeindex].right)) + 1;
};



int main() {
	ios_base::sync_with_stdio(false);
	cin>>n;
	treearr = vector<node>(n+1);
	for (int i = 1; i <= n; i++) {
		int l,r;
		cin>>l>>r;
		treearr[i].left = l;
		treearr[i].right = r;
	}
	cout<<searchdepth(1);
	return 0;
}
