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
    int fn(TreeNode* root, int& res) {
        if (root == nullptr) return 0;
        int left = fn(root->left, res);
        int right = fn(root->right, res);
        res = max(res, root->val + max(0, left) + max(0, right));
        return root->val +  max(0,max(left,right));
    }
    int maxPathSum(TreeNode* root) {
        int res = -1e5;
        fn(root, res);
        return res;
    }
};
