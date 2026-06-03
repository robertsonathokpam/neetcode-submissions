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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(!root){
            return res;
        }
        queue<TreeNode*>q;
        q.push(root);
        res.push_back({root->val});
        while(!q.empty()){
            int sz=q.size();
            vector<int>nodes;
            for(int i=0;i<sz;i++){
                auto curr=q.front();
                q.pop();
                if(curr->left){
                    q.push(curr->left);
                    nodes.push_back(curr->left->val);
                }
                if(curr->right){
                    q.push(curr->right);
                    nodes.push_back(curr->right->val);
                }
            }
            if(nodes.size()!=0){
               res.push_back(nodes);
            }
        }
        return res;
    }
};
