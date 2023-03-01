class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<int> s;
        int mindiff = INT_MAX;
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            for (int j = 0; j < i - 1; ++j) {
                s.insert(nums[i - 1] + nums[j]);
            }
            auto it = s.lower_bound(target - nums[i]);
            if (it != s.end()) {
                int diff = target - nums[i] - *it;
                if (abs(diff) < mindiff) {
                    mindiff = abs(diff);
                    ans = target - diff;
                }
            }
            int diff = target - nums[i] - *(--it);
            if (abs(diff) < mindiff) {
                mindiff = abs(diff);
                ans = target - diff;
            }
            if (nums[0] + nums[1] + nums[i] >= target) {
                return ans;
            }
        }
        return ans;

    }
};