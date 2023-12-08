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
    string tree2str(TreeNode* root) {
        string ans="";
        solve(root,ans);
        return ans;

    }
    void solve(TreeNode* root,string &ans){
        if(root==NULL){
            return;
        }
            ans+=to_string(root->val);
            if(root->left){
                ans.push_back('(');
                solve(root->left,ans);
                ans.push_back(')');

                // int n = ans.length();
                // if(ans[n-1]==')' && ans[n-2]=='('){
                //     ans.pop_back();
                //     ans.pop_back();
                // }
                }

            if(root->right){
                if(root->left==NULL) ans+="()";
                ans.push_back('(');
                solve(root->right,ans);
                ans.push_back(')');

                // int n = ans.length();
                // if(ans[n-1]==')' && ans[n-2]=='('){
                //     ans.pop_back();
                //     ans.pop_back();
                // }
                }

        return;
    }
};