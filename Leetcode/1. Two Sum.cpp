class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> index;
        for (int i = 0; i < nums.size(); i++) {
            auto it = index.find(target - nums[i]);
            if (it != index.end()) {
                return vector<int>({it->second,i});
            }
            index[nums[i]] = i;
        }
        return vector<int>();
    }
};