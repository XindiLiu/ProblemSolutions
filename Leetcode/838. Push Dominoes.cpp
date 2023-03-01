class Solution {
public:
    const char l = 'L';
    const char r = 'R';
    const char m = '.';
    inline void push(int beg, int end, char dir, string& s) {
        for (int i = beg; i <= end; ++i) {
            s[i] = dir;
        }
    }
    string pushDominoes(string dominoes) {
        string& s = dominoes;
        char prevdir = s[0];
        int prev = 0;

        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == l) {
                if (prevdir == l || prevdir == m) {
                    push(prev, i, l, s);
                }
                else if (prevdir == r) {
                    int rr, ll;
                    if ((i - prev) % 2 == 1) {
                        rr = (i + prev) / 2;
                        ll = rr + 1;
                    }
                    else {
                        rr = (i + prev) / 2 - 1;
                        ll = rr + 2;
                    }
                    push(prev, rr, r, s);
                    push(ll, i, l, s);
                }
                prev = i;
                prevdir = s[i];
            }
            else if (s[i] == r) {
                if (prevdir == r) {
                    push(prev, i, r, s);
                }

                prev = i;
                prevdir = s[i];
            }

        }
        if (prevdir == r) {
            push(prev, s.size() - 1, r, s);
        }
        return s;
    }
};