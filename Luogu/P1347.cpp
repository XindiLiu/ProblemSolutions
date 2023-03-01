#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<string> vs;
int n, m;
const char A = 'A';
void determined(int number_relations, string& seq) { cout << "Sorted sequence determined after " << number_relations << " relations: " << seq << "."; };
void inconsistency(int number_relations) { cout << "Inconsistency found after " << number_relations << " relations."; };
void cannot_determine() { cout << "Sorted sequence cannot be determined."; };
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    vi ingrad, outgrad;
    ingrad = vi(n, 0);
    outgrad = vi(n, 0);

    // bitset<n> visit;

    vvi mtx = vvi(n, vi(n, 0));
    for (int im = 1; im <= m; im++) {
        char ac, bc, less;
        cin >> ac >> less >> bc;
        int a = ac - A;
        int b = bc - A;
        outgrad[a]++;
        ingrad[b]++;

        if (mtx[b][a] != 0 || a == b) { // check rings
            inconsistency(im);
            return 0;
        }

        mtx[a][b] = 1;

        for (int i = 0; i < n; i++) { // all greater than b is greater than a
            if (i != b && i != a && mtx[b][i] == 1) { // i greater than b
                // if (mtx[i][a] == 1) {
                //     inconsistency(im);
                //     return 0;
                // }
                mtx[a][i] = 1;
            }
        }

        for (int i = 0; i < n; i++) { // all less than a is less than b
            if (i != b && i != a && mtx[i][a] == 1) { // i less than a
                // if (mtx[b][i] == 1) {
                //     inconsistency(im);
                //     return 0;
                // }
                mtx[i][b] = 1;
            }
        }

        for (int i = 0; i < n; i++) { // all greater than b is greater than all less than a
            if (i != b && i != a && mtx[b][i] == 1) { // i greater than b
                for (int j = 0; j < n; j++) {
                    if (j != b && j != a && i != j && mtx[j][a] == 1) { // j less than a
                        mtx[j][i] = 1;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) { // all less than a is less than all greater than b
            if (i != b && i != a && mtx[i][a] == 1) { // i less than a
                for (int j = 0; j < n; j++) {
                    if (j != b && j != a && i != j && mtx[b][j] == 1) { // j greater than b
                        mtx[i][j] = 1;
                    }
                }
            }
        }

        bool det = true;
        for (int i = 0; i < n; i++) { // check if path.
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    if (mtx[i][j] == 1 && mtx[j][i] == 1) {
                        inconsistency(im);
                        return 0;
                    }
                    det &= (mtx[i][j] == !mtx[j][i]);
                }
            }
        }

        if (det) { // determine sequence
            string seq = string(n, 0);
            for (int i = 0; i < n; i++) {
                int pos = 0;
                for (int j = 0; j < n; j++) {
                    pos += mtx[i][j];
                }
                seq[n - pos - 1] = i + A;
            }
            determined(im, seq);
            return 0;
        }

        mtx[a][b] = 1;

    }
    cannot_determine();
    return 0;
}
