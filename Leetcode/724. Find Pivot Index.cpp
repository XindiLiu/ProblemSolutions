class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.size() == 1)return 0;
        int r = accumulate(nums.begin() + 1, nums.end(), 0);
        int l = 0;
        if (l == r)return 0;
        for (int i = 1; i < nums.size(); i++) {
            l += nums[i - 1];
            r -= nums[i];
            if (l == r)return i;
        }
        return -1;
    }
};