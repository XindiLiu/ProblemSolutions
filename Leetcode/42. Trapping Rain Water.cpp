typedef pair<int, int> pii;
typedef vector<int> vi;
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vi presum(n);
        vector<pii> maxafter(n); // first: the height, second: the position
        presum[0] = height[0];
        for (int i = 1; i < n; ++i) {
            presum[i] = presum[i - 1] + height[i];
        }
        maxafter[n - 1] = make_pair(0, n);
        for (int i = n - 2; i >= 0; --i) {
            if (height[i + 1] > maxafter[i + 1].first) {
                maxafter[i] = make_pair(height[i + 1], i + 1);
            }
            else
                maxafter[i] = maxafter[i + 1];
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (i < n - 1 && height[i + 1]>height[i]) {
                continue;
            }
            // find the first j: height[j] >= height[i], else find max of the remaining.
            int j;
            int jheight;
            if (height[i] >= maxafter[i].first) {
                j = maxafter[i].second;
                jheight = maxafter[i].first;
            }
            else {
                for (j = i + 1; j < n; ++j) {
                    if (height[j] > height[i]) {
                        jheight = height[j];
                        break;
                    }
                }
            }
            int waterlevel = min(height[i], jheight);
            ans += waterlevel * (j - i - 1) - (presum[j - 1] - presum[i]);
            i = j - 1;
        }
        return ans;
    }
};