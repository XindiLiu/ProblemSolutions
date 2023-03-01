/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* rt;
    int kk;
    bool findTarget(TreeNode* root, int k) {
        rt = root;
        kk = k;
        return trav(root);
    }
    bool trav(TreeNode* root) {
        if (kk - root->val != root->val && find(rt, kk - root->val)) {
            return true;
        }
        bool ret = false;
        if (root->left != nullptr) {
            ret = ret || trav(root->left);

        }
        if (ret)return true;
        if (root->right != nullptr) {
            ret = ret || trav(root->right);
        }
        return ret;
    }
    bool find(TreeNode* root, int k) {
        if (root->val == k) return true;
        bool ret = false;
        if (root->left != nullptr && root->val > k) ret = ret || find(root->left, k);
        if (ret)return true;
        if (root->right != nullptr && root->val < k) ret = ret || find(root->right, k);
        return ret;
    }

};