class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = neededTime.size();
        vector<int>& t = neededTime;
        string& c = colors;
        if (n == 1) {
            return 0;
        }
        int maxt = 0;
        int sumt = 0; // Time if remove last
        int ans = 0;
        int start = -1;
        for (int i = 1; i < n; ++i) {
            if (start == -1) {
                if (c[i - 1] == c[i]) {
                    start = i - 1;
                    sumt = t[i - 1] + t[i];
                    maxt = max(t[i - 1], t[i]);
                }
            }
            else {
                if (c[i - 1] == c[i]) {
                    sumt += t[i];
                    maxt = max(maxt, t[i]);
                }
                else {
                    ans += sumt - maxt;
                    start = -1;
                }
            }

        }
        if (start != -1) {
            ans += sumt - maxt;
        }
        return ans;

    }
};