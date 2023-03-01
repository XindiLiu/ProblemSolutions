class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        auto cmp = [&] (int a, int b) { return temperatures[a] == temperatures[b] ? a > b : temperatures[a] < temperatures[b]; };
        set<int, decltype(cmp)> s(cmp);
        s.insert(0);
        for (int i = 1; i < n; ++i) {
            auto insert_pos = s.insert(i).first;
            auto it = s.begin();
            while (it != insert_pos) {
                ans[*it] = i - *it;
                it = s.erase(it); // return the element that follows after the removed element
            }
        }
        return ans;
    }
};