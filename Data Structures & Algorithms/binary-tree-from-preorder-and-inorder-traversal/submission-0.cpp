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
    unordered_map<int,int>ind;
    int ptr=0;
    TreeNode* fn(vector<int>pre,int l,int r){
        if(l>r) return nullptr;
        TreeNode* curr=new TreeNode(pre[ptr++]);
        curr->left=fn(pre,l,ind[curr->val]-1);
        curr->right=fn(pre,ind[curr->val]+1,r);
        return curr;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            ind[inorder[i]]=i;
        }
        return fn(preorder,0,ind.size()-1);
    }
};
