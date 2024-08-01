/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    int maxi;

    void solve(TreeNode* root, int cnt = 1) {
        if (root == NULL)
            return;

        if (cnt > maxi) {
            ans.push_back(root->val);
            maxi = max(maxi, cnt);
        }

        solve(root->right, cnt + 1);
        solve(root->left, cnt + 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        maxi = 0;
        solve(root);

        return ans;
    }
};