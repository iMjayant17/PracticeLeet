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

    int solve(TreeNode* root ,int h = 1){
        if(!root) return 0;
        int a = solve(root->left,h+1);
        int b = solve(root->right,h+1);
        if(abs(a-b)>1) ans = false;
        return 1 + max(a,b);
    }

    bool isBalanced(TreeNode* root) {
        solve(root);
        return ans;    
    }
};