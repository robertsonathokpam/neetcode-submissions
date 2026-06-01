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
    bool k=1;
    int dfs(TreeNode *root){
        if(root==nullptr){
            return 0;
        }
        int left=dfs(root->left);
        int right=dfs(root->right);
        if(abs(left-right)>1){
            k=false;
            return 0;
        }
        return 1+max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        k=1;
        dfs(root);
        if(k) return true;
        return false;
    }
};
