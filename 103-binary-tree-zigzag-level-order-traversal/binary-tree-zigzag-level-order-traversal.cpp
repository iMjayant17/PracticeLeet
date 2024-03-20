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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
         if(root==NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size()>0){
            int a = q.size();
            vector<int> ans;
            for(int i=0; i<a; i++){
                TreeNode* node = q.front();
                q.pop();
            
                ans.push_back(node->val);
                
               if(node->left) q.push(node->left);
               if(node->right) q.push(node->right);
            }
            res.push_back(ans);
        }
        // reverse(begin(res),end(res));
        for(int i = 0;i<res.size();i++){
            if(i&1){
                reverse(res[i].begin(),res[i].end());
            }
        }
        return res;
    }
};