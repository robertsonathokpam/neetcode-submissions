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
    void count(TreeNode* root,vector<int>&arr){
        if(!root) return ;
        count(root->left,arr);
        arr.push_back(root->val);
        count(root->right,arr);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>arr;
        count(root,arr);
        return arr[k-1];
    }
};
