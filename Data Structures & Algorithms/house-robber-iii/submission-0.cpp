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
    map<pair<TreeNode*,int>,int>dp;
    int fn(TreeNode* root,int curr){
        if(!root) return 0;
        if(dp.count({root,curr})) return dp[{root,curr}];
        int take=0;
        int notake=fn(root->right,0)+fn(root->left,0);
        if(curr==0){
            take=root->val+fn(root->right,1)+fn(root->left,1);
        }
        
        return dp[{root,curr}]=max(take,notake);
    }
    int rob(TreeNode* root) {
        return fn(root,0);   
    }
};