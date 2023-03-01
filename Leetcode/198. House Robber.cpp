class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        else if (n == 2) {
            return max(nums[0], nums[1]);
        }
        int ans = 0;
        int b1 = nums[1]; // b[j]: max of the i-1 first houses if take that house.
        int c1 = nums[0]; // c[j]: max of the i-1 first houses if not take that house.
        for (int i = 2; i < n; ++i) {
            int b2 = c1 + nums[i];
            int c2 = max(c1, b1);
            ans = max(ans, max(b2, c2));
            b1 = b2;
            c1 = c2;
        }
        return ans;
    }
};