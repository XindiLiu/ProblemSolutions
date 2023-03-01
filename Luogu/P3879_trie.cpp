#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define null (NULL)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// typedef vector<pair<char, node*>> vector<pair<char, node*>>

struct node {
    char c;
    int numchildren = 0;
    vector<pair<char, node*>>* next;
    vi* senteces;
    node(char cc) : c(cc), numchildren(0), next(new vector<pair<char, node*>> ()), senteces(null) {}

    node() : c(0), numchildren(26), next(new vector<pair<char, node*>> (26)), senteces(null) {
        for (int i = 0; i < 26; i++) {
            this->next->at(i) = make_pair(i + 97, new node(i + 97));
        }
    }

};


node root;

void insert(node* nod, string& s, int sentence) {
    node* no = nod;
    int index = 0;
    while (index < s.size()) {
        bool found = false;
        for (int i = 0; i < no->numchildren; i++) { // find existing nodes
            if (no->next->at(i).first == s[index]) {
                no = no->next->at(i).second;
                found = true;
                break;
            }
        }
        if (!found) { // not found, create new
            node* nn = new node(s[index]);
            auto p = make_pair(s[index], nn);
            no->next->push_back(p);
            no->numchildren++;
            no = nn;
        }
        index++;
    }
    if (no->senteces == null) {
        no->senteces = new vi();
        no->senteces->push_back(sentence);
    }
    else {
        if (*(no->senteces->end() - 1) != sentence) {
            no->senteces->push_back(sentence);
        }
    }
};

vi* find(node* nod, string& s) {
    node* no = nod;
    int index = 0;
    while (index < s.size()) {
        bool found = false;
        for (int i = 0; i < no->numchildren; i++) { // find existing nodes
            if (no->next->at(i).first == s[index]) {
                no = no->next->at(i).second;
                index++;
                found = true;
                break;
            }
        }
        if (!found) { // not found, create new
            return null;
        }
    }
    return no->senteces;
}

int main() {
    ios_base::sync_with_stdio(false);
    root = node();

    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        for (int j = 0; j < l; j++) {
            string s;
            cin >> s;
            s += 1;
            insert(&root, s, i + 1);
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        s += 1;
        auto v = find(&root, s);
        if (v == null) {
            cout << endl;
            continue;
        }
        int ii = 0;
        cout << v->at(ii++);
        for (; ii < v->size(); ii++) {
            cout << ' ';
            cout << v->at(ii);
        }
        cout << endl;
    }


    return 0;
}
