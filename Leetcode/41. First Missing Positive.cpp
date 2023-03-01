class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (!(nums[i] >= 1 && nums[i] <= n))nums[i] = 0;
        }
        while (i < n) {
            int j = i;
            int k = nums[j]; // save the value 
            if (k >= 1 && k <= n) {
                nums[j] = 0;
                // j = k - 1;
                while (k >= 1 && k <= n) {
                    j = k - 1; // position to jump
                    k = nums[j]; // save the value 
                    nums[j] = -1; // mark k as exist
                }
            }
            i++;
        }
        int ans = n + 1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != -1) {
                ans = i + 1;
                break;
            }
        }
        return ans;
    }
};