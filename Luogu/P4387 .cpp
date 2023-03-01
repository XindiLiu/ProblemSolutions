#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	ios_base::sync_with_stdio(false);
	int q;
	cin>>q;
	for (int iiii = 0; iiii < q; iiii++) {
		int n;
		cin>>n;
		vi pushed = vi(n);
		vi poped = vi(n);
		vi stack1 = vi(n, 0);
		int stack_size = 0;
		for (int i = 0; i < n; i++) {
			cin>>pushed[i];
		}
		for (int i = 0; i < n; i++) {
			cin>>poped[i];
		}
		
		int j = 0;
		for (int i = 0; i < n; i++) {
			stack1[stack_size] = pushed[i];

			while (stack_size >= 0 && stack1[stack_size] == poped[j] ){
				stack1[stack_size--] = 0;
				j++; 
			}
			stack_size++;
		} 
		if (j == n){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	}
	
	return 0;
}
