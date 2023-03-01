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
	int n;
	cin>>n;
	vi a = vi(n);
	map<int,int> m =map<int,int>();
	for (int i = 0; i < n; i++){
		cin>>a[i];
	}

	int sum = 0;
	for (int i = 0; i < n; i++){
		int ai = a[i];
		if (i == 0) {
			sum += ai;
			m[ai] = ai;
			continue;
		}

		if (m.count(ai)){ // already exist
			continue;
		}
		else {
			
			map<int,int>::iterator it = m.upper_bound(ai);
			int mindiff = INT_MAX;
			if (it != m.end()){
				int upper = it->first;
				mindiff = min(mindiff, abs(upper - ai));
			}
			if (it != m.begin()){
				it--;
				int lower = it->first;
				mindiff = min(mindiff, abs(lower - ai));
			}
			
			sum += mindiff;
			m[ai] = ai;
		}

		
	}
	
	cout<<sum;

	

	return 0;
}
