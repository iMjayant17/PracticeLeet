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
 vector<int> ans;
 void dfs(TreeNode* A,int len = 1){
     if(A==NULL) return;
     if(len>ans.size()){
         ans.push_back(A->val);
     }
     dfs(A->right,len+1);
     dfs(A->left,len+1);
     
     
 }
    vector<int> rightSideView(TreeNode* root) {
        ans.clear();
    dfs(root);
    return ans;
    }
};