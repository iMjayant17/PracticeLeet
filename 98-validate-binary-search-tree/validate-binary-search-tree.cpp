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
    bool ans = true;
    long long prev = -1e10 ;

    void solve(TreeNode* root){
        if(!root) return;

        solve(root->left);
        if(prev>=root->val) ans = false;
        prev = root->val;

        solve(root->right);
    }


    bool isValidBST(TreeNode* root) {
 solve(root);
 return ans;
    }
};