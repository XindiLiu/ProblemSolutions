class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> step(n, 0); // minimum numbers of jumps to the position.
        int x = 1; // maximum reached position + 1.
        for (int i = 0; i < n; ++i) {
            if (i > 0 && step[i] == 0) {
                return false;
            }
            // mark not reached positions that can be reached from i.
            for (; x <= min(i + nums[i], n - 1); ++x) {
                step[x] = step[i] + 1;
            }

        }
        return true;
    }
};