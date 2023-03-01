class Solution {
public:
    int ans = INT_MIN;
    int maxPathSum(TreeNode* root) {
        maxSum(root);
        return ans;
    }
    int maxSum(TreeNode* root) {
        if (root == nullptr) { return 0; }
        int lsum = max(maxSum(root->left), 0);
        int rsum = max(maxSum(root->right), 0);
        ans = max(ans, lsum + rsum + root->val);
        return max(lsum, rsum) + root->val;
    }
};