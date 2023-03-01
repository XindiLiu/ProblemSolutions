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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth > 2) {
            if (root->left != nullptr)root->left = addOneRow(root->left, val, depth - 1);
            if (root->right != nullptr)root->right = addOneRow(root->right, val, depth - 1);
        }
        else if (depth == 2) {
            if (root->left != nullptr) {
                root->left = new TreeNode(val, root->left, nullptr);
            }
            else {
                root->left = new TreeNode(val);
            }
            if (root->right != nullptr) {
                root->right = new TreeNode(val, nullptr, root->right);
            }
            else {
                root->right = new TreeNode(val);
            }
        }
        else if (depth == 1) {
            root = new TreeNode(val, root, nullptr);
        }
        return root;

    }
};