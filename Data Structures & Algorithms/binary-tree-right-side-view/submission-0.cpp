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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        if (!root) return res;
        deque<TreeNode*>q;
        q.push_front(root);
        while(!q.empty()){
            int sz=q.size();
            res.push_back(q.front()->val);
            
            for(int i=0;i<sz;i++){
                TreeNode* node=q.front();
                q.pop_front();
                if(node->right){
                    q.push_back(node->right);
                }
                if(node->left){
                    q.push_back(node->left);
                }
            }
            
        }
        return res;
    }
};
