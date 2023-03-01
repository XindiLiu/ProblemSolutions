class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();
        int minv = INT_MAX, mind = INT_MAX;
        priority_queue<int, vector<int>, less<int>> q;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2) {
                nums[i] = nums[i] << 1;
            }
            minv = min(minv, nums[i]);
            q.push(nums[i]);
        }

        mind = q.top() - minv;
        while (!(q.top() % 2)) {
            int a = q.top() / 2;
            minv = min(minv, a);
            q.pop();
            q.push(a);
            mind = min(q.top() - minv, mind);
        }
        return mind;
    }
};